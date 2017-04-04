// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"// must be the last include

/**
 * 
 */
UCLASS()
class BATTLE_TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	//move barrel so a shot would hit where the crosshair intersects with the world 
	void AimAtCrosshair();
private:
	//return an out parameter , true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
