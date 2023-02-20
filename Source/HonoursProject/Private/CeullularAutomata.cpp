// Fill out your copyright notice in the Description page of Project Settings.

#include "CeullularAutomata.h"

ACeullularAutomata::ACeullularAutomata()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialise grid size
	GridWidth = 30;
	GridHeight = 30;

	// Initialise number of iterations
	NumIterations = 2;
	SmoothIterations = 2;

	// Initialise thresholds
	Threshold = 0.45f;
	WallThreshold = 4;
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
	SmoothGrid();
}

TArray<bool> ACeullularAutomata::GetGrid() const
{
	return Grid;
}

void ACeullularAutomata::GetGridCoordinates(int32 Index, int32& X, int32& Y)
{
	// Calculate the x and y coordinates of the cell based on its index
	X = Index % GridWidth;
	Y = Index / GridWidth;

	// Check if coordinates are within the grid
	if (X >= 0 && X < GridWidth && Y >= 0 && Y < GridHeight)
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

void ACeullularAutomata::InitializeGrid()
{
	// Initialize grid and randomly set the values of the grid
	Grid.Empty(GridWidth * GridHeight);
	for (int32 i = 0; i < GridWidth * GridHeight; i++)
	{
		Grid.Add(FMath::RandRange(0.0f, 1.0f) < Threshold);
	}
}

bool ACeullularAutomata::GetGridValue(int32 X, int32 Y) const
{
	// Returns grid value
	return Grid[X + Y * GridWidth];
}

void ACeullularAutomata::SetGridValue(int32 X, int32 Y, bool Value)
{
	// Sets grid value
	Grid[X + Y * GridWidth] = Value;
}

void ACeullularAutomata::GenerateWalls()
{
	// For loop that will iterate based on the number of the iterations the user would like
	for (int32 i = 0; i < NumIterations; i++)
	{
		TArray<bool> tempGrid;
		tempGrid.SetNumUninitialized(GridWidth * GridHeight);

		for (int32 X = 0; X < GridWidth; X++)
		{
			for (int32 Y = 0; Y < GridHeight; Y++)
			{
				int32 neighbourWallCount = 0;
				for (int32 DX = -1; DX <= 1; DX++)
				{
					for (int32 DY = -1; DY <= 1; DY++)
					{
						if (DX == 0 && DY == 0)
						{
							continue;
						}

						int32 CheckX = X + DX;
						int32 CheckY = Y + DY;

						if (CheckX < 0 || CheckX >= GridWidth || CheckY < 0 || CheckY >= GridHeight)
						{
							neighbourWallCount++;
						}
						else if (GetGridValue(CheckX, CheckY))
						{
							neighbourWallCount++;
						}
					}
				}

				if (neighbourWallCount >= WallThreshold)
				{
					tempGrid[X + Y * GridWidth] = true;
				}
				else
				{
					tempGrid[X + Y * GridWidth] = false;
				}
			}
		}

		Grid = tempGrid;
	}
}


void ACeullularAutomata::SmoothGrid()
{
	for (int32 i = 0; i < SmoothIterations; i++)
	{
		TArray<bool> NextGrid;
		NextGrid.SetNumUninitialized(GridWidth * GridHeight);

		for (int32 X = 0; X < GridWidth; X++)
		{
			for (int32 Y = 0; Y < GridHeight; Y++)
			{
				int32 WallCount = 0;
				for (int32 DX = -1; DX <= 1; DX++)
				{
					for (int32 DY = -1; DY <= 1; DY++)
					{
						if (DX == 0 && DY == 0)
						{
							continue;
						}

						int32 CheckX = X + DX;
						int32 CheckY = Y + DY;

						if (CheckX < 0 || CheckX >= GridWidth || CheckY < 0 || CheckY >= GridHeight)
						{
							WallCount++;
						}
						else if (GetGridValue(CheckX, CheckY))
						{
							WallCount++;
						}
					}
				}

				if (WallCount >= SmoothThreshold)
				{
					NextGrid[X + Y * GridWidth] = true;
				}
				else
				{
					NextGrid[X + Y * GridWidth] = false;
				}
			}
		}

		Grid = NextGrid;
	}
}









