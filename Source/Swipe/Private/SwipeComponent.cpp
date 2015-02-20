//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "SwipePrivatePCH.h"

void USwipeComponent::OnRegister()
{
	Super::OnRegister();
	
	USwipeComponent::SwipeLeftDelegate.AddUObject(this, &USwipeComponent::SwipeLeft_Handler);
	USwipeComponent::SwipeLeftEndedDelegate.AddUObject(this, &USwipeComponent::SwipeLeftEnded_Handler);
	
	USwipeComponent::SwipeRightDelegate.AddUObject(this, &USwipeComponent::SwipeRight_Handler);
	USwipeComponent::SwipeRightEndedDelegate.AddUObject(this, &USwipeComponent::SwipeRightEnded_Handler);
	
	USwipeComponent::SwipeUpDelegate.AddUObject(this, &USwipeComponent::SwipeUp_Handler);
	USwipeComponent::SwipeUpEndedDelegate.AddUObject(this, &USwipeComponent::SwipeUpEnded_Handler);
	
	USwipeComponent::SwipeDownDelegate.AddUObject(this, &USwipeComponent::SwipeDown_Handler);
	USwipeComponent::SwipeDownEndedDelegate.AddUObject(this, &USwipeComponent::SwipeDownEnded_Handler);
}

void USwipeComponent::OnUnregister()
{
	Super::OnUnregister();

	USwipeComponent::SwipeLeftDelegate.RemoveAll(this);
	USwipeComponent::SwipeLeftEndedDelegate.RemoveAll(this);

	USwipeComponent::SwipeRightDelegate.RemoveAll(this);
	USwipeComponent::SwipeRightEndedDelegate.RemoveAll(this);

	USwipeComponent::SwipeUpDelegate.RemoveAll(this);
	USwipeComponent::SwipeUpEndedDelegate.RemoveAll(this);

	USwipeComponent::SwipeDownDelegate.RemoveAll(this);
	USwipeComponent::SwipeDownEndedDelegate.RemoveAll(this);
}

USwipeComponent::FSwipeDelegatePool USwipeComponent::SwipeLeftDelegate;
USwipeComponent::FSwipeDelegatePool USwipeComponent::SwipeLeftEndedDelegate;

USwipeComponent::FSwipeDelegatePool USwipeComponent::SwipeRightDelegate;
USwipeComponent::FSwipeDelegatePool USwipeComponent::SwipeRightEndedDelegate;

USwipeComponent::FSwipeDelegatePool USwipeComponent::SwipeUpDelegate;
USwipeComponent::FSwipeDelegatePool USwipeComponent::SwipeUpEndedDelegate;

USwipeComponent::FSwipeDelegatePool USwipeComponent::SwipeDownDelegate;
USwipeComponent::FSwipeDelegatePool USwipeComponent::SwipeDownEndedDelegate;
