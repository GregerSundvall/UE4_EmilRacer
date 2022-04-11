// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RacePoopaShell.h"
#include "RacePowerup.h"
#include "RacePoopaShellPowerup.generated.h"



UCLASS(Abstract)
class URacePoopaShellPowerup : public URacePowerup
{
	GENERATED_BODY()

public:
	void OnPowerupActivated_Implementation() override;

	UPROPERTY(EditDefaultsOnly, Category = Poopa)
	TSubclassOf<ARacePoopaShell> PoopaClass;

	UPROPERTY(EditDefaultsOnly, Category = Poopa)
	float SpawnOffset = 200.0f;
	
};
