// Fill out your copyright notice in the Description page of Project Settings.

#include "PartolRouteComponent.h"


TArray<AActor*> UPartolRouteComponent::GetPatrolPoints() const
{
	return PatrolPoints;
}
