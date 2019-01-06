// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DrawDebugHelpers.h"
#include "CollisionQueryParams.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GameFramework/PlayerController.h"
#include "components/InputComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Interact.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROOMESCAPEVERSION2_API UInteract : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteract();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void GetFirstActorHit();
	void ViewpointInfo();
	void VisualiseRaycast();
	void SetupInputComponent();
	void Use();

private:
	FVector PlayerViewpointLocation;
	FRotator PlayerViewpointRotation;
	FVector LineTraceEnd;
	FVector LineTraceDirection;
	float add = 1.3;
	float Reach = 200.f;
	UInputComponent* InputComponent=nullptr;
	AActor* LampUsed = nullptr;
		
};
