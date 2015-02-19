//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "SwipeViewportClient.generated.h"

UCLASS()
class USwipeViewportClient : public UGameViewportClient {
	GENERATED_BODY()
	
public:
	virtual bool InputTouch(FViewport* Viewport,
							int32 ControllerId,
							uint32 Handle,
							ETouchType::Type Type,
							const FVector2D& TouchLocation,
							FDateTime DeviceTimestamp,
							uint32 TouchpadIndex) override;
	
private:
	bool bSwiping;
	bool bSwipeTriggered;
	FVector2D SwipeStartLocation;
};