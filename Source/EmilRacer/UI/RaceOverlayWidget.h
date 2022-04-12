
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RaceOverlayWidget.generated.h"


UCLASS()
class EMILRACER_API URaceOverlayWidget : public UUserWidget
{
	GENERATED_BODY()
	void NativeConstruct() override;
	
	void AddPlayerStatus(int PlayerIndex);

	UPROPERTY(EditAnywhere, Category = RaceOverlay)
	TSubclassOf<UUserWidget> PlayerWidgetClass;
	
	
};
