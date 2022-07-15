// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SHInventoryGridWidget.generated.h"


class USHInventoryComponent;
class UBorder;
/**
 * 
 */

USTRUCT()
struct FLine
{
	GENERATED_BODY()
	FVector2D Start;
	FVector2D End;
};


UCLASS()
class SURVIVALHORRORCPLUS1_API USHInventoryGridWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize() override;

	virtual int32 NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect,
		FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

public:

	UFUNCTION()
	void InitialWidget(USHInventoryComponent* InventoryComp, float Size);

private:
	UPROPERTY(VisibleAnywhere)
	USHInventoryComponent* InventoryComponent;
	float TileSize;

	void CreateSegments();
	TArray<FLine> Lines;


protected:
	UPROPERTY(meta = (BindWidget))
	UBorder* Grid;
};
