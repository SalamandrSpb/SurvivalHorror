// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SHPlayerHUD.h"
#include "Inventory/SHInventoryComponent.h"
#include "Inventory/SHInventoryGridWidget.h"
#include "Inventory/SHInventoryWidget.h"
#include "Blueprint/UserWidget.h"

void ASHPlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	InventoryWidget = CreateWidget<USHInventoryWidget>(GetWorld(), InventoryWidgetClass);
	InventoryGridWidget = CreateWidget<USHInventoryGridWidget>(GetWorld(), InventoryGridWidgetClass);
}

void ASHPlayerHUD::OpenCloseInventory(APlayerController* PlayerController, USHInventoryComponent* InventoryComponent)
{
	if (InventoryWidget)
	{
		if (!InventoryWidget->IsInViewport())
		{
			InventoryWidget->AddToViewport();
			InventoryWidget->InitialInventoryWidget(InventoryComponent);
			PlayerController->SetInputMode(FInputModeGameAndUI());
			PlayerController->SetShowMouseCursor(true);
		}
		else
		{
			InventoryWidget->RemoveFromParent();
			PlayerController->SetInputMode(FInputModeGameOnly());
			PlayerController->SetShowMouseCursor(false);
		}
	}
}
