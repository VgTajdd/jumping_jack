#pragma once

namespace constants
{
// Game constants.
const int TOTAL_LEVELS = 15;
const int INITIAL_LIFES = 6;
const int TOTAL_PLATFORMS = 8;
const int COMPLETE_JUMP_SCORE = 5;

// Player constants.
const float PLAYER_SPEED_X = 300; // px/sec
const float PLAYER_SPEED_Y = 150; // px/sec
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