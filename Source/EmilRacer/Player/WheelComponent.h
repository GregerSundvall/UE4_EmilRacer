// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WheelComponent.generated.h"

UCLASS(Meta = (BlueprintSpawnableComponent))
class EMILRACER_API UWheelComponent : public UObject
{
	GENERATED_BODY()

public:
	void SetAngle(float Angle);

	UPROPERTY()
	float Angle = 0;

	
	
};
