// Fill out your copyright notice in the Description page of Project Settings.

#include "Activator.h"

// Sets default values for this component's properties
UActivator::UActivator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActivator::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


bool UActivator::GetActive()
{
	return bIsActive;
}

void UActivator::SetActive(bool IsActive)
{
	bIsActive = IsActive;
}

// Called every frame
void UActivator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

