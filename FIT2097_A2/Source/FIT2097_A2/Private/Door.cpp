// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"

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
	if (Role == ROLE_Authority)
	{
		m_targetRotation = FVector(GetActorRotation().Euler().X, 90, GetActorRotation().Euler().Z);
	}
}

void ADoor::UpdateDoor(float DeltaTime)
{
	if (Role == ROLE_Authority)
	{
		FVector lerpVec = FMath::Lerp(GetActorRotation().Euler(), m_targetRotation, 0.5f * DeltaTime);
		SetActorRelativeRotation(FRotator::MakeFromEuler(lerpVec));

		//Snap door to fixed rotation once it gets close enough to target
		if (FVector::DistSquared(GetActorRotation().Euler(), m_targetRotation) < 5.0f)
		{
			SetActorRelativeRotation(FRotator::MakeFromEuler(m_targetRotation));
		}
	}
}

void ADoor::Interact()
{
	OpenDoor();
}
