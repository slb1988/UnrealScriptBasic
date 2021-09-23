// Fill out your copyright notice in the Description page of Project Settings.


#include "PillSpawner.h"
#include "MagicPill.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APillSpawner::APillSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawningVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningVolumeBox"));
	RootComponent = SpawningVolume;

	ItemToSpawn = AMagicPill::StaticClass();
}

// Called when the game starts or when spawned
void APillSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnPill();

}

// Called every frame
void APillSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector APillSpawner::GetRandomPointInVolume()
{
	FVector Origin = SpawningVolume->Bounds.Origin;
	FVector Extent = SpawningVolume->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(Origin, Extent);
}

void APillSpawner::SpawnPill()
{
	if (ItemToSpawn != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World) {
			FVector spawnLocation = GetRandomPointInVolume();
			FRotator spawnRotation;
			spawnRotation.Pitch = FMath::FRand() * 360.0f;
			spawnRotation.Roll = FMath::FRand() * 360.0f;
			spawnRotation.Yaw = FMath::FRand() * 360.0f;

			AMagicPill* spawnPill = World->SpawnActor<AMagicPill>(ItemToSpawn, spawnLocation, spawnRotation);

		}
	}
}

