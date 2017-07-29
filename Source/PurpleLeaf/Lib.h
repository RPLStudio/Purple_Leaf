// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "save.h"
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
		int ID;

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

UCLASS()
class PURPLELEAF_API ULib : public UObject
{
	GENERATED_BODY()
	
public:
	Usave *savedata;



	static TArray<FInventoryItems> InventoryItemList;

	UFUNCTION(BlueprintCallable)
		static void Save();

};

