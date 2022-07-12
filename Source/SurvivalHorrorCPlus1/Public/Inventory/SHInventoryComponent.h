// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SHInventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SURVIVALHORRORCPLUS1_API USHInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USHInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inventory Size")
	int32 Columns;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inventory Size")
	int32 Rows;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inventory Size")
	int32 Size;

public:	
	UFUNCTION()
	int32 GetColumns() const { return Columns; }

	UFUNCTION()
	int32 GetRows() const { return Rows; }

	UFUNCTION()
	int32 GetSize() const { return Size; }

		
};
