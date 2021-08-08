#pragma once

#include "Constants.h"

namespace stats
{
struct Stats
{
	static int LEVEL /* = 1*/;
	static int LIFES /* = 1*/;
	static int SCORE /* = 0*/;
	static int CURRENT_PLATFORM /* = 0*/;

	static void resetStats()
	{
		Stats::LEVEL = 1;
		Stats::LIFES = constants::INITIAL_LIFES;
		Stats::SCORE = 0;
		Stats::CURRENT_PLATFORM = 0;
	}

	static void completeJump()
	{
		Stats::CURRENT_PLATFORM++;
		Stats::SCORE += constants::COMPLETE_JUMP_SCORE;
		if ( Stats::CURRENT_PLATFORM == constants::TOTAL_PLATFORMS )
		{
			// Next Level.
			Stats::LEVEL++;
		}
	}

	static void fall()
	{
		Stats::CURRENT_PLATFORM--;
		Stats::LIFES--;
		if ( Stats::LIFES == 0 )
		{
			// Game Over.
		}
	}
};
} // namespace stats