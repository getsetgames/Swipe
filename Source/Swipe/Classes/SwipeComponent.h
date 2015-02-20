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
	DECLARE_MULTICAST_DELEGATE(FSwipeDelegatePool);
	
	static FSwipeDelegatePool SwipeLeftDelegate;
	static FSwipeDelegatePool SwipeLeftEndedDelegate;
	
	static FSwipeDelegatePool SwipeRightDelegate;
	static FSwipeDelegatePool SwipeRightEndedDelegate;
	
	static FSwipeDelegatePool SwipeUpDelegate;
	static FSwipeDelegatePool SwipeUpEndedDelegate;
	
	static FSwipeDelegatePool SwipeDownDelegate;
	static FSwipeDelegatePool SwipeDownEndedDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSwipeDelegate);
	
	UPROPERTY(BlueprintAssignable)
	FSwipeDelegate SwipeLeft;

	UPROPERTY(BlueprintAssignable)
	FSwipeDelegate SwipeLeftEnded;

	UPROPERTY(BlueprintAssignable)
	FSwipeDelegate SwipeRight;
	
	UPROPERTY(BlueprintAssignable)
	FSwipeDelegate SwipeRightEnded;
	
	UPROPERTY(BlueprintAssignable)
	FSwipeDelegate SwipeUp;
	
	UPROPERTY(BlueprintAssignable)
	FSwipeDelegate SwipeUpEnded;
	
	UPROPERTY(BlueprintAssignable)
	FSwipeDelegate SwipeDown;

	UPROPERTY(BlueprintAssignable)
	FSwipeDelegate SwipeDownEnded;
	
	void OnRegister() override;
	void OnUnregister() override;
	
private:
	void SwipeLeft_Handler() { SwipeLeft.Broadcast(); }
	void SwipeLeftEnded_Handler() { SwipeLeftEnded.Broadcast(); }

	void SwipeRight_Handler() { SwipeRight.Broadcast(); }
	void SwipeRightEnded_Handler() { SwipeRightEnded.Broadcast(); }

	void SwipeUp_Handler() { SwipeUp.Broadcast(); }
	void SwipeUpEnded_Handler() { SwipeUpEnded.Broadcast(); }

	void SwipeDown_Handler() { SwipeDown.Broadcast(); }
	void SwipeDownEnded_Handler() { SwipeDownEnded.Broadcast(); }
};