#include "Stats.h"
#include "Constants.h"
#include "scene/SceneManager.h"
#include "scene/SceneType.h"

#include "world/jj/JJWorld.h"

namespace stats
{
int Stats::LEVEL = 1;
int Stats::LIFES = 1;
int Stats::SCORE = 0;
int Stats::CURRENT_PLATFORM = 0;

void Stats::resetStats()
{
	Stats::LEVEL = 1;
	Stats::LIFES = constants::INITIAL_LIFES;
	Stats::SCORE = 0;
	Stats::CURRENT_PLATFORM = 0;
}

void Stats::onNextLevel()
{
	Stats::LEVEL++;
	Stats::CURRENT_PLATFORM = 0;
	if ( LEVEL > constants::TOTAL_LEVELS )
	{
		// Win Game.
		SceneManager::Get()->setNextScene( SCENE_TYPE::MAIN_MENU );
	}
	else
	{
		SceneManager::Get()->setNextScene( SCENE_TYPE::GAME );
	}
}

void Stats::completeJump()
{
	Stats::CURRENT_PLATFORM++;
	Stats::SCORE += constants::COMPLETE_JUMP_SCORE;
	JJWorld::Get()->setScore( SCORE );
	if ( Stats::CURRENT_PLATFORM > constants::TOTAL_PLATFORMS )
	{
		onNextLevel();
	}
}

void Stats::fall()
{
	Stats::CURRENT_PLATFORM--;
	Stats::LIFES--;
	JJWorld::Get()->setLifes( LIFES );
	if ( Stats::LIFES == 0 )
	{
		// Game Over.
		SceneManager::Get()->setNextScene( SCENE_TYPE::MAIN_MENU );
	}
}

} // namespace stats