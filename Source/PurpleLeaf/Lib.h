// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "list.h"
#include "CoreMinimal.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Lib.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct PURPLELEAF_API FInventoryItems
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		bool Stackable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		int Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		UTexture2D *Icon;
};

class PURPLELEAF_API UInventory
{


public:

	static const int max = 1;

	//static TList<FInventoryItems> InventoryItems;

	//static TList<int> Inventory;

	static int InventoryLength;

	static void add(int obj);

	static void remove(int index);
};

class PURPLELEAF_API ULib 
{
	
	
public:

	static UInventory Inventory();


	UFUNCTION(BlueprintCallable)
		static void Save();

	UFUNCTION(BlueprintCallable)
		static void Init();


};



