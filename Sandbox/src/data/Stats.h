#pragma once

namespace stats
{
struct Stats
{
	static int LEVEL;
	static int LIFES;
	static int SCORE;
	static int CURRENT_PLATFORM;

	static void resetStats();
	static void onNextLevel();
	static void completeJump();
	static void fall();
};

// static void getPlatformConstants()
//{}
} // namespace stats