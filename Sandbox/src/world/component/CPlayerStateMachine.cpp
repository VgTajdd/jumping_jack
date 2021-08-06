#include "CPlayerStateMachine.h"
#include "CPlayerMotionController.h"

#include <univer/core/Log.h>

#include "world/Actor.h"

DEFINE_GET_COMPONENT_INSTANCE( CPlayerMotionController )

void CPlayerStateMachine::init()
{
	set_fallEnabled( false );
	set_flipEnabled( false );
	set_jumpEnabled( false );
	set_moveToLeftEnabled( false );
	set_moveToRightEnabled( false );
	set_state( states::ST_STAND );
	addEdge(
		states::ST_STAND, states::ST_WALK, [this]() { return moveToRightEnabled() || moveToLeftEnabled(); },
		[this]() { walk(); } );
	addEdge(
		states::ST_WALK, states::ST_STAND,
		[this]() { return !moveToRightEnabled() && !moveToLeftEnabled() && !jumpEnabled(); }, [this]() { stand(); } );
	addEdge(
		states::ST_WALK, states::ST_WALK, [this]() { return flipEnabled(); }, [this]() { walk(); } );
	addEdge(
		states::ST_WALK, states::ST_JUMPING, [this]() { return jumpEnabled(); }, [this]() { jump(); } );
	addEdge(
		states::ST_STAND, states::ST_JUMPING, [this]() { return jumpEnabled(); }, [this]() { jump(); } );
	addEdge(
		states::ST_JUMPING, states::ST_STAND, [this] { return verticalMovementCompleted(); }, [this]() { stand(); } );
}

void CPlayerStateMachine::walk()
{
	auto& mc{ GET_COMPONENT_INSTANCE( CPlayerMotionController ) };
	mc->moveToLeft( false );
	mc->moveToRight( false );
	if ( moveToLeftEnabled() ) mc->moveToLeft( true );
	if ( moveToRightEnabled() ) mc->moveToRight( true );
	m_flipEnabled = false;
	UVR_INFO( "Walk" );
}

void CPlayerStateMachine::stand()
{
	set_jumpEnabled( false );
	auto& mc{ GET_COMPONENT_INSTANCE( CPlayerMotionController ) };
	mc->moveToLeft( false );
	mc->moveToRight( false );
	UVR_INFO( "Stand" );
}

void CPlayerStateMachine::jump()
{
	auto& mc{ GET_COMPONENT_INSTANCE( CPlayerMotionController ) };
	mc->moveToLeft( false );
	mc->moveToRight( false );
	mc->moveVertically( -55 );
	UVR_INFO( "Jump" );
}

void CPlayerStateMachine::fall()
{
	auto& mc{ GET_COMPONENT_INSTANCE( CPlayerMotionController ) };
	mc->moveToLeft( false );
	mc->moveToRight( false );
	mc->moveVertically( 55 );
	UVR_INFO( "Fall" );
}

bool CPlayerStateMachine::verticalMovementCompleted()
{
	auto& mc{ GET_COMPONENT_INSTANCE( CPlayerMotionController ) };
	return mc->verticalMovementCompleted();
}