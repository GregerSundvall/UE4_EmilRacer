// Fill out your copyright notice in the Description page of Project Settings.


#include "RacePowerupPickup.h"

#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Components/SphereComponent.h"
#include "EmilRacer/Player/RaceCar.h"

ARacePowerupPickup::ARacePowerupPickup()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(Root);
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ARacePowerupPickup::HandleOverlap);
	
}

void ARacePowerupPickup::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool bFromSweep, const FHitResult& SweepHit)
{
	int RandomIndex = FMath::RandRange(0, PowerupClasses.Num() -1);
	auto PowerupClass = PowerupClasses[RandomIndex];
	
	ARaceCar* Car = Cast<ARaceCar>(OtherActor);
	if (!Car->HasPowerup())
	{
		Car->EquipPowerup(NewObject<URacePowerup>(Car, PowerupClass));
		Destroy();
	}
	
	
	
}
