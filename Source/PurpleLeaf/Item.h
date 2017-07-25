// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PurpleLeafCharacter.h"
#include "Runtime/Engine/Classes/Components/ShapeComponent.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class PURPLELEAF_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "aproperty")
		UStaticMeshComponent *body;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "aproperty")
		UShapeComponent *collider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "aproperty")
	FString name = TEXT("name");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "aproperty")
	int ID = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "aproperty")
		TArray<FString> log;
		


	bool IsInRange = false;

	APurpleLeafCharacter *player;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void PickUp();

	
};
