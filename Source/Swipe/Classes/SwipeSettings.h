//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "SwipeSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class USwipeSettings : public UObject
{
	GENERATED_BODY()
	
public:
	USwipeSettings(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(Config, EditAnywhere, Category=General, meta=(DisplayName="Minimum Swipe Distance"))
	float MinSwipeDistance;
};
