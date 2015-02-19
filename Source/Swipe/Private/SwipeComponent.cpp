//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "SwipePrivatePCH.h"

void USwipeComponent::OnRegister()
{
	Super::OnRegister();
	
	USwipeComponent::SwipeLeftDelegate.AddUObject(this, &USwipeComponent::SwipeLeft_Handler);
	USwipeComponent::SwipeRightDelegate.AddUObject(this, &USwipeComponent::SwipeRight_Handler);
	USwipeComponent::SwipeUpDelegate.AddUObject(this, &USwipeComponent::SwipeUp_Handler);
	USwipeComponent::SwipeDownDelegate.AddUObject(this, &USwipeComponent::SwipeDown_Handler);
}

void USwipeComponent::OnUnregister()
{
	Super::OnUnregister();

	USwipeComponent::SwipeLeftDelegate.RemoveAll(this);
	USwipeComponent::SwipeRightDelegate.RemoveAll(this);
	USwipeComponent::SwipeUpDelegate.RemoveAll(this);
	USwipeComponent::SwipeDownDelegate.RemoveAll(this);
}

USwipeComponent::FSwipeDelegatePool USwipeComponent::SwipeLeftDelegate;
USwipeComponent::FSwipeDelegatePool USwipeComponent::SwipeRightDelegate;
USwipeComponent::FSwipeDelegatePool USwipeComponent::SwipeUpDelegate;
USwipeComponent::FSwipeDelegatePool USwipeComponent::SwipeDownDelegate;
