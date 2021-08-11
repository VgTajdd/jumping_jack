// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// CInputManager.h                                                           //
// ========================================================================= //

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
