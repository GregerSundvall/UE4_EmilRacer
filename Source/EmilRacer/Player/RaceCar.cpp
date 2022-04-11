// Fill out your copyright notice in the Description page of Project Settings.


#include "RaceCar.h"
#include "Components/BoxComponent.h"
#include "EmilRacer/Game/RaceGameInstance.h"
#include "EmilRacer/Powerup/RacePowerup.h"

ARaceCar::ARaceCar()
{
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	BoxCollision->SetCollisionProfileName(TEXT("BlockAll"));
	BoxCollision->SetCollisionResponseToAllChannels(ECR_Block);
	RootComponent = BoxCollision;

	MoveComponent = CreateDefaultSubobject<URaceCarMovementComponent>(TEXT("Movement Component"));
	
}

void ARaceCar::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (Powerup != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(
			INDEX_NONE,
			0.0f,
			FColor::Emerald,
			Powerup->GetClass()->GetName(),
			true,
			FVector2D(4.f)
			);

		if (bPowerupActivated)
		{
			Powerup->TickActive(DeltaSeconds);
			if (Powerup->ShouldDeactivate())
			{
				bPowerupActivated = false;
				Powerup = nullptr;
			}
		}
	}
}


void ARaceCar::BeginPlay()
{
	Super::BeginPlay();
}

void ARaceCar::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	URaceGameInstance* GameInstance = URaceGameInstance::Get(this);
	GameInstance->Cars.Remove(this);
	
}

void ARaceCar::SetupPlayerInputComponent(UInputComponent* InputComp)
{
	Super::SetupPlayerInputComponent(InputComp);

	InputComp->BindAxis(TEXT("Acceleration"), this, &ARaceCar::HandleAccelerationInput);
	InputComp->BindAxis(TEXT("TurnRight"), this, &ARaceCar::HandleTurnRightInput);
	InputComp->BindAction(TEXT("ActivatePowerup"), IE_Pressed, this, &ARaceCar::HandleActivatePowerup);
}

void ARaceCar::HandleActivatePowerup()
{
	if (Powerup != nullptr && !bPowerupActivated)
	{
		Powerup->OnPowerupActivated();
		bPowerupActivated = true;
	}
}

void ARaceCar::HandleAccelerationInput(float Value)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.0f, FColor::Magenta, FString::Printf(
		TEXT("Accelerate: %f"), Value));

	MoveComponent->DriveForwardInput = Value;
}

void ARaceCar::HandleTurnRightInput(float Value)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.0f, FColor::Magenta, FString::Printf(
		TEXT("Turn right: %f"), Value));

	MoveComponent->DriveSteerInput = Value;
}

void ARaceCar::EquipPowerup(URacePowerup* NewPowerup)
{
	Powerup = NewPowerup;
	Powerup->Setup();
}

