#include "ISettingsModule.h"
#include "SwipeViewportClient.h"
#include "SwipeSettings.h"
#include "SwipeDelegates.h"

#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Engine/UserInterfaceSettings.h"

USwipeViewportClient::USwipeViewportClient() :
	SwipeSettings(GetDefault<USwipeSettings>())
{}

bool USwipeViewportClient::InputTouch(FViewport* InViewport,
	int32 ControllerId,
	uint32 Handle,
	ETouchType::Type Type,
	const FVector2D& TouchLocation,
	float Force,
	FDateTime DeviceTimestamp,
	uint32 TouchpadIndex)
{
	if (IgnoreInput())
	{
		return false;
	}

	switch (Type) 
	{
		case ETouchType::Began:
		{
			USwipeDelegates::TouchBeganDelegate.Broadcast(TouchLocation, Handle);

			SwipeStartLocation = TouchLocation;
			bSwiping = true;
			SwipeDirection = Swipe::Direction::None;

			break;
		}
		case ETouchType::Moved:
		{
			USwipeDelegates::TouchMovedDelegate.Broadcast(TouchLocation, Handle);
			CallSwipeDelegates(TouchLocation);
			break;
		}
		case ETouchType::Ended:
		{
			USwipeDelegates::TouchEndedDelegate.Broadcast(TouchLocation, Handle);
			bSwiping = false;
			if (SwipeDirection != Swipe::Direction::None)
			{
				CallSwipeEndedDelegates(TouchLocation);
				SwipeDirection = Swipe::Direction::None;
			}
			else
			{
				DetermineTapAmount(TouchLocation);
			}
		}
		default:
			break;
	}

	bool bResult = Super::InputTouch(InViewport, ControllerId, Handle, Type, TouchLocation, Force, DeviceTimestamp, TouchpadIndex);

	return bResult;
}

void USwipeViewportClient::CallSwipeDelegates(const FVector2D & TouchLocation)
{
	float MinSwipeDistance = SwipeSettings->MinSwipeDistance;
	if (SwipeSettings->EnableDPIScaling)
	{
		MinSwipeDistance *= GetDPIScreenScale();
	}

	if (bSwiping && SwipeDirection == Swipe::Direction::None)
	{
		const FVector2D TouchDelta = TouchLocation - SwipeStartLocation;
		const float AbsX = FMath::Abs(TouchDelta.X);
		const float AbsY = FMath::Abs(TouchDelta.Y);
		const bool XMeetsThreshold = (AbsX >= MinSwipeDistance);
		const bool YMeetsThreshold = (AbsY >= MinSwipeDistance);
		if (AbsX > AbsY && XMeetsThreshold)
		{
			SwipeTriggerLocation = TouchLocation;
			if (TouchDelta.X > 0)
			{
				USwipeDelegates::SwipeRightDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation);
				SwipeDirection = Swipe::Direction::Right;
			}
			else
			{
				USwipeDelegates::SwipeLeftDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation);
				SwipeDirection = Swipe::Direction::Left;
			}
		}
		else if (YMeetsThreshold)
		{
			SwipeTriggerLocation = TouchLocation;
			if (TouchDelta.Y > 0)
			{
				USwipeDelegates::SwipeDownDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation);
				SwipeDirection = Swipe::Direction::Down;
			}
			else
			{
				USwipeDelegates::SwipeUpDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation);
				SwipeDirection = Swipe::Direction::Up;
			}
		}
	}
}

void USwipeViewportClient::DetermineTapAmount(const FVector2D & TouchLocation)
{
	++TapCount;
	if (TapCount == 1)
	{
		USwipeDelegates::SingleTapDelegate.Broadcast(TouchLocation);
	}
	else if (TapCount >= 2)
	{
		USwipeDelegates::DoubleTapDelegate.Broadcast(TouchLocation);
	}
	FTimerHandle TapHandler;
	FTimerDelegate TapHandlerDelegate;
	TapHandlerDelegate.BindUObject(this, &USwipeViewportClient::ResetTapHandler);
	UWorld* World = GetWorld();
	if (World)
	{
		World->GetTimerManager().SetTimer(TapHandler, TapHandlerDelegate, SwipeSettings->MaxTimeBetweenTaps, false);
	}
}

void USwipeViewportClient::CallSwipeEndedDelegates(const FVector2D & TouchLocation)
{
	switch (SwipeDirection)
	{
	case Swipe::Direction::Right:
	{
		USwipeDelegates::SwipeRightEndedDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation, TouchLocation);
		break;
	}
	case Swipe::Direction::Left:
	{
		USwipeDelegates::SwipeLeftEndedDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation, TouchLocation);
		break;
	}
	case Swipe::Direction::Down:
	{
		USwipeDelegates::SwipeDownEndedDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation, TouchLocation);
		break;
	}
	case Swipe::Direction::Up:
	{
		USwipeDelegates::SwipeUpEndedDelegate.Broadcast(SwipeStartLocation, SwipeTriggerLocation, TouchLocation);
		break;
	}
	}
}

void USwipeViewportClient::ResetTapHandler()
{
	TapCount = 0;
}

float USwipeViewportClient::GetDPIScreenScale()
{
	if (GEngine->GameViewport)
	{
		const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
		const float ViewportScale = GetDefault<UUserInterfaceSettings>(UUserInterfaceSettings::StaticClass())->GetDPIScaleBasedOnSize(FIntPoint(ViewportSize.X, ViewportSize.Y));
		return ViewportScale;
	}
	else
	{
		return 1;
	}
}
