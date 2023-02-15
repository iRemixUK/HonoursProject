// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CeullularAutomata.generated.h"

UCLASS()
class HONOURSPROJECT_API ACeullularAutomata : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACeullularAutomata();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int tilemapHeight = 20;
	int tilemapWidth = 20;
	int noiseGrid[0][0];

	void make_noise_grid(int density);

	void apply_cellular_automation(int iterations);

	bool isWithinMapBounds(int x, int y);

	void print2DArray();
	

	int random= 0;
	

};
