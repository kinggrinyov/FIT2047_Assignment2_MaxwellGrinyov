// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FIT2097_A2Character.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "Kismet/GameplayStatics.h"
#include "InteractableActor.h"
#include "FIT2097_A2GameMode.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "InteractableButton.h"


//////////////////////////////////////////////////////////////////////////
// AFIT2097_A2Character

AFIT2097_A2Character::AFIT2097_A2Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;

	HasExplosionPower = false;	
	CurrentMessage = "";

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AFIT2097_A2Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFIT2097_A2Character::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &AFIT2097_A2Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFIT2097_A2Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AFIT2097_A2Character::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFIT2097_A2Character::LookUpAtRate);

	//Trace calling
	PlayerInputComponent->BindAction("LeftClick", IE_Pressed, this, &AFIT2097_A2Character::CallMyTrace);
}

void AFIT2097_A2Character::BeginPlay()
{
	ACharacter::BeginPlay();

	if (RoleText == nullptr)
	{
		UActorComponent* comp = GetComponentByClass(UTextRenderComponent::StaticClass());
		if (comp)
		{
			RoleText = Cast<UTextRenderComponent>(comp);
			SetupDisplayRole();
		}
	}

	CurrentHealth = 100.0f;
}

void AFIT2097_A2Character::Jump()
{
	ACharacter::Jump();
}

void AFIT2097_A2Character::OnJumped_Implementation()
{
	ACharacter::OnJumped_Implementation();

	if (HasExplosionPower)
	{
		CLIENT_SpawnExplosion(GetActorLocation() + FVector(0, 0, -100));
	}
}

void AFIT2097_A2Character::HandleInteractable(AInteractableActor * interactable)
{
	//attempt to cast interactable as specific objects
	if (Cast<ADoor>(interactable))
	{
		CLIENT_RequestOpenDoor(Cast<ADoor>(interactable), HasKey(), HasFuse());

		if (HasKey() || HasFuse())
		{
			CurrentMessage = "Door Opened!";
		}
		else
		{
			CurrentMessage = "Can't open door, Not Unlocked!";
		}
	}
	else if (Cast<AInteractableKey>(interactable))
	{
		CLIENT_PickupKey(Cast<AInteractableKey>(interactable));
		m_hasKey = true;

		CurrentMessage = "Key Acquired!";
	}
	else if (Cast<AInteractableFuse>(interactable))
	{
		CLIENT_PickupFuse(Cast<AInteractableFuse>(interactable));
		m_hasFuse = true;

		CurrentMessage = "Absorbing Fuse!";
	}
	else if (Cast<AInteractableButton>(interactable))
	{
		CLIENT_ActivateButton(Cast<AInteractableButton>(interactable));
	}
}

void AFIT2097_A2Character::CLIENT_RequestOpenDoor_Implementation(ADoor* doorToOpen, const bool haskey, const bool hasfuse)
{
	if (GetWorld())
	{
		if (GetWorld()->GetAuthGameMode()) //This would only work on the server (Since gamemode is server only)
		{
			AFIT2097_A2GameMode* gameMode = Cast<AFIT2097_A2GameMode>(GetWorld()->GetAuthGameMode());
			if (gameMode)
			{
				if (doorToOpen)
				{
					bool canOpenDoor = false;
					switch (doorToOpen->DoorID)
					{
						case 0:
						{
							canOpenDoor = haskey;
							break;
						}

						case 1:
						{
							canOpenDoor = hasfuse;
							break;
						}
					}

					if(canOpenDoor)
					{
						doorToOpen->Interact();
					}
				}

			}
		}
	}
}

bool AFIT2097_A2Character::CLIENT_RequestOpenDoor_Validate(ADoor * doorToOpen, const bool haskey, const bool hasfuse)
{
	return (doorToOpen != nullptr);
}

void AFIT2097_A2Character::CLIENT_PickupKey_Implementation(AInteractableKey* keyToPickup)
{
	keyToPickup->Interact();
}

bool AFIT2097_A2Character::CLIENT_PickupKey_Validate(AInteractableKey* keyToPickup)
{
	return (keyToPickup != nullptr);
}

void AFIT2097_A2Character::CLIENT_PickupFuse_Implementation(AInteractableFuse* fuseToPickup)
{
	fuseToPickup->SetOwner(this);
	fuseToPickup->Interact();
}

bool AFIT2097_A2Character::CLIENT_PickupFuse_Validate(AInteractableFuse* fuseToPickup)
{
	return fuseToPickup != nullptr;
}

void AFIT2097_A2Character::CLIENT_ActivateButton_Implementation(AInteractableButton* button)
{
	button->Interact();
}

bool AFIT2097_A2Character::CLIENT_ActivateButton_Validate(AInteractableButton* button)
{
	return button != nullptr;
}

bool AFIT2097_A2Character::Trace(UWorld * World, TArray<AActor*>& ActorsToIgnore, const FVector & Start, const FVector & End, FHitResult & HitOut, ECollisionChannel CollisionChannel, bool ReturnPhysMat)
{
	// The World parameter refers to our game world (map/level) 
	// If there is no World, abort
	if (!World)
	{
		return false;
	}

	// Set up our TraceParams object
	FCollisionQueryParams TraceParams(FName(TEXT("My Trace")), true, ActorsToIgnore[0]);

	// Should we simple or complex collision?
	TraceParams.bTraceComplex = true;

	// We don't need Physics materials 
	TraceParams.bReturnPhysicalMaterial = ReturnPhysMat;

	// Add our ActorsToIgnore
	TraceParams.AddIgnoredActors(ActorsToIgnore);

	// When we're debugging it is really useful to see where our trace is in the world
	// We can use World->DebugDrawTraceTag to tell Unreal to draw debug lines for our trace
	// (remove these lines to remove the debug - or better create a debug switch!)
	const FName TraceTag("MyTraceTag");
	World->DebugDrawTraceTag = TraceTag;
	TraceParams.TraceTag = TraceTag;

	// Force clear the HitData which contains our results
	HitOut = FHitResult(ForceInit);

	// Perform our trace
	World->LineTraceSingleByChannel
	(
		HitOut,		//result
		Start,	//start
		End, //end
		CollisionChannel, //collision channel
		TraceParams
	);

	//Debug draw a trace line
	DrawDebugLine(World, HitOut.TraceStart, HitOut.TraceEnd, FColor::Orange, false, 1.0f, 0, 5.0f);

	// If we hit an actor, return true
	return (HitOut.GetActor() != NULL);
}

void AFIT2097_A2Character::CallMyTrace()
{
	// Get the location of the camera (where we are looking from) and the direction we are looking in
	UCameraComponent* camera = Cast<UCameraComponent>( GetComponentByClass(UCameraComponent::StaticClass()) );

	if (!camera)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "CAMERA NOT FOUND, CANT TRACE");
		}

		return;
	}

	const FVector Start = camera->GetComponentLocation();
	const FVector ForwardVector = camera->GetForwardVector();
	const float TRACE_DISTANCE = 556;

	// How for in front of our character do we want our trace to extend?
	// ForwardVector is a unit vector, so we multiply by the desired distance
	const FVector End = Start + ForwardVector * TRACE_DISTANCE;

	// Force clear the HitData which contains our results
	FHitResult HitData(ForceInit);

	// What Actors do we want our trace to Ignore?
	TArray<AActor*> ActorsToIgnore;

	//Ignore the player character - so you don't hit yourself!
	ActorsToIgnore.Add(this);

	// Call our Trace() function with the paramaters we have set up
	// If it Hits anything
	if (Trace(GetWorld(), ActorsToIgnore, Start, End, HitData, ECC_Visibility, false))
	{
		ProcessTraceHit(HitData);
	}

}

void AFIT2097_A2Character::ProcessTraceHit(FHitResult & HitOut)
{
	AActor* actorHit = HitOut.GetActor();

	// Process our HitData
	if (actorHit)
	{
		AInteractableActor* interactable = Cast<AInteractableActor>(actorHit);
		if (interactable)
		{
			HandleInteractable(interactable);
		}
	}
}

void AFIT2097_A2Character::ActivateExplosionPower()
{
	HasExplosionPower = true;
	JumpMaxCount = 2;
	CLIENT_SpawnExplosionAura();
	CurrentMessage = "You have gained the power of the fuse, Double Jump Activated!";
}


void AFIT2097_A2Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateDisplayRole();

	//Reduce health over time
	if (CurrentHealth > 0)
	{
		CurrentHealth -= DeltaTime;
	}
}

void AFIT2097_A2Character::SERVER_SpawnExplosion_Implementation(FVector explodeLocation)
{
	//Spawn Explosion Effect
	if (ExplosionEffect != nullptr)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, explodeLocation, GetActorRotation(), FVector::OneVector, false);
		if (ExplosionSFX)
		{
			UGameplayStatics::PlaySound2D(GetWorld(), ExplosionSFX);
		}
	}
}
void AFIT2097_A2Character::CLIENT_SpawnExplosion_Implementation(FVector explodeLocation)
{
	SERVER_SpawnExplosion(explodeLocation);
}
bool AFIT2097_A2Character::CLIENT_SpawnExplosion_Validate(FVector explodeLocation)
{
	return true;
}

void AFIT2097_A2Character::SERVER_SpawnExplosionAura_Implementation()
{
	//Spawn Explosion Effect
	if (ExplosionModeAura != nullptr)
	{
		UGameplayStatics::SpawnEmitterAttached(ExplosionModeAura,GetRootComponent(), NAME_None, FVector::ZeroVector, GetActorRotation(), EAttachLocation::SnapToTarget);
	}
}
void AFIT2097_A2Character::CLIENT_SpawnExplosionAura_Implementation()
{
	SERVER_SpawnExplosionAura();
}
bool AFIT2097_A2Character::CLIENT_SpawnExplosionAura_Validate()
{
	return true;
}

void AFIT2097_A2Character::SetupDisplayRole()
{
	FString val = "Missing";

	switch (Role)
	{
		case ROLE_None:
		{
			val = "No Role";
			break;
		}
		case ROLE_SimulatedProxy:
		{
			val = "Simulated Proxy";
			break;
		}
		case ROLE_AutonomousProxy:
		{
			val = "Autonomous Proxy";
			break;
		}
		case ROLE_Authority:
		{
			val = "Authority (Server)";
			break;
		}
	}

	if (RoleText)
	{
		FText ftext = FText::FromString(val);
		RoleText->SetText(val);
	}
}

void AFIT2097_A2Character::UpdateDisplayRole()
{
	if(RoleText)
	{
		RoleText->SetWorldRotation(FRotator::MakeFromEuler(FVector::ZeroVector));
	}	
}

FString AFIT2097_A2Character::GetRole()
{
	FString retVal = "MISSING ROLE";

	if (Role == ROLE_Authority)
	{
		retVal = "SERVER";
	}
	else
	{
		retVal = "CLIENT";
	}

	return retVal;
}



void AFIT2097_A2Character::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AFIT2097_A2Character::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AFIT2097_A2Character::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AFIT2097_A2Character::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
