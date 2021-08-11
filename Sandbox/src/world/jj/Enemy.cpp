// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Enemy.cpp                                                                 //
// ========================================================================= //

#include "Enemy.h"
#include "data/Constants.h"
#include "world/component/CCollision.h"
#include "world/component/CMotionController.h"
#include "world/component/CPosition.h"
#include "world/component/CSkin.h"

Enemy::Enemy( float speedX, int platformLevel )
	: m_speedX{ speedX }
	, m_platformLevel{ platformLevel }
{}

void Enemy::init()
{
	auto& collision{ addComponent<CCollision>() };
	auto& mc{ addComponent<CMotionController>() };
	auto& position{ addComponent<CPosition>() };
	auto& skin{ addComponent<CSkin>() };

	// Setup components.
	float startPosition{ -20.f };
	float speed{ m_speedX > 0 ? m_speedX : -m_speedX };
	int displacement{ constants::SCREEN_WIDTH + 40 };
	position->set_y( (float)constants::getPlatformHeight( m_platformLevel ) - 10 );
	position->set_x( m_speedX > 0 ? startPosition : startPosition + displacement );
	mc->set_speedX( speed );
	mc->set_speedY( 0 );
	mc->moveHorizontally( m_speedX < 0 ? -displacement : displacement );
	skin->set_color( { 1, .2f, .2f, 1 } );
	skin->set_size( { 30, 30 } );
	skin->reset();
	collision->set_bounds( univer::URectangle( { -15.f, -30.f }, { 30.f, 30.f } ) );
}
