// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PartolRouteComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S05_PROVINGGROUNDS_API UPartolRouteComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	TArray<AActor*> GetPatrolPoints() const;

private:	

	UPROPERTY(EditInstanceOnly, Category = "Patrolling")
	TArray<AActor*> PatrolPoints;
	
};
