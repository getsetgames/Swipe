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
	static FSwipeDelegatePool SwipeRightDelegate;
	static FSwipeDelegatePool SwipeUpDelegate;
	static FSwipeDelegatePool SwipeDownDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSwipeDelegate);
	
	UPROPERTY(BlueprintAssignable)
	FSwipeDelegate SwipeLeft;
	
	UPROPERTY(BlueprintAssignable)
	FSwipeDelegate SwipeRight;
	
	UPROPERTY(BlueprintAssignable)
	FSwipeDelegate SwipeUp;
	
	UPROPERTY(BlueprintAssignable)
	FSwipeDelegate SwipeDown;
	
	void OnRegister() override;
	void OnUnregister() override;
	
private:
	void SwipeLeft_Handler() { SwipeLeft.Broadcast(); }
	void SwipeRight_Handler() { SwipeRight.Broadcast(); }
	void SwipeUp_Handler() { SwipeUp.Broadcast(); }
	void SwipeDown_Handler() { SwipeDown.Broadcast(); }
};
