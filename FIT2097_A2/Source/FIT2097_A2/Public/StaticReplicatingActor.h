// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "StaticReplicatingActor.generated.h"

/**
*
*/
UCLASS()
class FIT2097_A2_API AStaticReplicatingActor : public AStaticMeshActor
{
	GENERATED_BODY()


public:
	AStaticReplicatingActor();

	//network stuff
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


	UFUNCTION(BlueprintPure)
		bool IsActive();

	UFUNCTION(BlueprintCallable)
		void SetActive(bool newState);


protected:
	UPROPERTY(ReplicatedUsing = OnRep_IsActive)
		bool bIsActive;

	UFUNCTION()
		virtual void OnRep_IsActive();

};
