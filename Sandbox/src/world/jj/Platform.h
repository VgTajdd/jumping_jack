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
