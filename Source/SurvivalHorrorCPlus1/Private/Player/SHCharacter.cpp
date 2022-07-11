// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/SHCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASHCharacter::ASHCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
	

}

// Called when the game starts or when spawned
void ASHCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASHCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASHCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASHCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASHCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ASHCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &ASHCharacter::AddControllerYawInput);

}

void ASHCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void ASHCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

float ASHCharacter::MoveDirection() const
{
	FVector VelocityNormal = GetVelocity().GetSafeNormal();
	float Angle = FMath::Acos(FVector::DotProduct(GetActorForwardVector(), VelocityNormal));
	FVector SignAngle = FVector::CrossProduct(GetActorForwardVector(), VelocityNormal);
	float DegreesAngle = FMath::RadiansToDegrees(Angle) * FMath::Sign(SignAngle.Z);
	return DegreesAngle;
}



