// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
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

	//Primary draw call for the HUD
	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

	void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(EditAnywhere, Category = "Health")
		TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Health")
		class UUserWidget* CurrentWidget;
};
