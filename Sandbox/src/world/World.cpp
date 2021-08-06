#include "World.h"

#include "Player.h"

World::World()
	: m_player{ std::make_shared<Player>() }
	, m_canvas{ nullptr }
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
	m_player->update( dt );
}

void World::onKeyPressedEvent( univer::KeyPressedEvent& e )
{
	m_player->onKeyPressedEvent( e );
}

void World::onKeyReleasedEvent( univer::KeyReleasedEvent& e )
{
	m_player->onKeyReleasedEvent( e );
}

void World::addActor( const std::shared_ptr<Actor>& actor )
{
	m_actors.push_back( actor );
}