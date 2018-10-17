// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Classes/Components/TextRenderComponent.h"
#include "FIT2097_A2GameMode.generated.h"

UCLASS(minimalapi)
class AFIT2097_A2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFIT2097_A2GameMode();


	void PostLogin(APlayerController* NewPlayer) override;

	//Blueprint overriding
	AActor* ChoosePlayerStart_Implementation(AController* Player) override;

	//UFUNCTION(BlueprintPure)
	//	bool IsDoorUnlocked(int index);
	//
	//UFUNCTION(BlueprintCallable)
	//	void UnlockDoor(int index);
	//
	//UFUNCTION(BlueprintCallable)
	//	void LockDoor(int index);

private:
	int m_playersSpawned;
	//This stores the doors that are unlocked
	//bool DoorsUnlocked[4];
};



