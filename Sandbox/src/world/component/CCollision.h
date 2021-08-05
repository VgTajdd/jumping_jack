#pragma once

#include "Component.h"

#include <univer/core/URectangle.h>

class CCollison : public Component
{
	ADD_PROPERTY( univer::URectangle, bounds )
};
