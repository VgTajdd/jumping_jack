#pragma once

#include "Actor.h"
#include "Player.h"

#include <memory>
#include <vector>

namespace univer
{
class KeyPressedEvent;
class KeyReleasedEvent;
class Sprite;
} // namespace univer

// Class for actors, player and objects.
class World : public std::enable_shared_from_this<World>
{
public:
	explicit World();
	void init();
	void setCanvas( univer::Sprite* canvas );
	void update( float dt );
	void onKeyPressedEvent( univer::KeyPressedEvent& e );
	void onKeyReleasedEvent( univer::KeyReleasedEvent& e );

	univer::Sprite* canvas() const;

private:
	std::vector<std::shared_ptr<Actor>> m_actors;
	std::shared_ptr<Player> m_player;
	univer::Sprite* m_canvas;
};

inline void World::setCanvas( univer::Sprite* canvas )
{
	m_canvas = canvas;
}

inline univer::Sprite* World::canvas() const
{
	return m_canvas;
}
