// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Activator.h"

#include "activated.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLaunch);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROOMESCAPEVERSION2_API Uactivated : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	Uactivated();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere)
	AActor* Actor = nullptr;
	UActivator* Lever = nullptr;
	UPROPERTY(BlueprintAssignable)
		FLaunch UP;

	UPROPERTY(BlueprintAssignable)
		FLaunch DOWN;
private:

};
