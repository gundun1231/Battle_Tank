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
	void AimAtCrossHair();


};