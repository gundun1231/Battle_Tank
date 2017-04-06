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
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	ATank* GetControlledTank() const;


	//move the barrel so that a shot would hit where the crosshair intersects with the world
	void AimAtCrossHair();

	//return an out paramter, true if landscape is hit.
	bool GetSightRayHitLocation(FVector& HitResult) const;//does it need to be const?

	bool GetLookDirection(FVector2D ScreenLocation, FVector LookDirection) const;

	UPROPERTY(EditAnywhere)
	float CrossHairLocationX = 0.5;
	
	UPROPERTY(EditAnywhere)
	float CrossHairLocationY = 0.33333;


};