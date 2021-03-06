// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	collider = CreateDefaultSubobject<UBoxComponent>("BoxCollider");
	RootComponent = collider;
	collider->bGenerateOverlapEvents = true;
	collider->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnOverlapBegin);
	collider->OnComponentEndOverlap.AddDynamic(this, &AItem::OnOverlapEnd);
	

	body = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	body->AttachToComponent(collider, *(new FAttachmentTransformRules(EAttachmentRule::KeepRelative,EAttachmentRule::KeepRelative,EAttachmentRule::KeepWorld,false)));

	
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

	if (player)
	{
		if (IsInRange && player->IsPickingUp)
		{
			PickUp();
			Destroy();
		}
	}

}

void AItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		IsInRange = true;
		player = Cast<APurpleLeafCharacter>(OtherActor);
		
	}
}

void AItem::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	IsInRange = false;
	player = nullptr;
}

void AItem::PickUp() {
	player->inventory.Add(ID);
}