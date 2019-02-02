//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "Engine/GameViewportClient.h"
#include "SwipeViewportClient.generated.h"

UENUM(BlueprintType)
namespace Swipe
{
	enum Direction
	{
		None,
		Left,
		Right,
		Up,
		Down
	};
}

UCLASS()
class USwipeViewportClient : public UGameViewportClient
{
	GENERATED_BODY()

public:
	USwipeViewportClient();
	virtual bool InputTouch(FViewport* Viewport,
		int32 ControllerId,
		uint32 Handle,
		ETouchType::Type Type,
		const FVector2D& TouchLocation,
		float Force,
		FDateTime DeviceTimestamp,
		uint32 TouchpadIndex) override;

private:
	bool bSwiping;
	Swipe::Direction SwipeDirection;
	FVector2D SwipeStartLocation;
	FVector2D SwipeTriggerLocation;
	int32 TapCount = 0;
	const class USwipeSettings* SwipeSettings;

	void CallSwipeDelegates(const FVector2D & TouchLocation);
	void DetermineTapAmount(const FVector2D & TouchLocation);
	void CallSwipeEndedDelegates(const FVector2D & TouchLocation);

	UFUNCTION()
	void ResetTapHandler();

	float GetDPIScreenScale();
};
