#include "Hole.h"

#include "data/Constants.h"
#include "world/component/CMotionController.h"
#include "world/component/CPosition.h"
#include "world/component/CSkin.h"

Hole::Hole( float speedX, int platformLevel )
	: m_speedX{ speedX }
	, m_platformLevel{ platformLevel }
{}

void Hole::init()
{
	auto& mc = addComponent<CMotionController>();
	auto& position = addComponent<CPosition>();
	auto& skin = addComponent<CSkin>();

	mc->set_speedX( m_speedX < 0 ? -m_speedX : m_speedX );
	mc->set_speedY( 0 );
	position->set_y( (float)constants::getPlatformHeight( m_platformLevel ) );

	float startX = -( (float)( constants::HOLE_WIDHT / 2 ) + 10 );
	int displacementX = constants::HOLE_WIDHT + constants::SCREEN_WIDTH + 20;
	position->set_x( m_speedX < 0 ? constants::SCREEN_WIDTH + ( constants::HOLE_WIDHT / 2 ) + 10 : startX );
	mc->moveHorizontally( m_speedX < 0 ? -displacementX : displacementX );

	skin->set_color( { 1, 1, 1, 1 } );
	skin->set_size( { constants::HOLE_WIDHT, 5 } );
	skin->reset();
}
