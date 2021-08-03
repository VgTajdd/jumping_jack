#pragma once

#include "Component.h"

class CPosition : public Component
{
	ADD_PROPERTY( float, x )
	ADD_PROPERTY( float, y )
};
