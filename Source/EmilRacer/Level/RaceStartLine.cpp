

#include "RaceStartLine.h"
#include "EmilRacer/Game/RaceGameInstance.h"
#include "EmilRacer/Game/RaceGameMode.h"
#include "Kismet/GameplayStatics.h"


ARaceStartLine::ARaceStartLine()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
	
}

void ARaceStartLine::BeginPlay()
{
	Super::BeginPlay();

	FTransform SpawnTransform = GetActorTransform();
	
	
	for (int i = 0; i < NumberOfPlayers; ++i)
	{
		APlayerController* PlayerController = UGameplayStatics::GetPlayerControllerFromID(this, i);
		if (PlayerController == nullptr)
		{
			PlayerController = UGameplayStatics::CreatePlayer(this, i);
			
		}
		PlayerController->bAutoManageActiveCameraTarget = false;

		ARaceCar* Car = GetWorld()->SpawnActor<ARaceCar>(CarClass, SpawnTransform);
		Car->PlayerIndex = i;
		PlayerController->Possess(Car);

		URaceGameInstance* GameInstance = URaceGameInstance::Get(this);
		GameInstance->Cars.Add(Car);

		// Add Player status widget
		ARaceGameMode* GameMode = ARaceGameMode::Get(this);
		GameMode->OverlayWidget->AddPlayerStatus(i);
		GameMode->OverlayWidget->StatusWidgets[i]->SetPlayerName(FString::Printf(TEXT("Player %d"), i + 1));
		
		SpawnTransform.AddToTranslation(GetActorRightVector() * 500.f);
	}
	
}

void ARaceStartLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

