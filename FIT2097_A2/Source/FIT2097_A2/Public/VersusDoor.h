// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StaticReplicatingActor.h"
#include "VersusDoor.generated.h"

/**
 * 
 */
UCLASS()
class FIT2097_A2_API AVersusDoor : public AStaticReplicatingActor
{
	GENERATED_BODY()
	
	
public:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	void MoveDoor();
	bool IsMoved;

private:
	FVector m_startingPosition;
	
};
