// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SHInventoryWidget.generated.h"


class USHInventoryComponent;
class USHInventoryGridWidget;
/**
 * 
 */
UCLASS()
class SURVIVALHORRORCPLUS1_API USHInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void InitialInventoryWidget(USHInventoryComponent* InventoryComponent);

protected:
	UPROPERTY(meta = (BindWidget))
	USHInventoryGridWidget* InventoryGridWidget;
	
};
