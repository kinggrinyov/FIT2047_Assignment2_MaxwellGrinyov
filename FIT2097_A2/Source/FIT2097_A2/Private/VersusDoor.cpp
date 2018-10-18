// Fill out your copyright notice in the Description page of Project Settings.

#include "VersusDoor.h"

void AVersusDoor::BeginPlay()
{
	m_startingPosition = GetActorLocation();

	IsMoved = FMath::RandRange(0, 10) > 5;
	MoveDoor();
}

void AVersusDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVersusDoor::MoveDoor()
{
	const FVector offsetPos = FVector(0, 880, 0);
	if (IsMoved)
	{
		SetActorLocation(m_startingPosition + offsetPos);
	}
	else
	{
		SetActorLocation(m_startingPosition);
	}
}
