// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableButton.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"


AInteractableButton::AInteractableButton()
	: Super()
{
	GetStaticMeshComponent()->SetSimulatePhysics(false);
	GetStaticMeshComponent()->SetEnableGravity(false);
}

void AInteractableButton::Interact()
{
	if (m_versusDoor)
	{
		m_versusDoor->IsMoved = !m_versusDoor->IsMoved;
		m_versusDoor->MoveDoor();
	}
}

