﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// #include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RaceCarMovementComponent.generated.h"


UCLASS(Meta = (BlueprintSpawnableComponent))
class URaceCarMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	URaceCarMovementComponent();
	
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddForce(const FVector& Force);
	void AddImpulse(const FVector& Impulse);
	
    UPROPERTY(EditDefaultsOnly, Category = "Driving")
	float Acceleration = 2000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Driving")
	float TurnSpeed = 0.05f;

    UPROPERTY(EditDefaultsOnly, Category = "Driving")
	float RollFriction = 0.8f;

    UPROPERTY(EditDefaultsOnly, Category = "Driving")
	float GripFriction = 3.8f;

	FVector Velocity = FVector::ZeroVector;
	
	float DriveForwardInput = 0.0f;
	float DriveSteerInput = 0.0f;
};
