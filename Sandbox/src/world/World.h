#pragma once

#include "Actor.h"
#include "Player.h"

#include <memory>
#include <vector>

namespace univer
{
class KeyPressedEvent;
class KeyReleasedEvent;
} // namespace univer

// Class for actors, player and objects.
class World : public std::enable_shared_from_this<World>
{
public:
	explicit World();
	void init();
	void update( float dt );
	void onKeyPressedEvent( univer::KeyPressedEvent& e );
	void onKeyReleasedEvent( univer::KeyReleasedEvent& e );

private:
	std::vector<std::shared_ptr<Actor>> m_actors;
	std::shared_ptr<Player> m_player;
};
