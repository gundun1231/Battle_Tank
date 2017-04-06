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

	//move the barrel so that a shot would hit where the crosshair intersects with the world
	void AimAtCrossHair();

	//return an out paramter, true if landscape is hit.
	bool GetSightRayHitLocation(FVector& HitResult) const;//does it need to be const?

};