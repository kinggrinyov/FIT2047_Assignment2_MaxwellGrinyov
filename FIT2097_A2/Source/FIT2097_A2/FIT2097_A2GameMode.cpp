// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FIT2097_A2GameMode.h"
#include "FIT2097_A2Character.h"
#include "UObject/ConstructorHelpers.h"
#include "MainHUD.h"
#include "MainPlayerState.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

const int MAX_PLAYERS = 2;

AFIT2097_A2GameMode::AFIT2097_A2GameMode() : Super()
{
	//Set up default classes
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	HUDClass = AMainHUD::StaticClass();
	PlayerStateClass = AMainPlayerState::StaticClass();


	//Initiase variables
	m_playersSpawned = 0;
	//for (bool& du : DoorsUnlocked)
	//{
	//	du = false;
	//}
}

//bool AFIT2097_A2GameMode::IsDoorUnlocked(int index)
//{
//	return DoorsUnlocked[index];
//}
//
//void AFIT2097_A2GameMode::UnlockDoor(int index)
//{
//	DoorsUnlocked[index] = true;
//}
//
//void AFIT2097_A2GameMode::LockDoor(int index)
//{
//	DoorsUnlocked[index] = false;
//}

void AFIT2097_A2GameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, "Welcome Player " + FString::FromInt(m_playersSpawned) );
	}

	m_playersSpawned++;
}

AActor* AFIT2097_A2GameMode::ChoosePlayerStart_Implementation(AController* Player)
{
	//limit player joining
	if (m_playersSpawned > MAX_PLAYERS-1)
	{
		return nullptr;
	}


	//Super::ChoosePlayerStart_Implementation(Player);
	TArray<AActor*> playerstarts;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), playerstarts);

	//for (AActor* actor : playerstarts)
	//{
	//	APlayerStart* ps = Cast<APlayerStart>(actor);
	//	if (ps)
	//	{
	//		if (ps->PlayerStartTag == "Player1Start")
	//		{
	//			retVal = ps;
	//		}
	//	}
	//}
	return playerstarts[m_playersSpawned];
}

