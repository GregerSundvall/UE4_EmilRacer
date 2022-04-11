

#include "RacePoopaShell.h"

#include "EmilRacer/Player/RaceCar.h"


ARacePoopaShell::ARacePoopaShell()
{
	PrimaryActorTick.bCanEverTick = true;
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	RootComponent = Collision;
	
}

void ARacePoopaShell::BeginPlay()
{
	Super::BeginPlay();

	ShellVelocity = GetActorForwardVector() * 3000.f;
}

void ARacePoopaShell::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FHitResult Hit;
	AddActorWorldOffset(ShellVelocity * DeltaSeconds, true, &Hit);
	if (Hit.bBlockingHit)
	{
		if (Hit.Actor->IsA<ARaceCar>())
		{
			Hit.Actor->Destroy();
			Destroy();
			return;
		}
		if (Hit.bStartPenetrating)
		{
			AddActorWorldOffset(Hit.Normal * Hit.PenetrationDepth + 0.01f);
		}
		else
		{
			ShellVelocity = ShellVelocity.MirrorByVector(Hit.Normal);
			
		}
	}
}
