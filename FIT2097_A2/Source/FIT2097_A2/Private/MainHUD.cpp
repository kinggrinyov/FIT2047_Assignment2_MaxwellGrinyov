// Fill out your copyright notice in the Description page of Project Settings.

#include "MainHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "Blueprint/UserWidget.h"
#include "Engine.h"

//#include "MainPlayerState.h"

AMainHUD::AMainHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> hudbpwidget(TEXT("/Game/Widgets/Widget_HUD"));
	HUDWidgetClass = hudbpwidget.Class;

	m_character = nullptr;
}

void AMainHUD::DrawHUD()
{
	Super::DrawHUD();
}

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();

	//get character!!
	m_character = Cast<AFIT2097_A2Character>(GetOwningPlayerController()->GetPawn());

	//Hook up and display widget on hud
	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);

		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}

	if (m_character)
	{
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
					if (m_character)
					{
						textBlock->SetText(m_character->GetRole());
					}
				}
			}
		}

	}



}

void AMainHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Key Image
	TSharedPtr<SWidget> keyimage = CurrentWidget->GetSlateWidgetFromName("KeyImage");
	if (keyimage->DoesSharedInstanceExist())
	{
		if (keyimage->GetType() == "SImage")
		{
			SImage* image = static_cast<SImage*>(keyimage.Get());
			if (image)
			{
				if (m_character)
				{
					image->SetRenderOpacity(m_character->HasKey() ? 1.0f : 0.0f);;
				}
			}
		}
	}

	//Fuse Image
	TSharedPtr<SWidget> widget = CurrentWidget->GetSlateWidgetFromName("FuseImage");
	if (widget->DoesSharedInstanceExist())
	{
		if (widget->GetType() == "SImage")
		{
			SImage* image = static_cast<SImage*>(widget.Get());
			if (image)
			{
				if (m_character)
				{
					image->SetRenderOpacity(m_character->HasFuse() ? 1.0f : 0.0f);
				}
			}
		}
	}

	//Health Bar Progressbar
	TSharedPtr<SWidget> pbwidget = CurrentWidget->GetSlateWidgetFromName("HealthBar");
	if (pbwidget->DoesSharedInstanceExist())
	{
		if (pbwidget->GetType() == "SProgressBar")
		{
			SProgressBar* progBar = static_cast<SProgressBar*>(pbwidget.Get());
			if (progBar)
			{
				if (m_character)
				{
					progBar->SetPercent(m_character->CurrentHealth / 100.0f);
				}
			}
		}
	}

	//MESSAGE TEXT
	TSharedPtr<SWidget> messageText = CurrentWidget->GetSlateWidgetFromName("MessageText");
	if (messageText->DoesSharedInstanceExist())
	{
		if (messageText->GetType() == "STextBlock")
		{
			STextBlock* textBlock = static_cast<STextBlock*>(messageText.Get());
			if (textBlock)
			{
				if (m_character)
				{
					if (m_character->CurrentMessage != textBlock->GetText().ToString())
					{
						textBlock->SetText(m_character->CurrentMessage);
						m_displayTimer = m_TIME_TO_DISPLAY;
					}

					if (m_displayTimer > 0.0f)
					{
						m_displayTimer -= DeltaTime;
					}
					else
					{
						const FString emptystr = "";
						textBlock->SetText(emptystr);
						m_character->CurrentMessage = emptystr;
					}
				}
			}
		}
	}

}

