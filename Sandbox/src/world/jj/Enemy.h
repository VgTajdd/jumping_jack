#pragma once

#include "world/Actor.h"

class Enemy : public Actor
{
public:
	explicit Enemy( float speedX, int platformLevel );
	void init() override;

private:
	float m_speedX;
	int m_platformLevel;
};
