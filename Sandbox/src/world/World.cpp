#include "World.h"

#include "Player.h"

World::World()
	: m_player{ std::make_shared<Player>() }
{}

void World::init()
{
	m_player->setWorld( shared_from_this() );
	m_player->init();
}

void World::update( float dt )
{
	for ( auto& actor : m_actors )
	{
		actor->update( dt );
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