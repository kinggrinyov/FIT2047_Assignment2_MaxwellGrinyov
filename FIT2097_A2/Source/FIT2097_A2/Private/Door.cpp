// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "FIT2097_A2GameMode.h"
#include "Engine.h"

ADoor::ADoor()
	: AInteractableActor(),
	m_targetRotation(-90,0,0),
	DoorID(0)
{
	GetStaticMeshComponent()->SetSimulatePhysics(false);
	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
}

void ADoor::BeginPlay()
{
	AActor::BeginPlay();
}

void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateDoor(DeltaTime);
}

void ADoor::OpenDoor()
{
	m_targetRotation = FVector(GetActorRotation().Euler().X, 90, GetActorRotation().Euler().Z);
}

void ADoor::UpdateDoor(float DeltaTime)
{
	if (Role == ROLE_Authority)
	{
		FVector lerpVec = FMath::Lerp(GetActorRotation().Euler(), m_targetRotation, 0.5f * DeltaTime);
		SetActorRelativeRotation(FRotator::MakeFromEuler(lerpVec));
	}
}

void ADoor::Interact()
{
	if (GetWorld())
	{
		if (GetWorld()->GetAuthGameMode())
		{
			AFIT2097_A2GameMode* gameMode = Cast<AFIT2097_A2GameMode>(GetWorld()->GetAuthGameMode());
			if (gameMode)
			{
				if (gameMode->DoorsUnlocked[DoorID])
				{
					OpenDoor();
				}
				else
				{
					if (GEngine)
					{
						GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Can't open door, Not Unlocked!");
					}
				}
			}
		}
	}
}
