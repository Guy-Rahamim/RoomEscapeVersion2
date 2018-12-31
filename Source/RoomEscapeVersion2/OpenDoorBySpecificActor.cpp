// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoorBySpecificActor.h"

// Sets default values for this component's properties
UOpenDoorBySpecificActor::UOpenDoorBySpecificActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoorBySpecificActor::BeginPlay()
{
	Super::BeginPlay();

	
	
}


// Called every frame
void UOpenDoorBySpecificActor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if ((Plate != nullptr) && (DoorOpener != nullptr))
	{
		if (Plate->IsOverlappingActor(DoorOpener))
		{
			//UE_LOG(LogTemp, Error, TEXT("YES actor overlapping"))
			FString Name = DoorOpener->GetName();
			UE_LOG(LogTemp, Warning, TEXT("actor overlapping %s"), *Name)
		}
		if (!(Plate->IsOverlappingActor(DoorOpener)))
		{
			UE_LOG(LogTemp, Warning, TEXT("No actor overlapping"))
		}
	}
}

