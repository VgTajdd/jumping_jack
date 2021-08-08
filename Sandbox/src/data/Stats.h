#pragma once

#include "Constants.h"

#include "scene/SceneManager.h"
#include "scene/SceneType.h"

namespace stats
{
struct Stats
{
	static int LEVEL;
	static int LIFES;
	static int SCORE;
	static int CURRENT_PLATFORM;

	static void resetStats()
	{
		Stats::LEVEL = 1;
		Stats::LIFES = constants::INITIAL_LIFES;
		Stats::SCORE = 0;
		Stats::CURRENT_PLATFORM = 0;
	}

	static void onNextLevel()
	{
		Stats::LEVEL++;
		Stats::CURRENT_PLATFORM = 0;
		SceneManager::Get()->setNextScene( SCENE_TYPE::GAME );
	}

	static void completeJump()
	{
		Stats::CURRENT_PLATFORM++;
		Stats::SCORE += constants::COMPLETE_JUMP_SCORE;
		if ( Stats::CURRENT_PLATFORM == constants::TOTAL_PLATFORMS )
		{
			onNextLevel();
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