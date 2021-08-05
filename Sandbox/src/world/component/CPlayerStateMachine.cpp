#include "CPlayerStateMachine.h"
#include "CMotionController.h"

#include <univer/core/Log.h>

#include "world/Actor.h"

DEFINE_GET_COMPONENT_INSTANCE( CMotionController )

void CPlayerStateMachine::init()
{
	set_state( states::ST_STAND );
	addEdge(
		states::ST_STAND, states::ST_WALK, [this]() { return moveToRightEnabled() || moveToLeftEnabled(); },
		[this]() { walk(); } );
	addEdge(
		states::ST_WALK, states::ST_STAND, [this]() { return !moveToRightEnabled() && !moveToLeftEnabled(); },
		[this]() { stand(); } );
	addEdge(
		states::ST_WALK, states::ST_WALK, [this]() { return m_flip; }, [this]() { walk(); } );
	addEdge(
		states::ST_WALK, states::ST_JUMPING, [this]() { return jumpEnabled(); }, [this]() { jump(); } );
	addEdge(
		states::ST_STAND, states::ST_JUMPING, [this]() { return jumpEnabled(); }, [this]() { jump(); } );
	addEdge(
		states::ST_JUMPING, states::ST_STAND, [this] { return verticalMovementCompleted(); }, [this]() { stand(); } );
}

void CPlayerStateMachine::walk()
{
	auto& mc{ GET_COMPONENT_INSTANCE( CMotionController ) };
	mc->moveToLeft( false );
	mc->moveToRight( false );
	if ( moveToLeftEnabled() ) mc->moveToLeft( true );
	if ( moveToRightEnabled() ) mc->moveToRight( true );
	m_flip = false;
}

void CPlayerStateMachine::stand()
{
	set_jumpEnabled( false );
	auto& mc{ GET_COMPONENT_INSTANCE( CMotionController ) };
	mc->moveToLeft( false );
	mc->moveToRight( false );
}

void CPlayerStateMachine::moveToLeft( bool on )
{
	if ( moveToRightEnabled() && !on ) return;
	set_moveToLeftEnabled( on );
	if ( moveToRightEnabled() )
	{
		set_moveToRightEnabled( false );
		m_flip = true;
	}
}

void CPlayerStateMachine::moveToRight( bool on )
{
	if ( moveToLeftEnabled() && !on ) return;
	set_moveToRightEnabled( on );
	if ( moveToLeftEnabled() )
	{
		set_moveToLeftEnabled( false );
		m_flip = true;
	}
}

void CPlayerStateMachine::tryJump()
{
	set_moveToLeftEnabled( false );
	set_moveToRightEnabled( false );
	set_jumpEnabled( true );
}

void CPlayerStateMachine::jump()
{
	auto& mc{ GET_COMPONENT_INSTANCE( CMotionController ) };
	mc->moveToLeft( false );
	mc->moveToRight( false );
	mc->moveVertically( -55 );
}

void CPlayerStateMachine::fall()
{
	auto& mc{ GET_COMPONENT_INSTANCE( CMotionController ) };
	mc->moveToLeft( false );
	mc->moveToRight( false );
	mc->moveVertically( 55 );
}

bool CPlayerStateMachine::verticalMovementCompleted()
{
	auto& mc{ GET_COMPONENT_INSTANCE( CMotionController ) };
	return mc->verticalMovementCompleted();
}