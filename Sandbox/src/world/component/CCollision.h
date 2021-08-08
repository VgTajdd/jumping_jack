#pragma once

#include "Component.h"

#include <univer/core/URectangle.h>

class CCollision : public Component
{
	ADD_PROPERTY( univer::URectangle, bounds )
};
