// Fill out your copyright notice in the Description page of Project Settings.

#include "StaticReplicatingActor.h"
#include "Net/UnrealNetwork.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"

AStaticReplicatingActor::AStaticReplicatingActor()
{
	bReplicates = true;

	PrimaryActorTick.bCanEverTick = false;

	//implement physics
	bReplicateMovement = true;
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetSimulatePhysics(true);
}

void AStaticReplicatingActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AStaticReplicatingActor, bIsActive);

}

bool AStaticReplicatingActor::IsActive()
{
	return bIsActive;
}

void AStaticReplicatingActor::SetActive(bool newState)
{
	if (Role == ROLE_Authority)
	{
		bIsActive = newState;
	}
}

void AStaticReplicatingActor::OnRep_IsActive()
{
	//stuff when active
}



