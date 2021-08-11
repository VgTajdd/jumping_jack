// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// CSkin.h                                                                   //
// ========================================================================= //

#pragma once

#include "Component.h"

#include <univer/core/UTypes.h>

namespace univer
{
class Sprite;
} // namespace univer

// Simple single-color skin.
class CSkin : public Component
{
public:
	~CSkin();
	void clear();
	void reset();
	void update( float dt );
	univer::Sprite* sprite();

private:
	univer::Sprite* m_sprite;

	ADD_PROPERTY( univer::UVec4, color )
	ADD_PROPERTY( univer::UVec2, size )
	ADD_PROPERTY( bool, drawLast )
};

inline univer::Sprite* CSkin::sprite()
{
	return m_sprite;
}
