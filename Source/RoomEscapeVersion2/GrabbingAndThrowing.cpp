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
	SetupInputComponent();
	SetupPhysicsHandle();
}


// Called every frame
void UGrabbingAndThrowing::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	DrawCrosshair();
	
	if (PhysicsHandle->GrabbedComponent)
	{
		if (PhysicsHandle->GrabbedComponent->GetMass()<20)
		{PhysicsHandle->SetTargetLocationAndRotation(HandsEnd,PlayerViewPointRotation); }
		else { PhysicsHandle->SetTargetLocationAndRotation(LineTraceEnd, PlayerViewPointRotation); }
	}
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

	GetWorld()->LineTraceSingleByObjectType(
		OUT FirstActorHit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		CollisionParams);

	//Extracting the actor hit name and logging it
	AActor* Actor = FirstActorHit.GetActor();
	if (Actor)
	{
		
		//UE_LOG(LogTemp, Warning, TEXT("actor being hit: %s"), *(Actor->GetName()))
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
	LineTraceEnd = LineTraceDirection * TraceReach+PlayerViewPointLocation;
	CrosshairEnd = LineTraceDirection * CrosshairReach + PlayerViewPointLocation;
	HandsEnd = LineTraceDirection * HandsReach + PlayerViewPointLocation;
	Impulse = LineTraceDirection * (ImpulsePush);
}

void UGrabbingAndThrowing::SetupInputComponent()
{
	//setting and checking for the input component.

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	///binding the action input the a function
	InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabbingAndThrowing::Grab);
	InputComponent->BindAction("Throw", IE_Pressed, this, &UGrabbingAndThrowing::Throw);
}
void UGrabbingAndThrowing::DrawCrosshair()
{
	
	ViewInfo();
	DrawDebugCrosshairs(
		GetWorld(),
		CrosshairEnd,
		PlayerViewPointRotation,
		2, //scale
		FColor(FColor::Black),
		false, //will the crosshair persist
		0.1f,//lifetime
		1);
}
void UGrabbingAndThrowing::Throw()
{
	auto ComponentToGrab = Raycast().GetComponent();
	if (PhysicsHandle->GrabbedComponent)
	{
		ViewInfo();
		PhysicsHandle->GrabbedComponent->AddImpulse(Impulse, NAME_None, true);
		PhysicsHandle->ReleaseComponent();
		return;
	}
}
void UGrabbingAndThrowing::SetupPhysicsHandle()
{

	//setting and checking for the physics handle.
	PhysicsHandle=GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (!PhysicsHandle)
	{UE_LOG(LogTemp,Error,TEXT("no physicshandle bitch")) }

}

void UGrabbingAndThrowing::Grab()
{
		auto ComponentToGrab = Raycast().GetComponent();
	if (PhysicsHandle->GrabbedComponent)
	{
//		ViewInfo();
	//	PhysicsHandle->GrabbedComponent->AddImpulse(Impulse, NAME_None,true);
		PhysicsHandle->ReleaseComponent();
		return;
	}

	if (!PhysicsHandle->GrabbedComponent)
	{

		if (ComponentToGrab)
		{
				PhysicsHandle->GrabComponentAtLocationWithRotation(ComponentToGrab,
				NAME_None,
				ComponentToGrab->GetOwner()->GetActorLocation()
				, ComponentToGrab->GetOwner()->GetActorRotation());
			return;		}			
	}

}
