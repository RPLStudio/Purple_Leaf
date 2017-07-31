// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Saving.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FGameContent
{
	GENERATED_USTRUCT_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGameBasic")
		float SpiritualValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGameBasic")
		TArray<int> inventory;


	

};

UCLASS()
class PURPLELEAF_API USaving : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGameBasic")
		FGameContent currentGame;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGameBasic")
		FString SaveSlotName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SaveGameBasic")
		int UserIndex;
	
	
};
