#include "CPlatform.h"
#include "Hole.h"
#include "data/Constants.h"
#include "world/World.h"
#include "world/component/CMotionController.h"

#include <univer/utils/Random.h>

void CPlatform::update( float dt )
{
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
