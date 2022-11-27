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

bool AProceduralSpawner::CheckIfWallShouldBeGenerated(int32 IndexX, int32 IndexY)
{
	if (IndexX == 0 || IndexX == 9 || IndexY == 0 || IndexY == 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Called every frame
void AProceduralSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FTransform AProceduralSpawner::MakeTransform(int32 IndexX, int32 IndexY)
{
	// Shifts location
	float ShiftLocation = (LevelGridSize * TileSize) / 2;

	// Gets placement of tile
	float XTile = IndexX * TileSize;
	float YTile = IndexY * TileSize;

	// Calculates the tile location
	float LocationX = XTile - ShiftLocation;
	float LocationY = YTile - ShiftLocation;

	// Randomizes the rotation of the tile to add an interesting effect
	float RandomZRotation = FMath::RandRange(0, 4) * 90;

	FVector Location = FVector(LocationX, LocationY, 0);
	FRotator Rotation = FRotator(0,RandomZRotation, 0);

	FTransform Output{Rotation, Location, FVector(1,1,1)};
	return Output;
}

