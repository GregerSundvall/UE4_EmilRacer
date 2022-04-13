
#pragma once

#include "CoreMinimal.h"
#include "RacePlayerStatusWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "RaceOverlayWidget.generated.h"


UCLASS()
class EMILRACER_API URaceOverlayWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct() override;
	void AddPlayerStatus(int PlayerIndex);

	UFUNCTION(BlueprintImplementableEvent)
	UCanvasPanel* GetMainCanvas();

	UPROPERTY(EditAnywhere, Category = RaceOverlay)
	TSubclassOf<URacePlayerStatusWidget> PlayerWidgetClass;

	UPROPERTY()
	TArray<URacePlayerStatusWidget*> StatusWidgets;
	
	// UPROPERTY(Meta = (BindWidget))
	// UCanvasPanel* MainCanvas;
	
};
