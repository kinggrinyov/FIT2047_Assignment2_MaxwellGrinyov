// Fill out your copyright notice in the Description page of Project Settings.

#include "MainHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "Blueprint/UserWidget.h"
#include "Engine.h"
#include "FIT2097_A2Character.h"
//#include "MainPlayerState.h"

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

	//Hook up and display widget on hud
	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);

		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}

	AFIT2097_A2Character* myCharacter = Cast<AFIT2097_A2Character>(GetOwningPlayerController()->GetPawn());
	if (myCharacter)
	{
		////AGameStateBase* gs = GetWorld()->GetGameState();
		//AMainPlayerState* myPlayerState = Cast<AMainPlayerState>(myCharacter->PlayerState);
		//if (myPlayerState)
		//{
		//Setup Widget's slate widgets

		//SERVER OR CLIENT TEXT
		TSharedPtr<SWidget> serverOrClientText = CurrentWidget->GetSlateWidgetFromName("ServerOrClient");
		if (serverOrClientText->DoesSharedInstanceExist())
		{
			if (serverOrClientText->GetType() == "STextBlock")
			{
				STextBlock* textBlock = static_cast<STextBlock*>(serverOrClientText.Get());
				if (textBlock)
				{
					if (myCharacter)
					{
						textBlock->SetText(myCharacter->GetRole());
					}
				}
			}
		}


		//}
	}



}

void AMainHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

