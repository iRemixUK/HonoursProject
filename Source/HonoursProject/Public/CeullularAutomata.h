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

    // Variables needed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cellular Automata")
	int32 gridWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cellular Automata")
	int32 gridHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cellular Automata")
	int32 numIterations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cellular Automata")
	float threshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cellular Automata")
	int32 wallThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cellular Automata")
	float TileSize;

	// Functions that will be called in the blueprint
	UFUNCTION(BlueprintCallable, Category="Cellular Automata")
	void GenerateLevel();

	UFUNCTION(BlueprintPure, Category="Cellular Automata")
	TArray<bool> GetGrid() const;

	UFUNCTION(BlueprintCallable, Category="Cellular Automata")
	void GetGridCoordinates(int32 Index, int32& X, int32& Y);

	UFUNCTION(BlueprintCallable, Category="Cellular Automata")
	FTransform MakeTransformFromIndex(int32 IndexX, int32 IndexY);
    

private:
	// Grid that will be used
	TArray<bool> Grid;

	// Functions needed
	void InitializeGrid();
	bool GetGridValue(int32 X, int32 Y) const;
	void SetGridValue(int32 X, int32 Y, bool Value);
	void GenerateWalls();
};
