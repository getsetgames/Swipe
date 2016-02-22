//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "SwipePrivatePCH.h"

void USwipeComponent::OnRegister()
{
	Super::OnRegister();

	USwipeDelegates::TouchBeganDelegate.AddUObject(this, &USwipeComponent::TouchBegan_Handler);
	USwipeDelegates::TouchMovedDelegate.AddUObject(this, &USwipeComponent::TouchMoved_Handler);
	USwipeDelegates::TouchEndedDelegate.AddUObject(this, &USwipeComponent::TouchEnded_Handler);

	USwipeDelegates::SwipeLeftDelegate.AddUObject(this, &USwipeComponent::SwipeLeft_Handler);
	USwipeDelegates::SwipeLeftEndedDelegate.AddUObject(this, &USwipeComponent::SwipeLeftEnded_Handler);

	USwipeDelegates::SwipeRightDelegate.AddUObject(this, &USwipeComponent::SwipeRight_Handler);
	USwipeDelegates::SwipeRightEndedDelegate.AddUObject(this, &USwipeComponent::SwipeRightEnded_Handler);

	USwipeDelegates::SwipeUpDelegate.AddUObject(this, &USwipeComponent::SwipeUp_Handler);
	USwipeDelegates::SwipeUpEndedDelegate.AddUObject(this, &USwipeComponent::SwipeUpEnded_Handler);

	USwipeDelegates::SwipeDownDelegate.AddUObject(this, &USwipeComponent::SwipeDown_Handler);
	USwipeDelegates::SwipeDownEndedDelegate.AddUObject(this, &USwipeComponent::SwipeDownEnded_Handler);

	USwipeDelegates::SingleTapDelegate.AddUObject(this, &USwipeComponent::SingleTap_Handler);
	USwipeDelegates::DoubleTapDelegate.AddUObject(this, &USwipeComponent::DoubleTap_Handler);
}

void USwipeComponent::OnUnregister()
{
	Super::OnUnregister();

	USwipeDelegates::TouchBeganDelegate.RemoveAll(this);
	USwipeDelegates::TouchMovedDelegate.RemoveAll(this);
	USwipeDelegates::TouchEndedDelegate.RemoveAll(this);

	USwipeDelegates::SwipeLeftDelegate.RemoveAll(this);
	USwipeDelegates::SwipeLeftEndedDelegate.RemoveAll(this);

	USwipeDelegates::SwipeRightDelegate.RemoveAll(this);
	USwipeDelegates::SwipeRightEndedDelegate.RemoveAll(this);

	USwipeDelegates::SwipeUpDelegate.RemoveAll(this);
	USwipeDelegates::SwipeUpEndedDelegate.RemoveAll(this);

	USwipeDelegates::SwipeDownDelegate.RemoveAll(this);
	USwipeDelegates::SwipeDownEndedDelegate.RemoveAll(this);

	USwipeDelegates::SingleTapDelegate.RemoveAll(this);
	USwipeDelegates::DoubleTapDelegate.RemoveAll(this);
}
