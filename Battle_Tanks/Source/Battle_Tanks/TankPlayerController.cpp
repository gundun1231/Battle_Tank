#include "Battle_Tanks.h"
#include "TankPlayerController.h"




ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possessing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controller possessing %s"), *(ControlledTank->GetName()));
	}
}
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtCrossHair();

}

void ATankPlayerController::AimAtCrossHair()
{
	if (!GetControlledTank()){return;}

	FVector HitLocation; // out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	
	FVector2D ScreenLocation = FVector2D ((ViewportSizeX*CrossHairLocationX), (ViewportSizeY*CrossHairLocationY));
	//deproject screen position of the crosshair to a world direction 
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))

	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());

	}
	//line trace along that look direction, and see what we hit.
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector LookDirection) const
{
	FVector CameraWorldLocation;
	DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}
