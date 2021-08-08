#include "CPlatform.h"
#include "Hole.h"
#include "data/Constants.h"
#include "data/Stats.h"
#include "world/World.h"
#include "world/component/CCollision.h"
#include "world/component/CMotionController.h"
#include "world/component/CPlayerStateMachine.h"
#include "world/component/CPosition.h"

#include <univer/core/Log.h>
#include <univer/core/URectangle.h>
#include <univer/utils/Random.h>

void CPlatform::update( float dt )
{
	// Create holes.
	m_time += dt;
	if ( m_time >= evaluationTime() )
	{
		float randomValue1{ univer::Random::GetInstance().value() };
		if ( m_holes.empty() && randomValue1 < probFirstHole() ||
			 m_holes.size() == 1 && randomValue1 < probSecondHole() )
		{
			float randomValue2{ univer::Random::GetInstance().value() };
			float speed{ constants::PLAYER_SPEED_X };
			createHole( randomValue2 > 0.5 ? speed : -speed, level() );
			set_evaluationTime( 1.f + randomValue2 );
		}
		m_time = 0;
	}

	// Remove holes.
	for ( size_t i = 0; i < m_holes.size(); i++ )
	{
		if ( m_holes[i].expired() )
		{
			m_holes.erase( m_holes.begin() + i );
			i--;
			continue;
		}

		if ( !m_holes[i].expired() &&
			 m_holes[i].lock()->getComponent<CMotionController>()->horizontalMovementCompleted() )
		{
			m_holes[i].lock()->setValid( false );
			m_holes.erase( m_holes.begin() + i );
			i--;
		}
	}

	// Jump/Fall logic.
	if ( stats::Stats::CURRENT_PLATFORM + 1 == m_level || stats::Stats::CURRENT_PLATFORM == m_level )
	{
		const auto& world{ actor().lock()->world().lock() };
		auto& p_collision{ world->player()->getComponent<CCollision>() };
		auto& p_position{ world->player()->getComponent<CPosition>() };
		auto& sm{ world->player()->getComponent<CPlayerStateMachine>() };
		auto p_bounds{ univer::URectangle::move( p_collision->bounds(), { p_position->x(), p_position->y() } ) };

		auto& pl_collision{ actor().lock()->getComponent<CCollision>() };
		bool collidedWithPlatform{ false };
		size_t passedHoles{ 0 };

		if ( stats::Stats::CURRENT_PLATFORM + 1 == m_level && sm->evaluateJump() )
		{
			auto& pl_bounds{ pl_collision->bounds() };
			if ( pl_bounds.intersetcts( p_bounds ) )
			{
				collidedWithPlatform = true;
			}
		}

		for ( size_t i = 0; i < m_holes.size(); i++ )
		{
			auto& collision{ m_holes[i].lock()->getComponent<CCollision>() };
			auto& position{ m_holes[i].lock()->getComponent<CPosition>() };
			auto bounds{ univer::URectangle::move( collision->bounds(), { position->x(), position->y() } ) };

			if ( stats::Stats::CURRENT_PLATFORM + 1 == m_level )
			{
				if ( collidedWithPlatform )
				{
					if ( bounds.intersetcts( p_bounds ) )
					{
						univer::UVec2 p1{ p_bounds.left(), p_bounds.top() };
						univer::UVec2 p2{ p_bounds.right(), p_bounds.top() };
						if ( bounds.contains( p1 ) && bounds.contains( p2 ) )
						{
							passedHoles++;
							break;
						}
					}
				}
			}
			else
			{
				if ( bounds.intersetcts( p_bounds ) )
				{
					UVR_TRACE( "Fall Collision!" );
					univer::UVec2 p1{ p_bounds.left(), p_bounds.bottom() };
					univer::UVec2 p2{ p_bounds.right(), p_bounds.bottom() };
					if ( bounds.contains( p1 ) && bounds.contains( p2 ) )
					{
						sm->set_fallEnabled( true );
					}
				}
			}
		}

		if ( sm->evaluateJump() )
		{
			if ( collidedWithPlatform )
			{
				if ( passedHoles > 0 )
				{
					UVR_TRACE( "Successful Jump!" );
					sm->set_evaluateJump( false );
				}
				else
				{
					UVR_TRACE( "Crash!" );
					sm->set_crashEnabled( true );
				}
			}
		}
	}
}

void CPlatform::createHole( float speedX, int platformLevel )
{
	auto hole{ std::make_shared<Hole>( speedX, platformLevel ) };
	if ( !actor().expired() && !actor().lock()->world().expired() )
	{
		const auto& world = actor().lock()->world().lock();
		world->addActor( hole );
	}
	m_holes.emplace_back( hole );
}
