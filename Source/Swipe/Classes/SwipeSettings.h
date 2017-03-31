//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "UObject/Object.h"
#include "UObject/ScriptMacros.h"
#include "SwipeSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class USwipeSettings : public UObject
{
	GENERATED_BODY()

public:
	USwipeSettings(const FObjectInitializer& ObjectInitializer);

	// Minimum Swipe Distance
	UPROPERTY(Config, EditAnywhere, Category = General, meta = (DisplayName = "Minimum Swipe Distance"))
	float MinSwipeDistance;

	// Maximum Time Between Taps To Register Double Tap
	UPROPERTY(Config, EditAnywhere, Category = General, meta = (DisplayName = "Maximum Time Between Taps"))
	float MaxTimeBetweenTaps;

	// Enable DPI Scaling to handle high density resolutions
	UPROPERTY(Config, EditAnywhere, Category = General, meta = (DisplayName = "Enable DPI Scaling"))
	bool EnableDPIScaling;
};
