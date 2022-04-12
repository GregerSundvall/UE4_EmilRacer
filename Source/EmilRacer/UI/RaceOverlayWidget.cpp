
#include "RaceOverlayWidget.h"

void URaceOverlayWidget::NativeConstruct()
{
	Super::NativeConstruct();
	AddPlayerStatus(0);

	UE_LOG(LogTemp, Warning, TEXT("URaceOverlayWidget::NativeConstruct"))
}

void URaceOverlayWidget::AddPlayerStatus(int PlayerIndex)
{
	UUserWidget* PlayerStatus = NewObject<UUserWidget>(this, PlayerWidgetClass);
	PlayerStatus->AddToViewport();
	
}
