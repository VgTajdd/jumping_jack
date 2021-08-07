#pragma once

#include "world/Actor.h"

class Hole : public Actor
{
public:
	explicit Hole( float speedX, int platformLevel );
	void init() override;

private:
	float m_speedX;
	int m_platformLevel;
};
