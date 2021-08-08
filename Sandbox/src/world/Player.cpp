#include "Player.h"
#include "component/CCollision.h"
#include "component/CInputManager.h"
#include "component/CPlayerMotionController.h"
#include "component/CPlayerStateMachine.h"
#include "component/CPosition.h"
#include "component/CSkin.h"
#include "data/Constants.h"

#include <univer/events/KeyEvent.h>

Player::Player()
{}

void Player::init()
{
	auto& mc = addComponent<CPlayerMotionController>();
	auto& position = addComponent<CPosition>();
	auto& skin = addComponent<CSkin>();
	auto& bounds = addComponent<CCollison>();
	auto& sm = addComponent<CPlayerStateMachine>();
	auto& im = addComponent<CInputManager>();

	// Setup components.
	mc->set_speedX( constants::PLAYER_SPEED_X );
	mc->set_speedY( constants::PLAYER_SPEED_Y );
	mc->set_horizontalLoopEnabled( true );
	position->set_x( 320 );
	position->set_y( 475 );
	skin->set_color( { 1, 0, 0, 1 } );
	skin->set_size( { 25, 40 } );
	skin->reset();
	skin->set_drawLast( true );
	bounds->set_bounds( univer::URectangle( -12.5f, -40.f, 25.f, 40.f ) );
	sm->init();
}

void Player::onKeyPressedEvent( univer::KeyPressedEvent& e )
{
	auto& im = getComponent<CInputManager>();
	im->processKeyInput( e.GetKeyCode(), true );
}

void Player::onKeyReleasedEvent( univer::KeyReleasedEvent& e )
{
	auto& im = getComponent<CInputManager>();
	im->processKeyInput( e.GetKeyCode(), false );
}
