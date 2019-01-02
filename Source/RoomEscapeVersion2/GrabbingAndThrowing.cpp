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
	//VisualiseRaycast();
	//Raycast();
	SetupPhysicsHandleAndInputComponent();
	
	//ray casting from the players eye height
}

void UGrabbingAndThrowing::VisualiseRaycast()
{

	ViewInfo();
	DrawDebugLine(GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 255),
		false,
		0.f, 0, 10);


}

FHitResult UGrabbingAndThrowing::Raycast()
{

	FCollisionQueryParams CollisionParams(FName(TEXT("")), false, GetOwner());
	FHitResult FirstActorHit;
	GetWorld()->LineTraceSingleByObjectType(FirstActorHit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), CollisionParams);

	//Extracting the actor hit name and logging it
	AActor* Actor = FirstActorHit.GetActor();
	if (Actor)
	{
		
		UE_LOG(LogTemp, Warning, TEXT("actor being hit: %s"), *(Actor->GetName()))
	}
	return FirstActorHit;
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

void UGrabbingAndThrowing::SetupPhysicsHandleAndInputComponent()
{

	//setting and checking for the physics handle.
	PhysicsHandle=GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (!PhysicsHandle)
	{UE_LOG(LogTemp,Error,TEXT("no physicshandle bitch")) }

	//setting and checking for the input component.

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (!InputComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("no Input Component bitch"))
	}

	///binding the action input the a function
	InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabbingAndThrowing::Grab);
}

void UGrabbingAndThrowing::Grab()
{
	ViewInfo();
	auto ComponentToGrab = Raycast().GetComponent();
	if (ComponentToGrab)
	{
		PhysicsHandle->GrabComponent(ComponentToGrab,
			NAME_None,
			ComponentToGrab->GetOwner()->GetActorLocation()
			, true);
	}
}
