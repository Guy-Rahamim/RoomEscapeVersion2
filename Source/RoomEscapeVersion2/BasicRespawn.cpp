// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicRespawn.h"

// Sets default values for this component's properties
UBasicRespawn::UBasicRespawn()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBasicRespawn::BeginPlay()
{
	Super::BeginPlay();

	Spawn = GetOwner()->GetActorLocation();
	
}


// Called every frame
void UBasicRespawn::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	Location = GetOwner()->GetActorLocation();
	if (Location.Z <= -50000.f)
	GetOwner()->SetActorLocation(Spawn);

}

