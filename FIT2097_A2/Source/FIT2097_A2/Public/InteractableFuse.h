// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "Runtime/Engine/Classes/Sound/SoundCue.h"
#include "InteractableFuse.generated.h"

/**
 * 
 */
UCLASS()
class FIT2097_A2_API AInteractableFuse : public AInteractableActor
{
	GENERATED_BODY()

public:
		AInteractableFuse();

		void Interact();
		void SetOwner(AActor* owner) { m_owner = owner; }

		void Tick(float DeltaTime) override;

private:
	AActor* m_owner;
	
};
