#include "CMotionController.h"
#include "CPosition.h"

#include "world/Actor.h"

DEFINE_GET_COMPONENT_INSTANCE( CPosition )

void CMotionController::moveToLeft( bool on )
{
	m_motionFactorX = on ? -1 : 0;
}

void CMotionController::moveToRight( bool on )
{
	m_motionFactorX = on ? 1 : 0;
}

void CMotionController::moveVertically( int pixels )
{
	m_verticalDisplacement.start( pixels > 0 ? pixels : -pixels );
	m_motionFactorY = pixels > 0 ? 1 : -1;
	m_verticalMovementCompleted = false;
}

void CMotionController::update( float dt )
{
	auto& position{ GET_COMPONENT_INSTANCE( CPosition ) };

	// Update x.
	float newX = position->x() + m_motionFactorX * m_speedX * dt;

	// End-of-screen logic.
	if ( newX > 640 && m_motionFactorX > 0 )
	{
		newX -= 640;
	}
	else if ( newX < 0 && m_motionFactorX < 0 )
	{
		newX += 640;
	}

	// Update y.
	float newY = position->y();

	if ( m_verticalDisplacement.enabled )
	{
		float deltaY = m_speedY * dt;
		m_verticalDisplacement.current += deltaY;
		if ( m_verticalDisplacement.current >= m_verticalDisplacement.goal )
		{
			m_verticalMovementCompleted = true;
			m_verticalDisplacement.enabled = false;
			deltaY = m_verticalDisplacement.goal - ( m_verticalDisplacement.current - deltaY );
		}
		newY += deltaY * m_motionFactorY;
	}

	// Save new values.
	position->set_x( newX );
	position->set_y( newY );
}
