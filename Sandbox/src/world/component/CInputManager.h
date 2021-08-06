#pragma once

#include "Component.h"

#include <univer/constants/KeyCodes.h>

// Component for input management.
class CInputManager : public Component
{
	void moveToLeft( bool on );
	void moveToRight( bool on );
	void tryJump();

public:
	void processKeyInput( const univer::KeyCode& keyCode, bool pressed );
};
