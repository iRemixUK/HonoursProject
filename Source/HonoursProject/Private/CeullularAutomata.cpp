// Fill out your copyright notice in the Description page of Project Settings.

#include "CeullularAutomata.h"

ACeullularAutomata::ACeullularAutomata()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialise grid size
	gridWidth = 30;
	gridHeight = 30;

	// Initialise number of iterations
	numIterations = 4;

	// Initialise thresholds
	threshold = 45.f;
	wallThreshold = 4;

	// Size of each tile
	TileSize = 400;
}

// Called when the game starts or when spawned
void ACeullularAutomata::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACeullularAutomata::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACeullularAutomata::GenerateLevel()
{
	// Generate level
	InitializeGrid();
	GenerateWalls();
}

TArray<bool> ACeullularAutomata::GetGrid() const
{
	return Grid;
}

void ACeullularAutomata::GetGridCoordinates(int32 Index, int32& X, int32& Y)
{
	// Calculate the x and y coordinates of the cell based on its index
	X = Index % gridWidth;
	Y = Index / gridWidth;

	// Check if coordinates are within the grid
	if (X >= 0 && X < gridWidth && Y >= 0 && Y < gridHeight)
	{
		return;
	}
	else
	{
		// Error check
		X = -1;
		Y = -1;
	}
}

FTransform ACeullularAutomata::MakeTransformFromIndex(int32 IndexX, int32 IndexY)
{
	// Shifts location
	float ShiftLocation = TileSize / 2;

	// Gets placement of tile
	float XTile = IndexX * TileSize;
	float YTile = IndexY * TileSize;

	// Calculates the tile location
	float LocationX = XTile - ShiftLocation;
	float LocationY = YTile - ShiftLocation;

	FVector Location = FVector(LocationX, LocationY, 0);
	FRotator Rotation = FRotator(0,0, 0);

	FTransform Output{Rotation, Location, FVector(1,1,1)};
	return Output;
}

void ACeullularAutomata::InitializeGrid()
{
	// Initialize grid and randomly set the values of the grid
	Grid.Empty(gridWidth * gridHeight);
	for (int32 i = 0; i < gridWidth * gridHeight; i++)
	{
		Grid.Add(FMath::RandRange(1.0f, 100.0f) < threshold);
	}
}

bool ACeullularAutomata::GetGridValue(int32 X, int32 Y) const
{
	// Returns grid value
	return Grid[X + Y * gridWidth];
}

void ACeullularAutomata::SetGridValue(int32 X, int32 Y, bool Value)
{
	// Sets grid value
	Grid[X + Y * gridWidth] = Value;
}

void ACeullularAutomata::GenerateWalls()
{
	// For loop that will iterate based on the number of the iterations the user would like
	for (int32 i = 0; i < numIterations; i++)
	{
		// Temporary grid that will store the new state of the grid
		TArray<bool> tempGrid;
		tempGrid.SetNumUninitialized(gridWidth * gridHeight);

		// Iterate over the x direction
		for (int32 j = 0; j < gridWidth; j++)
		{
			// Iterate over the y direction
			for (int32 k = 0; k < gridHeight; k++)
			{
				// Stores the number of neighbours that are walls
				int32 neighbourWallCount = 0;

				// These nested for loops will iterate over the 8 neighbouring cells to check whether a wall has been found
				for (int32 x = -1; x <= 1; x++)
				{
					for (int32 y = -1; y <= 1; y++)
					{
						// 0,0 is the current cell so don't include this and skip to the next iteration
						if (x == 0 && y == 0)
						{
							continue;
						}

						int32 CheckX = j + x;
						int32 CheckY = k + y;

						// If neighbour is outside the bounds of the map this will be a wall
						if (CheckX < 0 || CheckX >= gridWidth || CheckY < 0 || CheckY >= gridHeight)
						{
							neighbourWallCount++;
						}

						// If neighbour is a wall increment wall count
						else if (GetGridValue(CheckX, CheckY))
						{
							neighbourWallCount++;
						}
					}
				}

				// If neighbour wall count is over or equal to the threshold the current cell will be a wall if not it will be a floor
				if (neighbourWallCount >= wallThreshold)
				{
					tempGrid[j + k * gridWidth] = true;
				}
				else
				{
					tempGrid[j + k * gridWidth] = false;
				}
			}
		}

		// Set grid to be the newly generated grid
		Grid = tempGrid;
	}
}

// References
// White Box Dev (2020) Cellular Automata | Procedural Generation | Game Development Tutorial. Available at: https://youtu.be/slTEz6555Ts (Accessed: February 15 2023).








