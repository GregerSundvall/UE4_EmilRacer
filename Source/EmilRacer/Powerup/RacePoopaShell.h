
#pragma once

#include "CoreMinimal.h"
#include "RacePowerup.h"
#include "Components/SphereComponent.h"
#include "UObject/Object.h"
#include "RacePoopaShell.generated.h"


UCLASS()
class ARacePoopaShell : public AActor
{
	GENERATED_BODY()

public:
	ARacePoopaShell();

	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
	
	UPROPERTY(VisibleAnywhere)
	USphereComponent* Collision;

	FVector ShellVelocity;
};
