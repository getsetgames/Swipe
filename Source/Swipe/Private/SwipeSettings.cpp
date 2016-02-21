//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "SwipePrivatePCH.h"

USwipeSettings::USwipeSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, MinSwipeDistance(50.0f)
	, MaxTimeBetweenTaps(0.3f)
	, EnableDPIScaling(true)
{
}
