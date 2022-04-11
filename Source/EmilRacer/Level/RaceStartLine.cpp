

#include "RaceStartLine.h"

#include "EmilRacer/Game/RaceGameInstance.h"
#include "GameFramework/GameModeBase.h"
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
		PlayerController->Possess(Car);

		URaceGameInstance* GameInstance = URaceGameInstance::Get(this);
		GameInstance->Cars.Add(Car);
		
		SpawnTransform.AddToTranslation(GetActorRightVector() * 500.f);
	}
	
}

void ARaceStartLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

