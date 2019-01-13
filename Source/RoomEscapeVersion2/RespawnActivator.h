// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Activator.h"
#include "Activated.h"
#include "RespawnActivator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSpawn);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ROOMESCAPEVERSION2_API URespawnActivator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URespawnActivator();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	//UPROPERTY(EditAnywhere)
	//AActor* Handle = nullptr;
	UActivator* Activator = nullptr;
	Uactivated* LauncherComponent = nullptr;
private:
	UPROPERTY(BlueprintAssignable)
	FSpawn SpawnSphere;

	UPROPERTY(BlueprintAssignable)
		FSpawn MoveHandle;

	UPROPERTY(EditAnywhere)
		AActor* Launcher = nullptr;

	void Respawner();
};
