// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "PurpleLeafController.generated.h"

/**
 * 
 */
UCLASS()
class PURPLELEAF_API APurpleLeafController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay();

	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<class UUserWidget> MainMenuWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		UUserWidget* MainMenu;
	
};
