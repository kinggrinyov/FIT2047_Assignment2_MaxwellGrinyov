// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableKey.h"
#include "Engine.h"
#include "FIT2097_A2GameMode.h"

void AInteractableKey::Interact()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "INTERACTED!!!");
	}

	if (GetWorld())
	{
		if (GetWorld()->GetAuthGameMode())
		{
			AFIT2097_A2GameMode* gameMode = Cast<AFIT2097_A2GameMode>(GetWorld()->GetAuthGameMode());
			if (gameMode)
			{
				gameMode->DoorsUnlocked[0] = true;
			}
		}
	}
}
