#include "CMotionController.h"
#include "CPosition.h"

#include "world/Actor.h"

DEFINE_GET_COMPONENT_INSTANCE( CPosition )

void CMotionController::moveToLeft( bool on )
{
	if ( m_motionFactorX > 0 && !on ) return;
	m_motionFactorX = on ? -1 : 0;
}

void CMotionController::moveToRight( bool on )
{
	if ( m_motionFactorX < 0 && !on ) return;
	m_motionFactorX = on ? 1 : 0;
}

void CMotionController::jump( bool on )
{
	m_motionFactorX = 0;
	m_inJump = on;
}

void CMotionController::update( float dt )
{
	auto& position{ GET_COMPONENT_INSTANCE( CPosition ) };

	float newX = position->x() + m_motionFactorX * m_speedX * dt;
	float newY = position->y();
	if ( m_inJump ) newY -= m_speedY * dt;

	// End-of-screen logic.
	if ( newX > 640 && m_motionFactorX > 0 )
	{
		newX -= 640;
	}
	else if ( newX < 0 && m_motionFactorX < 0 )
	{
		newX += 640;
	}

	position->set_x( newX );
	position->set_y( newY );
}
