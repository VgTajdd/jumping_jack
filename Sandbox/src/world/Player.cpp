#include "Player.h"

#include "component/CMotionController.h"
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

	// Setup components.
	mc->set_speedX( 10 );
	position->set_x( 200 );
	position->set_y( 200 );
	skin->set_color( { 1, 1, 0, 1 } );
	skin->set_size( { 50, 50 } );
	skin->reset();
}

void Player::update( float dt )
{
	auto& mc = getComponent<CMotionController>();
	auto& skin = getComponent<CSkin>();

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
	auto& mc = getComponent<CMotionController>();
	switch ( keyCode )
	{
		case univer::KeyCode::Left:
		case univer::KeyCode::A:
			mc->moveToLeft( pressed );
			break;
		case univer::KeyCode::Right:
		case univer::KeyCode::D:
			mc->moveToRight( pressed );
			break;
		case univer::KeyCode::Up:
		case univer::KeyCode::W:
			if ( pressed ) mc->goUp();
			break;
	}
}
