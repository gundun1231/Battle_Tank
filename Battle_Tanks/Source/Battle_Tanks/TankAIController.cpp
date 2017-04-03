// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tanks.h"
#include "TankAIController.h"

ATank* ATankAIController::GetAIControlled() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::TargetPlayerController() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
}
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AI_Targetter = TargetPlayerController();
	if (!AI_Targetter)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s Not targetting a Tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller is targetting %s"), *(AI_Targetter->GetName()));
	}
}

