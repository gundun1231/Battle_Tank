// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"
class UTankBarrel;
UCLASS()
class BATTLE_TANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector HitLocation);

	UPROPERTY(EditAnywhere)
		float LaunchSpeed = 100000;//Launch Speed starting: 1000m/s
protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;  

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//method that can call from blueprints.
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);
	
};
