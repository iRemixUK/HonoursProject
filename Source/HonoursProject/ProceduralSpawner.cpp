// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralSpawner.h"

// Sets default values
AProceduralSpawner::AProceduralSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LevelGridSize = 9;
	TileSize = 1000;
}

// Called when the game starts or when spawned
void AProceduralSpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProceduralSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FTransform AProceduralSpawner::MakeTransform(int32 IndexX, int32 IndexY)
{
	float Area = (LevelGridSize * TileSize) / 2;

	float XTile = IndexX * TileSize;
	float YTile = IndexY * TileSize;

	float LocationX = XTile - Area;
	float LocationY = YTile - Area;

	float RandomZRotation = FMath::RandRange(0, 4) * 90;

	FVector Location = FVector(LocationX, LocationY, 0);
	FRotator Rotation = FRotator(0,RandomZRotation, 0);

	FTransform Output{Rotation, Location, FVector(1,1,1)};
	return Output;
}

