#include "Player.h"
#include "data/Constants.h"

#include "component/CCollision.h"
#include "component/CMotionController.h"
#include "component/CPlayerStateMachine.h"
#include "component/CPosition.h"
#include "component/CSkin.h"

#include <univer/events/KeyEvent.h>

Player::Player()
{}

void Player::init()
{
	auto& mc = addComponent<CMotionController>();
	auto& position = addComponent<CPosition>();
	auto& skin = addComponent<CSkin>();
	auto& bounds = addComponent<CCollison>();
	auto& sm = addComponent<CPlayerStateMachine>();

	// Setup components.
	mc->set_speedX( constants::PLAYER_SPEED_X );
	mc->set_speedY( constants::PLAYER_SPEED_Y );
	position->set_x( 320 );
	position->set_y( 475 );
	skin->set_color( { 1, 0, 0, 1 } );
	skin->set_size( { 25, 40 } );
	skin->reset();
	bounds->set_bounds( univer::URectangle( -12.5f, -40.f, 25.f, 40.f ) );
	sm->init();
}

void Player::update( float dt )
{
	auto& sm{ getComponent<CPlayerStateMachine>() };
	auto& mc{ getComponent<CMotionController>() };
	auto& skin{ getComponent<CSkin>() };

	sm->update( dt );
	mc->update( dt );
	skin->update( dt );
}

void Player::onKeyPressedEvent( univer::KeyPressedEvent& e )
{
	processKeyInput( e.GetKeyCode(), true );
}

void Player::onKeyReleasedEvent( univer::KeyReleasedEvent& e )
{
	processKeyInput( e.GetKeyCode(), false );
}

void Player::processKeyInput( const univer::KeyCode& keyCode, bool pressed )
{
	auto& sm = getComponent<CPlayerStateMachine>();
	switch ( keyCode )
	{
		case univer::KeyCode::Left:
		case univer::KeyCode::A:
			sm->moveToLeft( pressed );
			break;
		case univer::KeyCode::Right:
		case univer::KeyCode::D:
			sm->moveToRight( pressed );
			break;
		case univer::KeyCode::Up:
		case univer::KeyCode::W:
			if ( pressed ) sm->tryJump();
			break;
	}
}
