// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Stats.h                                                                   //
// ========================================================================= //

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