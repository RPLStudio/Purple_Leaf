// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"
#include "Runtime/Engine/Classes/Components/ShapeComponent.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	collider = CreateDefaultSubobject<UBoxComponent>("BoxCollider");
	RootComponent = collider;
	
	body = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

