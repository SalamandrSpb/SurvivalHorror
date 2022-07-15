// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/SHInventoryWidget.h"

#include "Inventory/SHInventoryComponent.h"
#include "Inventory/SHInventoryGridWidget.h"

void USHInventoryWidget::InitialInventoryWidget(USHInventoryComponent* InventoryComponent)
{
	InventoryGridWidget->InitialWidget(InventoryComponent, InventoryComponent->GetSize());
}
