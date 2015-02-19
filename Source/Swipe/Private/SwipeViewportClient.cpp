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
			break;
		}
		case ETouchType::Ended:
		{
			FVector2D TouchDelta = TouchLocation - SwipeStartLocation;
			const USwipeSettings* SwipeSettings = GetDefault<USwipeSettings>();
			float AbsX = FMath::Abs(TouchDelta.X);
			float AbsY = FMath::Abs(TouchDelta.Y);
			bool XMeetsThreshold = (AbsX >= SwipeSettings->MinSwipeDistance);
			bool YMeetsThreshold = (AbsY >= SwipeSettings->MinSwipeDistance);
			
			if (AbsX > AbsY && XMeetsThreshold) {
				if (TouchDelta.X > 0) {
					USwipeComponent::SwipeRightDelegate.Broadcast();
				}
				else {
					USwipeComponent::SwipeLeftDelegate.Broadcast();
				}
			}
			else if (YMeetsThreshold) {
				if (TouchDelta.Y > 0) {
					USwipeComponent::SwipeDownDelegate.Broadcast();
				}
				else {
					USwipeComponent::SwipeUpDelegate.Broadcast();
				}
			}

			break;
		}
		default:
			break;
	}
	
	bool bResult = UGameViewportClient::InputTouch(InViewport, ControllerId, Handle, Type, TouchLocation, DeviceTimestamp, TouchpadIndex);

	return bResult;
}