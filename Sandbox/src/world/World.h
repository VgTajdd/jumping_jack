#pragma once

#include "Actor.h"
#include "Player.h"

#include <memory>
#include <vector>

// Class for actors, player and objects.
class World
{
public:
	explicit World()
		: m_player{ std::make_unique<Player>() } {};
	void update( float dt );
	void onKeyPressedEvent( univer::KeyPressedEvent& e );
	void onKeyReleasedEvent( univer::KeyReleasedEvent& e );

private:
	std::vector<Actor> m_actors;
	std::unique_ptr<Player> m_player;
};
