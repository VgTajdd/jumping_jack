#pragma once

namespace constants
{
// Game constants.
const unsigned int TOTAL_LEVELS = 15;
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

static unsigned int getPlatformHeight( int platformLevel )
{
	return PLAYER_START_Y - platformLevel * PLATFORM_SEPARATION + 5;
}
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
