//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "SwipePrivatePCH.h"

USwipeDelegates::FTouchDelegate USwipeDelegates::TouchBeganDelegate;
USwipeDelegates::FTouchDelegate USwipeDelegates::TouchMovedDelegate;
USwipeDelegates::FTouchDelegate USwipeDelegates::TouchEndedDelegate;

USwipeDelegates::FSwipeTriggeredDelegate USwipeDelegates::SwipeLeftDelegate;
USwipeDelegates::FSwipeEndedDelegate USwipeDelegates::SwipeLeftEndedDelegate;

USwipeDelegates::FSwipeTriggeredDelegate USwipeDelegates::SwipeRightDelegate;
USwipeDelegates::FSwipeEndedDelegate USwipeDelegates::SwipeRightEndedDelegate;

USwipeDelegates::FSwipeTriggeredDelegate USwipeDelegates::SwipeUpDelegate;
USwipeDelegates::FSwipeEndedDelegate USwipeDelegates::SwipeUpEndedDelegate;

USwipeDelegates::FSwipeTriggeredDelegate USwipeDelegates::SwipeDownDelegate;
USwipeDelegates::FSwipeEndedDelegate USwipeDelegates::SwipeDownEndedDelegate;

USwipeDelegates::FTapDelegate USwipeDelegates::SingleTapDelegate;
USwipeDelegates::FTapDelegate USwipeDelegates::DoubleTapDelegate;
