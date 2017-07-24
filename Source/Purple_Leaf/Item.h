// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Purple_LeafCharacter.h"
#include "CommonHeader.h"
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

	
	
};
