// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Hole.h                                                                    //
// ========================================================================= //

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
