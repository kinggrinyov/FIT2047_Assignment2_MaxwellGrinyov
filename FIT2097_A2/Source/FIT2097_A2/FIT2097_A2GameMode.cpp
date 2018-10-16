// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FIT2097_A2GameMode.h"
#include "FIT2097_A2Character.h"
#include "UObject/ConstructorHelpers.h"
#include "MainHUD.h"

AFIT2097_A2GameMode::AFIT2097_A2GameMode()
{
	//Set up default classes
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	HUDClass = AMainHUD::StaticClass();

	//Initiase variables
	for (bool& du : DoorsUnlocked)
	{
		du = false;
	}
}

bool AFIT2097_A2GameMode::IsDoorUnlocked(int index)
{
	return DoorsUnlocked[index];
}

void AFIT2097_A2GameMode::UnlockDoor(int index)
{
	DoorsUnlocked[index] = true;
}

void AFIT2097_A2GameMode::LockDoor(int index)
{
	DoorsUnlocked[index] = false;
}
