// Fill out your copyright notice in the Description page of Project Settings.

#include "activated.h"

// Sets default values for this component's properties
Uactivated::Uactivated()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Uactivated::BeginPlay()
{
	Super::BeginPlay();
	if (Actor)
	Lever = Actor->FindComponentByClass<UActivator>();

	
}


// Called every frame
void Uactivated::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Lever)
	{
		if (Lever->UActivator::GetActive()==true)
		{
			UP.Broadcast();
		}
		else if (Lever->GetActive()==false) { DOWN.Broadcast(); }
	}
}

