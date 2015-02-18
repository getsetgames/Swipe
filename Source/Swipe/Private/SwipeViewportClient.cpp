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
			SwipeStartLocation = TouchLocation;
			
			UE_LOG(LogSwipe, Log, TEXT("Swipe began: %f %f"), TouchLocation.X, TouchLocation.Y);
			
			break;
		}
		case ETouchType::Moved:
		{
			UE_LOG(LogSwipe, Log, TEXT("Swiping"));
			break;
		}
		case ETouchType::Ended:
		{
			FVector2D TouchDelta = TouchLocation - SwipeStartLocation;
			
			FString SwipeDirection = TEXT("No Direction");
			
			if (FMath::Abs(TouchDelta.X) > FMath::Abs(TouchDelta.Y)) {
				// swipe is horizontal
				if (TouchDelta.X > 0) {
					// swipe is right
					SwipeDirection = TEXT("Right");
				}
				else {
					// swipe is left
					SwipeDirection = TEXT("Left");
				}
			}
			else {
				// swipe is vertical
				if (TouchDelta.Y > 0) {
					// swipe is down
					SwipeDirection = TEXT("Down");
				}
				else {
					// swipe is up
					SwipeDirection = TEXT("Up");
				}
			}
			
			UE_LOG(LogSwipe, Log, TEXT("Swipe ended: %f %f, delta: %f %f, direction: %s"), TouchLocation.X, TouchLocation.Y, TouchDelta.X, TouchDelta.Y, *SwipeDirection);
			
			break;
		}
		default:
			break;
	}
	
	bool bResult = UGameViewportClient::InputTouch(InViewport, ControllerId, Handle, Type, TouchLocation, DeviceTimestamp, TouchpadIndex);

	return bResult;
}