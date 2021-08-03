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

	ADD_PROPERTY( univer::UVec4, color )
	ADD_PROPERTY( univer::UVec2, size )

private:
	univer::Sprite* m_sprite;
};
