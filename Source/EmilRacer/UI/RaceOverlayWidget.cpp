
#include "RaceOverlayWidget.h"

#include "Components/CanvasPanelSlot.h"

void URaceOverlayWidget::NativeConstruct()
{
	Super::NativeConstruct();
	StatusWidgets.SetNum(4);
	
}

void URaceOverlayWidget::AddPlayerStatus(int PlayerIndex)
{
	static FName SlotNames[] =
	{
		TEXT("Player0Slot"),
		TEXT("Player1Slot"),
		TEXT("Player2Slot"),
		TEXT("Player3Slot")
	};
	
	URacePlayerStatusWidget* PlayerStatus = NewObject<URacePlayerStatusWidget>(this, PlayerWidgetClass);
	StatusWidgets[PlayerIndex] = PlayerStatus;
	
	// PlayerStatus->AddToViewport();
	
	// UCanvasPanelSlot* CanvasPanelSlot = GetMainCanvas()->AddChildToCanvas(PlayerStatus);
	// CanvasPanelSlot->SetPosition(FVector2D(80.f, 80.f));
	// CanvasPanelSlot->SetAutoSize(true);
	// SetContentForSlot((TEXT("Player0SLot")), PlayerStatus);
	SetContentForSlot(SlotNames[PlayerIndex], PlayerStatus);
	
}
