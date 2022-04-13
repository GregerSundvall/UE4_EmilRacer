
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "EmilRacer/Powerup/RacePowerup.h"
#include "RacePlayerStatusWidget.generated.h"


UCLASS()
class EMILRACER_API URacePlayerStatusWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	UTextBlock* GetNameTextBlock();

	UFUNCTION(BlueprintImplementableEvent)
	UTextBlock* GetPowerupTextBlock();

	

	void SetPlayerName(const FString& Name);
	void SetEquippedPowerup(URacePowerup* Powerup);
	
};
