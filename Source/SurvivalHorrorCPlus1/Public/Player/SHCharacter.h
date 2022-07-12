// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SHCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USHInventoryComponent;
class ASHPlayerHUD;

UCLASS()
class SURVIVALHORRORCPLUS1_API ASHCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASHCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;
	
	UFUNCTION(BlueprintCallable)
	float MoveDirection() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USHInventoryComponent* InventoryComponent;

	UPROPERTY(VisibleAnywhere)
	ASHPlayerHUD* PlayerHUD;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void OpenCloseInventory();

};
