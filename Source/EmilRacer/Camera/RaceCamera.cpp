// Fill out your copyright notice in the Description page of Project Settings.


#include "RaceCamera.h"

#include "EngineUtils.h"
#include "Camera/CameraComponent.h"
#include "EmilRacer/Game/RaceGameInstance.h"


ARaceCamera::ARaceCamera()
{
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(Root);
	
}

void ARaceCamera::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* Controller = GetWorld()->GetFirstPlayerController();
	Controller->SetViewTarget(this);

	// for (TActorIterator<ARaceCar> It(GetWorld()); It; ++It) { }
}

void ARaceCamera::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// if (ActorToFollow == nullptr)
	// {
	// 	return;
	// }

	int NumCars = 0;
	FVector LocationSum = FVector::ZeroVector;
	URaceGameInstance* GameInstance = URaceGameInstance::Get(this);
	
	for (ARaceCar* Car : GameInstance->Cars)
	{
		LocationSum += Car->GetActorLocation();
		NumCars++;
	}

	if (NumCars == 0)
	{
		return;
	}
	
	FVector TargetLocation = LocationSum / NumCars;
	
	FVector Location = GetActorLocation();
	Location = FMath::Lerp(Location, TargetLocation, FollowSpeed * DeltaSeconds);
	SetActorLocation(Location);
}
