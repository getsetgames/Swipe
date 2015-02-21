//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "SwipePrivatePCH.h"

bool USwipeViewportClient::InputTouch(FViewport* InViewport,
									  int32 ControllerId,
									  uint32 Handle,
									  ETouchType::Type Type,
									  const FVector2D& TouchLocation,
									  FDateTime DeviceTimestamp,
									  uint32 TouchpadIndex)
{
	if (IgnoreInput())
	{
		return false;
	}
	
	switch (Type) {
		case ETouchType::Began:
		{
			USwipeComponent::TouchBeganDelegate.Broadcast(TouchLocation);

			SwipeStartLocation = TouchLocation;
			bSwiping = true;
			SwipeDirection = Swipe::Direction::None;
			break;
		}
		case ETouchType::Moved:
		{
			USwipeComponent::TouchMovedDelegate.Broadcast(TouchLocation);

			if (bSwiping && SwipeDirection == Swipe::Direction::None) {
				FVector2D TouchDelta = TouchLocation - SwipeStartLocation;
				const USwipeSettings* SwipeSettings = GetDefault<USwipeSettings>();
				float AbsX = FMath::Abs(TouchDelta.X);
				float AbsY = FMath::Abs(TouchDelta.Y);
				bool XMeetsThreshold = (AbsX >= SwipeSettings->MinSwipeDistance);
				bool YMeetsThreshold = (AbsY >= SwipeSettings->MinSwipeDistance);
				
				if (AbsX > AbsY && XMeetsThreshold) {
					SwipeTriggerLocation = TouchLocation;
					if (TouchDelta.X > 0) {
						USwipeComponent::SwipeRightDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation);
						SwipeDirection = Swipe::Direction::Right;
					}
					else {
						USwipeComponent::SwipeLeftDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation);
						SwipeDirection = Swipe::Direction::Left;
					}
				}
				else if (YMeetsThreshold) {
					SwipeTriggerLocation = TouchLocation;
					if (TouchDelta.Y > 0) {
						USwipeComponent::SwipeDownDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation);
						SwipeDirection = Swipe::Direction::Down;
					}
					else {
						USwipeComponent::SwipeUpDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation);
						SwipeDirection = Swipe::Direction::Up;
					}
				}
			}
			
			break;
		}
		case ETouchType::Ended:
		{
			USwipeComponent::TouchEndedDelegate.Broadcast(TouchLocation);

			bSwiping = false;
			
			switch (SwipeDirection) {
				case Swipe::Direction::Right:
				{
					USwipeComponent::SwipeRightEndedDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation, TouchLocation);
					break;
				}
				case Swipe::Direction::Left:
				{
					USwipeComponent::SwipeLeftEndedDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation, TouchLocation);
					break;
				}
				case Swipe::Direction::Down:
				{
					USwipeComponent::SwipeDownEndedDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation, TouchLocation);
					break;
				}
				case Swipe::Direction::Up:
				{
					USwipeComponent::SwipeUpEndedDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation, TouchLocation);
					break;
				}
				default:
					break;
			}
			
			SwipeDirection = Swipe::Direction::None;
		}
		default:
			break;
	}
	
	bool bResult = Super::InputTouch(InViewport, ControllerId, Handle, Type, TouchLocation, DeviceTimestamp, TouchpadIndex);

	return bResult;
}