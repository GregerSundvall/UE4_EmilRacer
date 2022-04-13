

#include "RaceGameMode.h"
#include "Blueprint/UserWidget.h"


ARaceGameMode::ARaceGameMode()
{
	DefaultPawnClass = nullptr;
}



ARaceGameMode* ARaceGameMode::Get(UObject* WorldContext)
{
	return WorldContext->GetWorld()->GetAuthGameMode<ARaceGameMode>();
}

void ARaceGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void ARaceGameMode::StartMatch()
{
	OverlayWidget = NewObject<URaceOverlayWidget>(this, OverlayWidgetClass);
	OverlayWidget->AddToViewport();
	
	Super::StartMatch();

}


