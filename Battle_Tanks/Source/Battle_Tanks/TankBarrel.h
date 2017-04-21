// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent),hidecategories = ("Collision"))
class BATTLE_TANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
		//-1 is a max downward speed, and +1 is a max up movement
		void Elevate(float RelativeSpeed);
private:
		UPROPERTY(EditAnywhere, Category= Setup)
		float MaxDegreesPerSecond = 20;//sensible default	

		UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 40;//sensible default	

		UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = 0;//sensible default	



};
