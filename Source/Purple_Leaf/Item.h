// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Purple_LeafCharacter.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/ShapeComponent.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class PURPLE_LEAF_API AItem : public AActor
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
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		UShapeComponent *body;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		UStaticMeshComponent *mesh;

	
	APurple_LeafCharacter *player;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
	FString name = FString(TEXT("item name"));

	UFUNCTION()
	void PickUp();

	UFUNCTION()
	void GetPlayer(AActor *player);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "property")
		bool ItemInRange = false;
	
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
};
