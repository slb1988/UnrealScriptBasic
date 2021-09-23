// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicPill.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
AMagicPill::AMagicPill()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PillEffect = 0.f;

	PillMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
	RootComponent = PillMesh;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));

	if (MeshAsset.Object != nullptr)
	{
		PillMesh->SetStaticMesh(MeshAsset.Object);
	}



}

// Called when the game starts or when spawned
void AMagicPill::BeginPlay()
{
	Super::BeginPlay();
	
	PillMesh->SetSimulatePhysics(true);
}

// Called every frame
void AMagicPill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

