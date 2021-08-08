#include "CPlayerStateMachine.h"
#include "CPlayerMotionController.h"
#include "CPosition.h"
#include "CSkin.h"
#include "CSoundManager.h"
#include "data/Constants.h"
#include "data/Stats.h"
#include "world/Actor.h"

#include <univer/core/Log.h>

void CPlayerStateMachine::init()
{
	set_inCrash( false );
	set_inFloor( false );
	set_evaluateJump( false );
	set_crashEnabled( false );
	set_fallEnabled( false );
	set_flipEnabled( false );
	set_jumpEnabled( false );
	set_moveToLeftEnabled( false );
	set_moveToRightEnabled( false );
	set_state( states::ST_STAND );
	stand();

	// Walk-Stand
	addEdge(
		states::ST_STAND, states::ST_WALK, [this]() { return moveToRightEnabled() || moveToLeftEnabled(); },
		[this]() { walk(); } );
	addEdge(
		states::ST_WALK, states::ST_STAND,
		[this]() { return !moveToRightEnabled() && !moveToLeftEnabled() && !jumpEnabled(); }, [this]() { stand(); } );
	addEdge(
		states::ST_WALK, states::ST_WALK, [this]() { return flipEnabled(); }, [this]() { walk(); } );

	// Jump.
	addEdge(
		states::ST_WALK, states::ST_JUMPING, [this]() { return jumpEnabled(); }, [this]() { jump(); } );
	addEdge(
		states::ST_STAND, states::ST_JUMPING, [this]() { return jumpEnabled(); }, [this]() { jump(); } );
	addEdge(
		states::ST_JUMPING, states::ST_STAND, [this] { return verticalMovementCompleted(); }, [this]() { endjump(); } );

	// Crash.
	addEdge(
		states::ST_JUMPING, states::ST_CRASH, [this]() { return crashEnabled(); }, [this]() { crash(); } );
	addEdge(
		states::ST_CRASH, states::ST_IN_FLOOR, [this]() { return !inCrash(); }, [this]() { toFloor(); } );
	addEdge(
		states::ST_IN_FLOOR, states::ST_FALLING, [this]() { return fallEnabled(); }, [this]() { fall(); } );
	addEdge(
		states::ST_IN_FLOOR, states::ST_STAND, [this]() { return !inFloor(); }, [this]() { stand(); } );

	// Fall.
	addEdge(
		states::ST_WALK, states::ST_FALLING, [this]() { return fallEnabled(); }, [this]() { fall(); } );
	addEdge(
		states::ST_STAND, states::ST_FALLING, [this]() { return fallEnabled(); }, [this]() { fall(); } );
	addEdge(
		states::ST_FALLING, states::ST_IN_FLOOR, [this] { return verticalMovementCompleted(); },
		[this]() { toFloor(); } );
}

void CPlayerStateMachine::update( float dt )
{
	CStateMachine::update( dt );
	if ( inFloor() && m_timer > 0 )
	{
		m_timer -= dt;
		if ( m_timer <= 0 ) set_inFloor( false );
	}
	if ( inCrash() && m_timer > 0 )
	{
		m_timer -= dt;
		if ( m_timer <= 0 ) endCrash();
	}
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
	auto& skin{ GET_COMPONENT_INSTANCE( CSkin ) };
	skin->set_color( constants::ST_WALK_COLOR );
}

void CPlayerStateMachine::stand()
{
	set_jumpEnabled( false );
	auto& mc{ GET_COMPONENT_INSTANCE( CPlayerMotionController ) };
	mc->moveToLeft( false );
	mc->moveToRight( false );
	UVR_INFO( "Stand" );
	auto& skin{ GET_COMPONENT_INSTANCE( CSkin ) };
	skin->set_color( constants::ST_STAND_COLOR );
}

void CPlayerStateMachine::jump()
{
	set_evaluateJump( true );
	auto& mc{ GET_COMPONENT_INSTANCE( CPlayerMotionController ) };
	mc->moveToLeft( false );
	mc->moveToRight( false );
	mc->moveVertically( -55 );
	UVR_INFO( "Jump" );
	auto& skin{ GET_COMPONENT_INSTANCE( CSkin ) };
	skin->set_color( constants::ST_JUMP_COLOR );
}

void CPlayerStateMachine::endjump()
{
	stand();
	stats::Stats::completeJump();
}

void CPlayerStateMachine::fall()
{
	set_inFloor( false );
	auto& mc{ GET_COMPONENT_INSTANCE( CPlayerMotionController ) };
	mc->moveToLeft( false );
	mc->moveToRight( false );
	mc->moveVertically( 55 );
	stats::Stats::fall();
	UVR_INFO( "Fall" );
	auto& skin{ GET_COMPONENT_INSTANCE( CSkin ) };
	skin->set_color( constants::ST_CRASH_COLOR );
}

void CPlayerStateMachine::crash()
{
	m_timer = .15f;
	set_inCrash( true );
	set_crashEnabled( false );
	set_evaluateJump( false );
	auto& mc{ GET_COMPONENT_INSTANCE( CPlayerMotionController ) };
	mc->stop();
	UVR_INFO( "Crash!" );

	auto& sound{ GET_COMPONENT_INSTANCE( CSoundManager ) };
	sound->playSound( "assets/sandbox/sounds/bonk.wav", 1 );

	auto& skin{ GET_COMPONENT_INSTANCE( CSkin ) };
	skin->set_color( constants::ST_CRASH_COLOR );
}

void CPlayerStateMachine::toFloor()
{
	UVR_INFO( "ToFloor" );
	set_inFloor( true );
	set_fallEnabled( false );
	m_timer = 1.f;
	auto& skin{ GET_COMPONENT_INSTANCE( CSkin ) };
	skin->set_color( constants::ST_CRASH_COLOR );
}

void CPlayerStateMachine::endCrash()
{
	set_inCrash( false );
	auto& position{ GET_COMPONENT_INSTANCE( CPosition ) };
	position->set_y( constants::getPlatformHeight( stats::Stats::CURRENT_PLATFORM ) - 5.f );
	stand();
}

bool CPlayerStateMachine::verticalMovementCompleted()
{
	auto& mc{ GET_COMPONENT_INSTANCE( CPlayerMotionController ) };
	return mc->verticalMovementCompleted();
}
