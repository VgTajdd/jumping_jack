#include "CSkin.h"
#include "CPosition.h"

#include "world/Actor.h"
#include "world/World.h"

#include <univer/renderables/2d/Sprite.h>

DEFINE_GET_COMPONENT_INSTANCE( CPosition )

CSkin::~CSkin()
{
	clear();
}

void CSkin::clear()
{
	univer::Sprite* canvas = nullptr;
	if ( !actor()->world().expired() ) canvas = actor()->world().lock()->canvas();

	if ( m_sprite != nullptr )
	{
		if ( canvas != nullptr )
		{
			canvas->removeChild( m_sprite, true );
		}
		else
		{
			delete m_sprite;
		}
		m_sprite = nullptr;
	}
}

void CSkin::reset()
{
	clear();

	univer::Sprite* canvas = nullptr;
	if ( !actor()->world().expired() ) canvas = actor()->world().lock()->canvas();

	if ( canvas != nullptr )
	{
		m_sprite = new univer::Sprite();
		m_sprite->setColor( m_color );
		m_sprite->setSize( m_size );
		canvas->addChild( m_sprite );
	}
}

void CSkin::update( float dt )
{
	auto& position = GET_COMPONENT_INSTANCE( CPosition );

	if ( m_sprite != nullptr )
	{
		m_sprite->setPosition( position->x(), position->y() );
	}
}