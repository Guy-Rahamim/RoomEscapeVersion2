// Fill out your copyright notice in the Description page of Project Settings.

#include "RespawnActivator.h"

// Sets default values for this component's properties
URespawnActivator::URespawnActivator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URespawnActivator::BeginPlay()
{
	Super::BeginPlay();

	Activator = GetOwner()->FindComponentByClass<UActivator>();


}


// Called every frame
void URespawnActivator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Respawner();
}

void URespawnActivator::Respawner()
{
	if (Activator!=nullptr)
	{

		if (Activator->UActivator::GetActive())
		{
			UE_LOG(LogTemp, Warning, TEXT("hello hello"))
			Spawn.Broadcast();
			Activator->UActivator::SetActive(false);

			return;
		}
	}

}

