// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// World.h                                                                   //
// ========================================================================= //

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
	void removeActor( size_t indexInBuffer );

public:
	explicit World();
	virtual ~World(){};
	virtual void init();
	virtual void clear();
	void setCanvas( univer::Sprite* canvas );
	void update( float dt );
	void onKeyPressedEvent( univer::KeyPressedEvent& e );
	void onKeyReleasedEvent( univer::KeyReleasedEvent& e );
	void addActor( const std::shared_ptr<Actor>& actor );

	const std::shared_ptr<Player>& player() const;
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

inline const std::shared_ptr<Player>& World::player() const
{
	return m_player;
}
