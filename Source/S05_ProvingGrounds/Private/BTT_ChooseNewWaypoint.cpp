// Fill out your copyright notice in the Description page of Project Settings.

#include "BTT_ChooseNewWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PartolRouteComponent.h"


EBTNodeResult::Type UBTT_ChooseNewWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// Get patrol points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto RouteComponent = ControlledPawn->FindComponentByClass<UPartolRouteComponent>();
	// auto RouteComponent = Cast<UPartolRouteComponent>(ControlledPawn->FindComponentByClass(UPartolRouteComponent::StaticClass()));

	// Ensure there is a route component
	if (!ensure(RouteComponent)) { return EBTNodeResult::Failed; }

	// Warn about empty patrol routes
	auto PatrolPoints = RouteComponent->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Guard %s has no patrol points"), *ControlledPawn->GetName());
		return EBTNodeResult::Failed;
	}


	// Set Next waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// Cycle the index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}



