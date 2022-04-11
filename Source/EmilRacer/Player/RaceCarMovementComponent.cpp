// Fill out your copyright notice in the Description page of Project Settings.


#include "RaceCarMovementComponent.h"

#include "PropertyCustomizationHelpers.h"

URaceCarMovementComponent::URaceCarMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void URaceCarMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	AActor* Owner = GetOwner();

	// Apply acceleration
	Velocity += Owner->GetActorForwardVector() * Acceleration * DriveForwardInput * DeltaTime;

	// Apply frivtion
	FVector RollVelocity = Velocity.ProjectOnTo(Owner->GetActorForwardVector());
	FVector GripVelocity = Velocity - RollVelocity;

	RollVelocity -= RollVelocity * RollFriction * DeltaTime;
	GripVelocity -= GripVelocity * GripFriction * DeltaTime;
	Velocity = RollVelocity + GripVelocity;

	// Apply movement
	float RemainingTime = DeltaTime;
	int Iterations = 0;
	
	while (RemainingTime > 0.0f && ++Iterations < 10)
	{
		FHitResult Hit;
		Owner->AddActorWorldOffset(Velocity * RemainingTime, true, &Hit);

		if (Hit.bBlockingHit == true)
		{
			if (Hit.bStartPenetrating)
			{
				Owner->AddActorWorldOffset(Hit.Normal * (Hit.PenetrationDepth + 0.5f));
			}
			else
			{
				Velocity = FVector::VectorPlaneProject(Velocity, Hit.Normal);
				RemainingTime -= RemainingTime * Hit.Time;
			}
		}
		else
		{
			break;
		}
	}

	
	float Speed = FVector::DotProduct(Velocity, Owner->GetActorForwardVector());
	Owner->AddActorWorldRotation(FRotator(0.0f, DriveSteerInput * TurnSpeed * Speed * DeltaTime, 0.0f));
	
}

void URaceCarMovementComponent::AddForce(const FVector& Force)
{
	Velocity += Force * GetWorld()->GetDeltaSeconds();
}

void URaceCarMovementComponent::AddImpulse(const FVector& Impulse)
{
	Velocity += Impulse;
}




