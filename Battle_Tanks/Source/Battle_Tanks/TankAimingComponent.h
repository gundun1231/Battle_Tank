// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"
class UTankBarrel;//forward declaration

//Holds barrels properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	UTankBarrel* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);



public:	
	//TODO Add SetTurret reference
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector HitLocation, float LaunchSpeed);
	//setter
	void SetBarrelReference(UTankBarrel *BarrelToSet);


	
};
