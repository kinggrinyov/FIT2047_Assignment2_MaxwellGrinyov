// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FIT2097_A2Character.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class FIT2097_A2_API AMainHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMainHUD();

	//OVERRIDES
	//Primary draw call for the HUD
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;
	void Tick(float DeltaTime) override;

	
private:
	UPROPERTY(EditAnywhere, Category = "Health")
		TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Health")
		class UUserWidget* CurrentWidget;

	AFIT2097_A2Character* m_character;
	float m_displayTimer;
	const float m_TIME_TO_DISPLAY = 5.0f;
};
