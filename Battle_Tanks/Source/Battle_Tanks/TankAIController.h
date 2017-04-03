// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private:	
	ATank* GetAIControlled() const;
	ATank* TargetPlayerController() const;
public:
	virtual void BeginPlay() override;
	
};
