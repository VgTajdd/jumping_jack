// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// World.cpp                                                                 //
// ========================================================================= //

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

void World::clear()
{
	for ( const auto& actor : m_actors )
	{
		actor->clearComponents();
	}
	m_actors.clear();
	m_player->clearComponents();
	m_player.reset();
	m_canvas = nullptr;
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
	size_t temp = 0;
	std::for_each( toRemove.begin(), toRemove.end(), [this, &temp]( size_t i ) {
		i = i - temp;
		removeActor( i );
		temp++;
	} );
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
	actor->setWorld( shared_from_this() );
	actor->init();
}

void World::removeActor( size_t indexInBuffer )
{
	m_actors[indexInBuffer]->clearComponents();
	m_actors[indexInBuffer].reset();
	m_actors.erase( m_actors.begin() + indexInBuffer );
}
