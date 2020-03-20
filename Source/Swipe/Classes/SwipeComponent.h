//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "Components/ActorComponent.h"
#include "SwipeComponent.generated.h"

UCLASS(ClassGroup = Input, HideCategories = (Activation, "Components|Activation", Collision), meta = (BlueprintSpawnableComponent))
class SWIPE_API USwipeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTouchDynDelegate, FVector2D, TouchLocation, int32, Handle);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSwipeTriggeredDynDelegate, FVector2D, StartLocation, FVector2D, TriggerLocation);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSwipeEndedDynDelegate, FVector2D, StartLocation, FVector2D, TriggerLocation, FVector2D, EndLocation);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTapDynDelegate, FVector2D, TapLocation);

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

	UPROPERTY(BlueprintAssignable)
	FTapDynDelegate SingleTap;

	UPROPERTY(BlueprintAssignable)
	FTapDynDelegate DoubleTap;

	void OnRegister() override;
	void OnUnregister() override;

private:
	void TouchBegan_Handler(FVector2D TouchLocation, int32 Handle) { TouchBegan.Broadcast(TouchLocation, Handle); }
	void TouchMoved_Handler(FVector2D TouchLocation, int32 Handle) { TouchMoved.Broadcast(TouchLocation, Handle); }
	void TouchEnded_Handler(FVector2D TouchLocation, int32 Handle) { TouchEnded.Broadcast(TouchLocation, Handle); }

	void SwipeLeft_Handler(FVector2D StartLocation, FVector2D TriggerLocation) { SwipeLeft.Broadcast(StartLocation, TriggerLocation); }
	void SwipeLeftEnded_Handler(FVector2D StartLocation, FVector2D TriggerLocation, FVector2D EndLocation) { SwipeLeftEnded.Broadcast(StartLocation, TriggerLocation, EndLocation); }

	void SwipeRight_Handler(FVector2D StartLocation, FVector2D TriggerLocation) { SwipeRight.Broadcast(StartLocation, TriggerLocation); }
	void SwipeRightEnded_Handler(FVector2D StartLocation, FVector2D TriggerLocation, FVector2D EndLocation) { SwipeRightEnded.Broadcast(StartLocation, TriggerLocation, EndLocation); }

	void SwipeUp_Handler(FVector2D StartLocation, FVector2D TriggerLocation) { SwipeUp.Broadcast(StartLocation, TriggerLocation); }
	void SwipeUpEnded_Handler(FVector2D StartLocation, FVector2D TriggerLocation, FVector2D EndLocation) { SwipeUpEnded.Broadcast(StartLocation, TriggerLocation, EndLocation); }

	void SwipeDown_Handler(FVector2D StartLocation, FVector2D TriggerLocation) { SwipeDown.Broadcast(StartLocation, TriggerLocation); }
	void SwipeDownEnded_Handler(FVector2D StartLocation, FVector2D TriggerLocation, FVector2D EndLocation) { SwipeDownEnded.Broadcast(StartLocation, TriggerLocation, EndLocation); }

	void SingleTap_Handler(FVector2D TapLocation) { SingleTap.Broadcast(TapLocation); }
	void DoubleTap_Handler(FVector2D TapLocation) { DoubleTap.Broadcast(TapLocation); }
};
