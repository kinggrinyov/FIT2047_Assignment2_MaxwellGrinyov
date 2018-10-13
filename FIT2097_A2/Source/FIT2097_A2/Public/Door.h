// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class FIT2097_A2_API ADoor : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	ADoor();
	
	void BeginPlay() override;
	void Tick(float DeltaTime);
	
	void OpenDoor();
	void UpdateDoor(float DeltaTime);
	void Interact();

	//Unique Identifier to the door, Used to link up the doors to unlock
	int DoorID; 

private:
	FVector m_targetRotation;

};
