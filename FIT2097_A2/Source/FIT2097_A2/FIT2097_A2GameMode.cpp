// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FIT2097_A2GameMode.h"
#include "FIT2097_A2Character.h"
#include "UObject/ConstructorHelpers.h"

AFIT2097_A2GameMode::AFIT2097_A2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	//Initiase variables
	for (bool& du : DoorsUnlocked)
	{
		du = false;
	}
}
