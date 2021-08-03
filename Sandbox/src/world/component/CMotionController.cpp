#include "CMotionController.h"
#include "CPosition.h"

#include "world/Actor.h"

DEFINE_GET_COMPONENT_INSTANCE( CPosition )

void CMotionController::moveToLeft( bool on )
{
	m_motionFactor = on ? -1 : 0;
}

void CMotionController::moveToRight( bool on )
{
	m_motionFactor = on ? 1 : 0;
}

void CMotionController::goUp()
{
	m_motionFactor = 0;
}

void CMotionController::update( float dt )
{
	auto& position = GET_COMPONENT_INSTANCE( CPosition );
	position->set_x( position->x() + m_motionFactor * m_speedX );
}