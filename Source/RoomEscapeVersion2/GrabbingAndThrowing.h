// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/StaticMeshActor.h"
#include "CollisionQueryParams.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GameFramework/PlayerController.h"
#include "components/InputComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Components/PrimitiveComponent.h"
#include "GrabbingAndThrowing.generated.h"
#define OUT


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROOMESCAPEVERSION2_API UGrabbingAndThrowing : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabbingAndThrowing();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	FHitResult Hit;



	UPhysicsHandleComponent *PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;
	
	UPrimitiveComponent* Component;


	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	FVector LineTraceStart;
	FVector LineTraceEnd;
	FVector CrosshairEnd;
	FVector HandsEnd;
	FVector LineTraceDirection;

	float TraceReach = 200.f;
	float HandsReach = 130.f;
	float CrosshairReach = 15.f;
	FHitResult Raycast();

	void Grab();
	void VisualiseRaycast();
	void ViewInfo();
	void SetupPhysicsHandle();
	void SetupInputComponent();
	void DrawCrosshair();
	
		
};
