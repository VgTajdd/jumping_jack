#pragma once

#include "Actor.h"

#include <univer/constants/KeyCodes.h>

namespace univer
{
class KeyPressedEvent;
class KeyReleasedEvent;
} // namespace univer

// Class for main Player (Jack).
class Player : public Actor
{
public:
	explicit Player();
	void init();
	void update( float dt );
	void onKeyPressedEvent( univer::KeyPressedEvent& e );
	void onKeyReleasedEvent( univer::KeyReleasedEvent& e );

private:
	void processKeyInput( const univer::KeyCode& keyCode, bool pressed );
};
