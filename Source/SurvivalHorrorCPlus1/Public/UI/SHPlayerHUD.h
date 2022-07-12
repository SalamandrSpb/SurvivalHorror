// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SHPlayerHUD.generated.h"


class USHInventoryComponent;
class USHInventoryWidget;
class USHInventoryGridWidget;
/**
 * 
 */
UCLASS()
class SURVIVALHORRORCPLUS1_API ASHPlayerHUD : public AHUD
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
	TSubclassOf<UUserWidget> InventoryWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
	TSubclassOf<UUserWidget> InventoryGridWidgetClass;

	virtual void BeginPlay() override;

public:
	void OpenCloseInventory(APlayerController* PlayerController, USHInventoryComponent* InventoryComponent);

private:
	UPROPERTY(VisibleAnywhere)
	USHInventoryWidget* InventoryWidget;

	UPROPERTY(VisibleAnywhere)
	USHInventoryGridWidget* InventoryGridWidget;
};
