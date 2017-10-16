// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"


ATank* ATankAIController::GetControlledTank() const { return Cast<ATank>(GetPawn()); }

ATank* ATankAIController::GetPlayerTank() const { return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn()); }

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (ControlledTank)
	{
		if (PlayerTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("AIController controlling %s is viewing: %s"), *GetControlledTank()->GetName(), *GetPlayerTank()->GetName());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("AIController controlling %s cannot find player tank"), *GetControlledTank()->GetName());
			return;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AIController not controlling a tank"))
			return;
	}

	return;
}

