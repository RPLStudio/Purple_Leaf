// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	body = CreateDefaultSubobject<UBoxComponent>(TEXT("collider"));
	RootComponent = body;
	body->bGenerateOverlapEvents = true;
	body->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnOverlapBegin);
	body->OnComponentEndOverlap.AddDynamic(this, &AItem::OnOverlapEnd);



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

void AItem::PickUp()
{
	return;

}

void AItem::GetPlayer(AActor *player)
{

}

void AItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void AItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}