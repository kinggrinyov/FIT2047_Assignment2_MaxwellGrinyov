// Fill out your copyright notice in the Description page of Project Settings.

#include "MainHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "Blueprint/UserWidget.h"
#include "Engine.h"

AMainHUD::AMainHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> hudbpwidget(TEXT("/Game/Widgets/Widget_HUD"));
	
	HUDWidgetClass = hudbpwidget.Class;
}

void AMainHUD::DrawHUD()
{
	Super::DrawHUD();
}

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();

	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);

		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void AMainHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//DEBUG TEST 2FIX
	TSharedPtr<SWidget> swid = CurrentWidget->GetSlateWidgetFromName("ServerOrClient");
	
	{
		swid->SetRenderOpacity(swid->GetRenderOpacity() - DeltaTime);
	}
}

