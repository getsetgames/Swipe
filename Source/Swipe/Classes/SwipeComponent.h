//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "SwipeComponent.generated.h"

UCLASS(ClassGroup=Input, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class USwipeComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTouchDynDelegate, FVector2D, TouchLocation);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSwipeTriggeredDynDelegate, FVector2D, StartLocation, FVector2D, TriggerLocation);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSwipeEndedDynDelegate, FVector2D, StartLocation, FVector2D, TriggerLocation, FVector2D, EndLocation);
	
	UPROPERTY(BlueprintAssignable)
	FTouchDynDelegate TouchBegan;

	UPROPERTY(BlueprintAssignable)
	FTouchDynDelegate TouchMoved;

	UPROPERTY(BlueprintAssignable)
	FTouchDynDelegate TouchEnded;

	UPROPERTY(BlueprintAssignable)
	FSwipeTriggeredDynDelegate SwipeLeft;

	UPROPERTY(BlueprintAssignable)
	FSwipeEndedDynDelegate SwipeLeftEnded;

	UPROPERTY(BlueprintAssignable)
	FSwipeTriggeredDynDelegate SwipeRight;
	
	UPROPERTY(BlueprintAssignable)
	FSwipeEndedDynDelegate SwipeRightEnded;
	
	UPROPERTY(BlueprintAssignable)
	FSwipeTriggeredDynDelegate SwipeUp;
	
	UPROPERTY(BlueprintAssignable)
	FSwipeEndedDynDelegate SwipeUpEnded;
	
	UPROPERTY(BlueprintAssignable)
	FSwipeTriggeredDynDelegate SwipeDown;

	UPROPERTY(BlueprintAssignable)
	FSwipeEndedDynDelegate SwipeDownEnded;
	
	void OnRegister() override;
	void OnUnregister() override;
	
private:
	void TouchBegan_Handler(FVector2D TouchLocation) { TouchBegan.Broadcast(TouchLocation); }
	void TouchMoved_Handler(FVector2D TouchLocation) { TouchMoved.Broadcast(TouchLocation); }
	void TouchEnded_Handler(FVector2D TouchLocation) { TouchEnded.Broadcast(TouchLocation); }

	void SwipeLeft_Handler(FVector2D StartLocation, FVector2D TriggerLocation) { SwipeLeft.Broadcast(StartLocation, TriggerLocation); }
	void SwipeLeftEnded_Handler(FVector2D StartLocation, FVector2D TriggerLocation, FVector2D EndLocation) { SwipeLeftEnded.Broadcast(StartLocation, TriggerLocation, EndLocation); }

	void SwipeRight_Handler(FVector2D StartLocation, FVector2D TriggerLocation) { SwipeRight.Broadcast(StartLocation, TriggerLocation); }
	void SwipeRightEnded_Handler(FVector2D StartLocation, FVector2D TriggerLocation, FVector2D EndLocation) { SwipeRightEnded.Broadcast(StartLocation, TriggerLocation, EndLocation); }

	void SwipeUp_Handler(FVector2D StartLocation, FVector2D TriggerLocation) { SwipeUp.Broadcast(StartLocation, TriggerLocation); }
	void SwipeUpEnded_Handler(FVector2D StartLocation, FVector2D TriggerLocation, FVector2D EndLocation) { SwipeUpEnded.Broadcast(StartLocation, TriggerLocation, EndLocation); }

	void SwipeDown_Handler(FVector2D StartLocation, FVector2D TriggerLocation) { SwipeDown.Broadcast(StartLocation, TriggerLocation); }
	void SwipeDownEnded_Handler(FVector2D StartLocation, FVector2D TriggerLocation, FVector2D EndLocation) { SwipeDownEnded.Broadcast(StartLocation, TriggerLocation, EndLocation); }
};