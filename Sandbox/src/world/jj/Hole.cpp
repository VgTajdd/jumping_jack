// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Hole.cpp                                                                  //
// ========================================================================= //

#include "Hole.h"

#include "data/Constants.h"
#include "data/Stats.h"
#include "world/component/CCollision.h"
#include "world/component/CMotionController.h"
#include "world/component/CPosition.h"
#include "world/component/CSkin.h"

Hole::Hole( float speedX, int platformLevel )
	: m_speedX{ speedX }
	, m_platformLevel{ platformLevel }
{}

void Hole::init()
{
	auto& mc{ addComponent<CMotionController>() };
	auto& position{ addComponent<CPosition>() };
	auto& skin{ addComponent<CSkin>() };
	auto& collision{ addComponent<CCollision>() };

	mc->set_speedX( m_speedX < 0 ? -m_speedX : m_speedX );
	mc->set_speedY( 0 );
	position->set_y( (float)constants::getPlatformHeight( m_platformLevel ) );
	float startX = -( (float)( constants::HOLE_WIDHT / 2 ) + 10 );
	int displacementX = constants::HOLE_WIDHT + constants::SCREEN_WIDTH + 20;
	position->set_x( m_speedX < 0 ? constants::SCREEN_WIDTH + ( constants::HOLE_WIDHT / 2 ) + 10 : startX );
	mc->moveHorizontally( m_speedX < 0 ? -displacementX : displacementX );

	skin->set_color( constants::getLevelColor( stats::Stats::LEVEL ) );
	skin->set_size( { constants::HOLE_WIDHT, 5 } );
	skin->reset();

	collision->set_bounds(
		univer::URectangle( { -( constants::HOLE_WIDHT / 2.f ), -10 }, { constants::HOLE_WIDHT, 10 } ) );
}
