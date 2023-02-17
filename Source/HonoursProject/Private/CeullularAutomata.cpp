// Fill out your copyright notice in the Description page of Project Settings.


#include "CeullularAutomata.h"

// Sets default values
ACeullularAutomata::ACeullularAutomata()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialise array
	Grid[tilemapWidth * tilemapHeight];

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

void ACeullularAutomata::make_noise_grid(int density)
{
	for (int i = 0; i < tilemapHeight; i++)
	{
		for (int j = 0; j < tilemapWidth; j++)
		{
			int32 random = FMath::RandRange(1, 100);

			if(random > density)
			{
				// Set value to floor
				SetElement(i, j, 0);
			}
			else
			{
				// Set value to wall
				SetElement(i, j, 1);
			}
		}
	}
	
}

void ACeullularAutomata::apply_cellular_automation(int iterations)
{
	for (int i = 1; i <= iterations; i++)
	{
		FTileStruct tempGrid[400];
		memcpy(tempGrid, Grid, sizeof(Grid));

		for (int j = 1; j < tilemapHeight; j++)
		{
			for (int k = 1; k < tilemapWidth; k++)
			{
				int32 neighbourWallCount = 0;

				for (int y = j - 1; y < j + 1; y++)
				{
					for (int x = k - 1; x < k +1; x++)
					{
						if (isWithinMapBounds(x, y))
						{
							if(y != j || x != k)
							{
								if(GetElement(x, y, tempGrid) == 1)
								{
									neighbourWallCount++;
								}
							}
						}
						else
						{
							neighbourWallCount++;
						}
					}
				}
				if (neighbourWallCount > 4)
				{
					SetElement(j,k,1);
				}
				else
				{
					SetElement(j,k,0);
				}
			}
		}
	}
	convertArray();
}

bool ACeullularAutomata::isWithinMapBounds(int x, int y)
{
	if ((x >=0 && x <= tilemapWidth) && (y >= 0 && y <= tilemapHeight))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ACeullularAutomata::print2DArray()
{
	for (int i = 0; i < tilemapHeight; i++)
	{
		for (int j = 0; j < tilemapWidth; j++)
		{
			
		}
	}
}

void ACeullularAutomata::SetElement(int x, int y, int value)
{
	Grid[(tilemapWidth * x) + y].value = value;
	Grid[(tilemapWidth * x) + y].indexX = x;
	Grid[(tilemapWidth * x) + y].indexY = y;
}

int32 ACeullularAutomata::GetElement(int x, int y, FTileStruct GridArray[])
{
	return GridArray[(tilemapWidth * x) + y].value;
}

void ACeullularAutomata::convertArray()
{
	FinalGrid.Append(Grid, UE_ARRAY_COUNT(Grid));
}






