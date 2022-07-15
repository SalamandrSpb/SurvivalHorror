// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/SHInventoryGridWidget.h"
#include "Components/Border.h"
#include "Components/CanvasPanelSlot.h"
#include "Inventory/SHInventoryComponent.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

bool USHInventoryGridWidget::Initialize()
{
	return Super::Initialize();
}

int32 USHInventoryGridWidget::NativePaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
	const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId,
	const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{

	FPaintContext Context(AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
	for (auto Element : Lines)
	{
		UWidgetBlueprintLibrary::DrawLine(Context, Element.Start, Element.End, FLinearColor::Gray, true, 1);
	}
	
	return Super::NativePaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle,
	                          bParentEnabled);

	
}

void USHInventoryGridWidget::InitialWidget(USHInventoryComponent* InventoryComp, float Size)
{
	TileSize = Size;
	InventoryComponent = InventoryComp;

	UCanvasPanelSlot* SlotGrid = Cast<UCanvasPanelSlot>(Grid->Slot);
	if (InventoryComponent && SlotGrid)
	{
		const int32 SizeX = InventoryComponent->GetColumns() * Size;
		const int32 SizeY = InventoryComponent->GetRows() * Size;

		const FVector2D SlotSize(SizeX, SizeY);

		SlotGrid->SetSize(SlotSize);
		CreateSegments();
		
	}
}

void USHInventoryGridWidget::CreateSegments()
{
	for (int32 Index = 0; Index <= InventoryComponent->GetColumns(); ++Index)
	{
		auto X = Index * TileSize;
		auto Y = InventoryComponent->GetRows() * TileSize;
		FLine Temp({{X, 0.0f}, {X, Y}});
		Lines.Add(Temp);
	}

	for (int32 Index = 0; Index <= InventoryComponent->GetRows(); ++Index)
	{
		auto Y = Index * TileSize;
		auto X = InventoryComponent->GetColumns() * TileSize;
		FLine Temp({{0.0f, Y}, {X, Y}});
		Lines.Add(Temp);
	}
}
