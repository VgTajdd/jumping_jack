#include "CInputManager.h"
#include "CPlayerStateMachine.h"
#include "world/Actor.h"

void CInputManager::processKeyInput( const univer::KeyCode& keyCode, bool pressed )
{
	switch ( keyCode )
	{
		case univer::KeyCode::Left:
		case univer::KeyCode::A:
			moveToLeft( pressed );
			break;
		case univer::KeyCode::Right:
		case univer::KeyCode::D:
			moveToRight( pressed );
			break;
		case univer::KeyCode::Up:
		case univer::KeyCode::W:
			if ( pressed ) tryJump();
			break;
	}
}

void CInputManager::moveToLeft( bool on )
{
	auto& sm{ GET_COMPONENT_INSTANCE( CPlayerStateMachine ) };
	if ( sm->moveToLeftEnabled() && on ) return;
	if ( sm->moveToRightEnabled() && !on ) return;
	sm->set_moveToLeftEnabled( on );
	if ( sm->moveToRightEnabled() )
	{
		sm->set_moveToRightEnabled( false );
		sm->set_flipEnabled( true );
	}
}

void CInputManager::moveToRight( bool on )
{
	auto& sm{ GET_COMPONENT_INSTANCE( CPlayerStateMachine ) };
	if ( sm->moveToRightEnabled() && on ) return;
	if ( sm->moveToLeftEnabled() && !on ) return;
	sm->set_moveToRightEnabled( on );
	if ( sm->moveToLeftEnabled() )
	{
		sm->set_moveToLeftEnabled( false );
		sm->set_flipEnabled( true );
	}
}

void CInputManager::tryJump()
{
	auto& sm{ GET_COMPONENT_INSTANCE( CPlayerStateMachine ) };
	sm->set_moveToLeftEnabled( false );
	sm->set_moveToRightEnabled( false );
	sm->set_jumpEnabled( true );
}
