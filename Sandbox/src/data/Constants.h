// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Constants.h                                                               //
// ========================================================================= //

#pragma once

#include <univer/core/UTypes.h>

namespace constants
{
// Game constants.
const unsigned int TOTAL_LEVELS = 20;
const unsigned int INITIAL_LIFES = 6;
const unsigned int TOTAL_PLATFORMS = 8;
const unsigned int COMPLETE_JUMP_SCORE = 5;

// Player constants.
const unsigned int PLAYER_SPEED_X = 200; // px/sec
const unsigned int PLAYER_SPEED_Y = 150; // px/sec
const unsigned int PLAYER_START_X = 320; // pixels
const unsigned int PLAYER_START_Y = 475; // pixels

// Game constants.
const unsigned int SCREEN_WIDTH = 640;		 // pixels
const unsigned int SCREEN_HEIGHT = 480;		 // pixels
const unsigned int PLATFORM_SEPARATION = 55; // pixels
const unsigned int HOLE_WIDHT = 80;			 // pixels

const univer::UVec4 LEVEL_COLOR_01{ .8f, .8f, 1.f, 1.f };
const univer::UVec4 LEVEL_COLOR_02{ .8f, 1.f, 1.f, 1.f };
const univer::UVec4 LEVEL_COLOR_03{ 1.f, .8f, 1.f, 1.f };
const univer::UVec4 LEVEL_COLOR_04{ 1.f, 1.f, .8f, 1.f };

static unsigned int getPlatformHeight( int platformLevel )
{
	return PLAYER_START_Y - platformLevel * PLATFORM_SEPARATION + 5;
}

static const univer::UVec4 getLevelColor( int level )
{
	int levelColor{ level % 4 };
	switch ( levelColor )
	{
		case 1:
			return LEVEL_COLOR_01;
		case 2:
			return LEVEL_COLOR_02;
		case 3:
			return LEVEL_COLOR_03;
		case 4:
			return LEVEL_COLOR_04;
	}
	return LEVEL_COLOR_01;
}
const univer::UVec4 ST_STAND_COLOR{ .2f, .2f, .2f, 1.f };
const univer::UVec4 ST_WALK_COLOR{ .4f, .4f, .4f, 1.f };
const univer::UVec4 ST_JUMP_COLOR{ .1f, .5f, .1f, 1.f };
const univer::UVec4 ST_CRASH_COLOR{ .5f, .1f, .1f, 1.f };
} // namespace constants

namespace states
{
// Player states.
const int ST_STAND = 1;
const int ST_WALK = 2;
const int ST_JUMPING = 3;
const int ST_CRASH = 4;
const int ST_FALLING = 5;
const int ST_IN_FLOOR = 6;
} // namespace states
