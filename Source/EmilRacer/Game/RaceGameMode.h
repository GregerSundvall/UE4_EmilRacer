
#pragma once
#include "CoreMinimal.h"
#include "EmilRacer/UI/RaceOverlayWidget.h"
#include "GameFramework/GameMode.h"
#include "RaceGameMode.generated.h"

UCLASS()
class EMILRACER_API ARaceGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	ARaceGameMode();
	void StartMatch() override;

	UFUNCTION(BlueprintPure, Category = "Race|GameMode", Meta = (DisplayName = "Get Race GameMode", WorldContext="WorldCOntext"))
	static ARaceGameMode* Get(UObject* WorldContext);
	
	void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Widgets)
	TSubclassOf<URaceOverlayWidget> OverlayWidgetClass;

	UPROPERTY()
	URaceOverlayWidget* OverlayWidget;
};
