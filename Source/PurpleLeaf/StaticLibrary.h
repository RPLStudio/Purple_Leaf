// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "stdio.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StaticLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PURPLELEAF_API UStaticLibrary : public UObject
{
	GENERATED_BODY()

public:
		UFUNCTION(BlueprintCallable)
		static void Save(FString filename,UObject *object);

		
	
	
};
