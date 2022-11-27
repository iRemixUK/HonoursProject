// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralSpawner.generated.h"

UCLASS()
class HONOURSPROJECT_API AProceduralSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	FTransform MakeTransform(int32 IndexX, int32 IndexY);

	UPROPERTY(Category = "Variables", EditAnywhere, BlueprintReadWrite)
	int32 LevelGridSize;

	UPROPERTY(Category = "Variables", EditAnywhere, BlueprintReadWrite)
	float TileSize;
	
	UFUNCTION(BlueprintCallable)
    	bool CheckIfWallShouldBeGenerated(int32 IndexX, int32 IndexY);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
