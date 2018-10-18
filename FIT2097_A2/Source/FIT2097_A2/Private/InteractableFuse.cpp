// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableFuse.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "FIT2097_A2Character.h"

AInteractableFuse::AInteractableFuse()
	: Super()
{
	SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
}

void AInteractableFuse::Interact()
{
	GetStaticMeshComponent()->SetSimulatePhysics(false);
	GetStaticMeshComponent()->SetEnableGravity(false);
}

void AInteractableFuse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Role == ROLE_Authority)
	{
		if (m_owner)
		{
			SetActorLocation(FMath::Lerp(GetActorLocation(), m_owner->GetActorLocation(), 1.0f * DeltaTime));

			if (FVector::DistSquared(GetActorLocation(), m_owner->GetActorLocation()) <= 1500.0f)
			{
				if (Cast<AFIT2097_A2Character>(m_owner))
				{
					Cast<AFIT2097_A2Character>(m_owner)->CLIENT_SpawnExplosion(GetActorLocation());
					Cast<AFIT2097_A2Character>(m_owner)->ActivateExplosionPower();
				}

				Destroy();
			}

		}
	}
}
