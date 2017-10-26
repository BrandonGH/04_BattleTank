// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"


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
		UE_LOG(LogTemp, Error, TEXT("AIController not controlling a tank"));
		return;
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		// TODO move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready
	}
}


ATank* ATankAIController::GetControlledTank() const { return Cast<ATank>(GetPawn()); }

ATank* ATankAIController::GetPlayerTank() const { return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn()); }