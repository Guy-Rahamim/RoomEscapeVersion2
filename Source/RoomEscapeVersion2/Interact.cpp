// Fill out your copyright notice in the Description page of Project Settings.

#include "Interact.h"

// Sets default values for this component's properties
UInteract::UInteract()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteract::BeginPlay()
{
	Super::BeginPlay();

	SetupInputComponent();
	
}


// Called every frame
void UInteract::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ViewpointInfo();


}

void UInteract::GetFirstActorHit()
{

	FHitResult Hit;
	FCollisionQueryParams CollisionParams(FName(TEXT("")), false, GetOwner());
	//Line Tracing
	GetWorld()->LineTraceSingleByObjectType(Hit,
		PlayerViewpointLocation, LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldStatic),
		CollisionParams);

	AActor* Actor = Hit.GetActor();

	if (Actor)
	{

		if (Actor->FindComponentByClass<UActivator>())
		{
			if (something == nullptr)
			{
				UE_LOG(LogTemp,Warning,TEXT("DASGASG"))
				something = Actor->FindComponentByClass<UActivator>();
				something->UActivator::SetActive(true);
				something = nullptr;
			//	something->UActivator::SetActive(false);

				return;
			}

/*			if (something != nullptr)
			{
				UE_LOG(LogTemp, Warning, TEXT("32458658436251"))
				something->UActivator::SetActive(false);
				something = nullptr;
				return;
			*/}
		
		}
	return;
	}




	






	//if (something)
	//{
	//	bool yes = something->UActivator::GetActive();
	//	bool No = false;
	//	something->UActivator::SetActive(yes);
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("MyCharacter's Bool is %s"), (yes ? TEXT("True") : TEXT("False")));
	//	}
	//	}
	//FString Name = Hit.GetActor()->GetName();
	//	if (Name == "SM_Lamp_Wall_6")
	//	{
	//		Actor->SetActorRotation(FRotator(32+add, 245+add, 300+add));
	//}
	


void UInteract::ViewpointInfo()
{
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		PlayerViewpointLocation, PlayerViewpointRotation);
	LineTraceDirection = PlayerViewpointRotation.Vector();
	LineTraceEnd = LineTraceDirection * Reach + PlayerViewpointLocation;

}

void UInteract::VisualiseRaycast()
{
	DrawDebugLine(GetWorld(),
		PlayerViewpointLocation,
		LineTraceEnd,
		FColor(FColor::Red), false,
		0, 0, 10);
}

void UInteract::SetupInputComponent()
{		

	//{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
		InputComponent->BindAction("Use", IE_Pressed, this, &UInteract::Use);
	//}
}

void UInteract::Use()
{
	GetFirstActorHit();
}

