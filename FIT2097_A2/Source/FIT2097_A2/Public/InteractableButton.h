// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "VersusDoor.h"
#include "InteractableButton.generated.h"

/**
 * 
 */
UCLASS()
class FIT2097_A2_API AInteractableButton : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	AInteractableButton();
	void Interact();

private:
	UPROPERTY(EditAnywhere, Category = "Door")
		AVersusDoor* m_versusDoor;
	
	
};
