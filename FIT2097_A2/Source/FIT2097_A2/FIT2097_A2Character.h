// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine.h"
#include "Door.h"
#include "InteractableKey.h"
#include "FIT2097_A2Character.generated.h"

UCLASS(config=Game)
class AFIT2097_A2Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AFIT2097_A2Character();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	void BeginPlay() override;
	void Tick(float DeltaTime);

	bool ShouldTickIfViewportsOnly() const
	{
		return true;
	}

	//MyStuff
	UPROPERTY(EditAnywhere, Category = "VFX")
		UParticleSystem* ExplosionEffect;

	UFUNCTION(NetMulticast, Reliable)
		void SERVER_SpawnExplosion();

	UFUNCTION(Server, Reliable, WithValidation)
		void CLIENT_SpawnExplosion();

	//Role Text
	UTextRenderComponent* RoleText;
	void SetupDisplayRole();
	void UpdateDisplayRole();

	//New methods
	void Jump();
	void HandleInteractable(AInteractableActor* interactable);

	UFUNCTION(Server, Reliable, WithValidation)
		void CLIENT_RequestOpenDoor(ADoor* doorToOpen);

	UFUNCTION(Server, Reliable, WithValidation)
		void CLIENT_PickupKey(AInteractableKey* keyToPickup);


	//Trace Code
	bool Trace(
		UWorld* World,
		TArray<AActor*>& ActorsToIgnore,
		const FVector& Start,
		const FVector& End,
		FHitResult& HitOut,
		ECollisionChannel CollisionChannel,
		bool ReturnPhysMat
	);
	void CallMyTrace();
	void ProcessTraceHit(FHitResult& HitOut);

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

