// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RaceCamera.generated.h"

class UCameraComponent;

UCLASS()
class ARaceCamera : public AActor
{
	GENERATED_BODY()

public:
	ARaceCamera();

	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Object to follow|Advanced")
	float FollowSpeed = 5.0f;
	
	// UPROPERTY(EditInstanceOnly, Category = "Object to follow")
	// AActor* ActorToFollow;

};
