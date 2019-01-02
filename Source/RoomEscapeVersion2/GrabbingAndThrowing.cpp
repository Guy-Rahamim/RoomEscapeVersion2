// Fill out your copyright notice in the Description page of Project Settings.

#include "GrabbingAndThrowing.h"

// Sets default values for this component's properties
UGrabbingAndThrowing::UGrabbingAndThrowing()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabbingAndThrowing::BeginPlay()
{
	Super::BeginPlay();

	
}


// Called every frame
void UGrabbingAndThrowing::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//getting the players viewpoint and location
	ViewInfo();
	VisualiseRayCast();
	//FString Name= Hit.Actor->GetName();
//	UE_LOG(LogTemp,Warning,TEXT("actor being hit: %s"),*Name)

	//ray casting from the players eye height
}

FHitResult UGrabbingAndThrowing::VisualiseRayCast()
{

	ViewInfo();
		DrawDebugLine(GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 255), 
		false,
		0.f, 0, 10);


	GetWorld()->LineTraceSingleByObjectType(Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		0, 0);
		return Hit;
}

void UGrabbingAndThrowing::ViewInfo()
{
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation);
	LineTraceDirection = PlayerViewPointRotation.Vector();
//	LineTraceStart = PlayerViewPointLocation * LineTraceDirection;
	LineTraceEnd = LineTraceDirection * Reach+PlayerViewPointLocation;
}
