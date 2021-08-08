#include "CPlayerMotionController.h"
#include "CPosition.h"

#include "data/Constants.h"
#include "world/Actor.h"

void CPlayerMotionController::moveToLeft( bool on )
{
	m_motionFactorX = on ? -1 : 0;
}

void CPlayerMotionController::moveToRight( bool on )
{
	m_motionFactorX = on ? 1 : 0;
}

void CPlayerMotionController::update( float dt )
{
	CMotionController::update( dt );

	auto& position{ GET_COMPONENT_INSTANCE( CPosition ) };
	float newX = position->x() + m_motionFactorX * speedX() * dt;
	if ( m_horizontalLoopEnabled )
	{
		// End-of-screen logic.
		if ( newX > constants::SCREEN_WIDTH && m_motionFactorX > 0 )
		{
			newX -= constants::SCREEN_WIDTH;
		}
		else if ( newX < 0 && m_motionFactorX < 0 )
		{
			newX += constants::SCREEN_WIDTH;
		}
	}
	position->set_x( newX );
}
