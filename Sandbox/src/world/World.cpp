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
	std::vector<size_t> toRemove;
	for ( size_t i = 0; i < m_actors.size(); i++ )
	{
		if ( !m_actors[i]->valid() )
		{
			toRemove.push_back( i );
			continue;
		}
		m_actors[i]->update( dt );
	}
	std::for_each( toRemove.begin(), toRemove.end(), [this]( size_t i ) { m_actors.erase( m_actors.begin() + i ); } );
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