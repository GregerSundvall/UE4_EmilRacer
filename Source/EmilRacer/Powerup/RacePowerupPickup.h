// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RacePowerup.h"
#include "Components/SphereComponent.h"
#include "RacePowerupPickup.generated.h"

UCLASS()
class ARacePowerupPickup : public AActor
{
	GENERATED_BODY()

public:
	ARacePowerupPickup();

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool bFromSweep, const FHitResult& SweepHit);

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	
	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<URacePowerup>> PowerupClasses;
	
};
