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

    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cellular Automata")
	int32 GridWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cellular Automata")
	int32 GridHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cellular Automata")
	int32 NumIterations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cellular Automata")
	float Threshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cellular Automata")
	int32 WallThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cellular Automata")
	int32 SmoothIterations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Procedural Generation")
	int32 SmoothThreshold = 4;

	UFUNCTION(BlueprintCallable, Category="Cellular Automata")
	void GenerateLevel();

	UFUNCTION(BlueprintPure, Category="Cellular Automata")
	TArray<bool> GetGrid() const;

	UFUNCTION(BlueprintCallable, Category="Cellular Automata")
	void GetGridCoordinates(int32 Index, int32& X, int32& Y);
    

private:

	TArray<bool> Grid;

	void InitializeGrid();
	bool GetGridValue(int32 X, int32 Y) const;
	void SetGridValue(int32 X, int32 Y, bool Value);
	void GenerateWalls();
	void SmoothGrid();
};
