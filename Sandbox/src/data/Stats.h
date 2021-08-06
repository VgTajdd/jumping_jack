#pragma once

#include "Constants.h"

namespace stats
{
static int LEVEL = 1;
static int LIFES = 1;
static int SCORE = 0;
static int CURRENT_PLATFORM = 0;

void resetStats()
{
	LEVEL = 1;
	LIFES = constants::INITIAL_LIFES;
	SCORE = 0;
	CURRENT_PLATFORM = 0;
}
} // namespace stats