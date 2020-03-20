//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "UObject/Object.h"
#include "UObject/ScriptMacros.h"
#include "SwipeDelegates.generated.h"

UCLASS(NotBlueprintable)
class USwipeDelegates : public UObject
{
	GENERATED_BODY()

public:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FTouchDelegate, FVector2D, int32);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FSwipeTriggeredDelegate, FVector2D, FVector2D);
	DECLARE_MULTICAST_DELEGATE_ThreeParams(FSwipeEndedDelegate, FVector2D, FVector2D, FVector2D);
	DECLARE_MULTICAST_DELEGATE_OneParam(FTapDelegate, FVector2D);

	static FTouchDelegate TouchBeganDelegate;
	static FTouchDelegate TouchMovedDelegate;
	static FTouchDelegate TouchEndedDelegate;

	static FSwipeTriggeredDelegate SwipeLeftDelegate;
	static FSwipeEndedDelegate SwipeLeftEndedDelegate;

	static FSwipeTriggeredDelegate SwipeRightDelegate;
	static FSwipeEndedDelegate SwipeRightEndedDelegate;

	static FSwipeTriggeredDelegate SwipeUpDelegate;
	static FSwipeEndedDelegate SwipeUpEndedDelegate;

	static FSwipeTriggeredDelegate SwipeDownDelegate;
	static FSwipeEndedDelegate SwipeDownEndedDelegate;

	static FTapDelegate SingleTapDelegate;
	static FTapDelegate DoubleTapDelegate;
};
