//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "UObject/Object.h"
#include "Engine/GameViewportClient.h"
#include "SwipeViewportClient.generated.h"

UENUM(BlueprintType)
namespace Swipe {
	enum Direction {
		None,
		Left,
		Right,
		Up,
		Down
	};
}

UCLASS()
class USwipeViewportClient : public UGameViewportClient {
	GENERATED_BODY()

public:
	/*
	virtual bool InputTouch(FViewport* Viewport, 
	int32 ControllerId, 
	uint32 Handle, 
	ETouchType::Type Type, 
	const FVector2D& TouchLocation, 
	float Force, 
	FDateTime DeviceTimestamp, 
	uint32 TouchpadIndex) override;


	virtual bool InputTouch
(
    FViewport * Viewport,
    int32 ControllerId,
    uint32 Handle,
    ETouchType::Type Type,
    const FVector2D & TouchLocation,
    float Force,
    FDateTime DeviceTimestamp,
    uint32 TouchpadIndex
)
	*/
	virtual bool InputTouch(FViewport* InViewport,
		int32 ControllerId,
		uint32 Handle,
		ETouchType::Type Type,
		const FVector2D& TouchLocation,
		float Force,
		FDateTime DeviceTimestamp,
		uint32 TouchpadIndex) override;
	/*bool InputTouch(FViewport* Viewport,
		int32 ControllerId,
		uint32 Handle,
		ETouchType::Type Type,
		const FVector2D& TouchLocation,
		FDateTime DeviceTimestamp,
		uint32 TouchpadIndex) override;*/

private:
	bool bSwiping;
	Swipe::Direction SwipeDirection;
	FVector2D SwipeStartLocation;
	FVector2D SwipeTriggerLocation;
	int32 TapCount = 0;

	UFUNCTION()
	void ResetTapHandler();

	float GetDPIScreenScale();
};
