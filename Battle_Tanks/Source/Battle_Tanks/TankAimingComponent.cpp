// Fill out your copyright notice in the Description page of Project Settings.

#include "Battle_Tanks.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}




void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,//where we want the porjectile to end up
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace//do not line trace
	);
		//calculate the outlaunchvelocity
		if (bHaveAimSolution)
	{

		//UE_LOG(LogTemp, Warning, TEXT("AimDirection : %s"), *AimDirection.ToString());
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);


	}//if no solution found do nothing
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//Work out difference between current barrel rotation, and aim direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();//receive the roll pitch and yaw from the Barrel
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *DeltaRotator.ToString());

	Barrel->Elevate(5.f);
}