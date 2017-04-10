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
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
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
		//line trace along that look direction, and see what we hit.
		GetLookVectorHitLocation(LookDirection,HitLocation);
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
	
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	const FVector Start = PlayerCameraManager->GetCameraLocation();
	const FVector End = Start + (LookDirection*LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel
	(
		HitResult,
		Start,
		End,
		ECollisionChannel::ECC_Visibility
	))
	{ // if line trace hits a visible object, assign the HitLocation to the 
		HitLocation = HitResult.Location;
		return true;
	}
	//if line trace does not detect a visible object (skybox is not considered visible), assign hit location 0
	HitLocation = FVector(0);
	return false;
	
}
