#include "World.h"

void World::update( float dt )
{
	for ( auto& actor : m_actors )
	{
		actor.update( dt );
	}
}

void World::onKeyPressedEvent( univer::KeyPressedEvent& e )
{
	m_player->onKeyPressedEvent( e );
}

void World::onKeyReleasedEvent( univer::KeyReleasedEvent& e )
{
	m_player->onKeyReleasedEvent( e );
}