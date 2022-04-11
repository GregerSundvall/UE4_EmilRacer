
#pragma once

#include "CoreMinimal.h"
#include "EmilRacer/Player/RaceCar.h"
#include "GameFramework/Actor.h"
#include "RaceStartLine.generated.h"

UCLASS()
class EMILRACER_API ARaceStartLine : public AActor
{
	GENERATED_BODY()

public:
	ARaceStartLine();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(EditDefaultsOnly, Category = Race)
	TSubclassOf<ARaceCar> CarClass;

	UPROPERTY(EditAnywhere, Category = Race)
	int NumberOfPlayers = 1;
	
};
