#pragma once

#include "Actor.h"

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
	void init() override;
	void onKeyPressedEvent( univer::KeyPressedEvent& e );
	void onKeyReleasedEvent( univer::KeyReleasedEvent& e );
};
