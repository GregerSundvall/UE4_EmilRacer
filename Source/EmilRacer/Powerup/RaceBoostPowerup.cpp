
#include "RaceBoostPowerup.h"

#include "EmilRacer/Player/RaceCar.h"

void URaceBoostPowerup::Setup_Implementation()
{
	MoveComponent = GetOwner()->FindComponentByClass<URaceCarMovementComponent>();
}


void URaceBoostPowerup::OnPowerupActivated_Implementation()
{
	BoostTime = 2.f;

	MoveComponent->AddImpulse(GetOwner()->GetActorForwardVector() * 3000.f);
}

void URaceBoostPowerup::TickActive_Implementation(float DeltaTime)
{
	// Super::TickActive_Implementation(float DeltaTime);
	
	MoveComponent->AddForce(GetOwner()->GetActorForwardVector() * 2000.0f);
	BoostTime -= DeltaTime;
}

bool URaceBoostPowerup::ShouldDeactivate_Implementation()
{
	return Super::ShouldDeactivate_Implementation();
	
}
