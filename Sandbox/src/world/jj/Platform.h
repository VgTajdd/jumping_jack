// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Platform.h                                                                //
// ========================================================================= //

#pragma once

#include "world/Actor.h"

class Platform : public Actor
{
public:
	explicit Platform( int level )
		: m_level{ level } {};
	void init() override;

private:
	int m_level;
};
