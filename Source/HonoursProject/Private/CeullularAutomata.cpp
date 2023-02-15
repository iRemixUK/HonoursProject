// Fill out your copyright notice in the Description page of Project Settings.


#include "CeullularAutomata.h"

// Sets default values
ACeullularAutomata::ACeullularAutomata()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	noiseGrid[tilemapHeight][tilemapWidth];

	random = FMath::RandRange(1, 100);

	for (int i = 0; i < tilemapHeight; i++)
	{
		for (int j = 0; j < tilemapWidth; j++)
		{
			if (random > density)
			{
				// Turn tile into floor
				noiseGrid[i][j] = 0;
			}
			else
			{
				// Turn tile into wall
				noiseGrid[i][j] = 1;
			}
		}
	}
}

void ACeullularAutomata::apply_cellular_automation(int iterations)
{
	for (int i = 0; i < iterations; i++)
	{
		int tempGrid[tilemapHeight][tilemapWidth];
		memcpy(tempGrid, noiseGrid, tilemapHeight*tilemapWidth*sizeof(int));

		for (int j = 0; j < tilemapHeight; j++)
		{
			for (int k = 0; k < tilemapWidth; k++)
			{
				int neighbourWallCount = 0;

				for(int y = j-1; y < j + 1; y++)
				{
					for(int x = k-1; y < k + 1; x++)
					{
						if (isWithinMapBounds(x, y))
						{
							if (y != j || x != k)
							{
								if(tempGrid[y][x] == 1)
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

					if (neighbourWallCount > 4)
					{
						noiseGrid[j][k] = 1;
					}
					else
					{
						noiseGrid[j][k] = 0;
					}
				}
			}
		}
	}
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





