#include "CPlayerStateMachine.h"
#include "CMotionController.h"

#include <univer/core/Log.h>

#include "world/Actor.h"

DEFINE_GET_COMPONENT_INSTANCE( CMotionController )

void CPlayerStateMachine::init()
{
	set_state( states::ST_STAND );
	addCondition(
		states::ST_STAND, states::ST_WALK, [this]() { return moveToRightEnabled() || moveToLeftEnabled(); },
		[this]() { walk(); } );
	addCondition(
		states::ST_WALK, states::ST_STAND, [this]() { return !moveToRightEnabled() && !moveToLeftEnabled(); },
		[this]() { stand(); } );
	addCondition(
		states::ST_WALK, states::ST_WALK, [this]() { return m_flip; }, [this]() { walk(); } );
}

void CPlayerStateMachine::walk()
{
	auto& sm{ GET_COMPONENT_INSTANCE( CMotionController ) };
	sm->moveToLeft( false );
	sm->moveToRight( false );
	if ( moveToLeftEnabled() ) sm->moveToLeft( true );
	if ( moveToRightEnabled() ) sm->moveToRight( true );
	m_flip = false;
}

void CPlayerStateMachine::stand()
{
	auto& sm{ GET_COMPONENT_INSTANCE( CMotionController ) };
	sm->moveToLeft( false );
	sm->moveToRight( false );
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

void CPlayerStateMachine::jump()
{}
