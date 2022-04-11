
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "RaceGameMode.generated.h"

UCLASS()
class EMILRACER_API ARaceGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	ARaceGameMode();

	void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Widgets)
	TSubclassOf<UUserWidget> OverlayWidgetClass;

	
};
