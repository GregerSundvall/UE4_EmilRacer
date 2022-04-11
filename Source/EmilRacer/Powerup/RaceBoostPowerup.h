
#pragma once

#include "CoreMinimal.h"
#include "RacePowerup.h"
#include "UObject/Object.h"
#include "RaceBoostPowerup.generated.h"

class URaceCarMovementComponent;

UCLASS()
class URaceBoostPowerup : public URacePowerup
{
	GENERATED_BODY()
	
public:
	void Setup_Implementation() override;
	void OnPowerupActivated_Implementation() override;
	void TickActive_Implementation(float DeltaTime) override;
	bool ShouldDeactivate_Implementation() override;

private:
	UPROPERTY()
	URaceCarMovementComponent* MoveComponent;

	float BoostTime;
};
