// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CeullularAutomata.generated.h"

USTRUCT(BlueprintType)
struct FTileStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Index")
	int32 indexX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Index")
	int32 indexY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tile value")
	int32 value;
};

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

	const int tilemapHeight = 20;
	const int tilemapWidth = 20;

	FTileStruct Grid[400];

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Array")
	TArray<FTileStruct> FinalGrid;

	UFUNCTION(BlueprintCallable)
	void make_noise_grid(int density);

	UFUNCTION(BlueprintCallable)
	void apply_cellular_automation(int iterations);

	bool isWithinMapBounds(int x, int y);

	void print2DArray();

	void SetElement(int x, int y, int value);

	int32 GetElement(int x, int y, FTileStruct Grid[]);

	void convertArray();
};
