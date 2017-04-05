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
	UE_LOG(LogTemp, Warning, TEXT("Tick!"));

}

void ATankPlayerController::AimAtCrossHair()
{
	if (!GetControlledTank()){return;}
}