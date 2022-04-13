
#pragma once

#include "RaceCarMovementComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
// #include "CoreMinimal.h"
#include "RaceCar.generated.h"

class URacePowerup;
class UBoxComponent;
class URaceCarMovementComponent;

UCLASS()
class ARaceCar : public APawn
{
	GENERATED_BODY()
public:
	ARaceCar();
	void Tick(float DeltaSeconds) override;

	void BeginPlay() override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void HandleAccelerationInput(float Value);
	void HandleTurnRightInput(float Value);
	void SetupPlayerInputComponent(UInputComponent* InputComp) override;
	void HandleActivatePowerup();

	void EquipPowerup(URacePowerup* NewPowerup);
	bool HasPowerup() {return Powerup != nullptr;}

	UPROPERTY(BlueprintReadOnly)
	int PlayerIndex = 0;
	
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollision;

	UPROPERTY(VisibleAnywhere)
	URaceCarMovementComponent* MoveComponent;
	
	UPROPERTY()
	URacePowerup* Powerup;
	bool bPowerupActivated = false;
	
};
