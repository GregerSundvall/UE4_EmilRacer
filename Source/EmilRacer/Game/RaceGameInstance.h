
#pragma once

#include "CoreMinimal.h"
#include "EmilRacer/Player/RaceCar.h"
#include "RaceGameInstance.generated.h"


UCLASS()
class EMILRACER_API URaceGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure,
		Category = "Race|GameInstance",
		Meta = (DisplayName = "Get Race Name Instance", WorldContext = WorldContext))
	static URaceGameInstance* Get(UObject* WorldContext);
		
	void Init() override;

	UPROPERTY(BlueprintReadOnly)
	TArray<ARaceCar*> Cars;
};
