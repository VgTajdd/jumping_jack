#include "CMotionController.h"
#include "CPosition.h"

#include "data/Constants.h"
#include "world/Actor.h"

DEFINE_GET_COMPONENT_INSTANCE( CPosition )

void CMotionController::moveVertically( int pixels )
{
	m_verticalDisplacement.start( pixels );
}

void CMotionController::moveHorizontally( int pixels )
{
	m_horizontalDisplacement.start( pixels );
}

void CMotionController::update( float dt )
{
	auto& position{ GET_COMPONENT_INSTANCE( CPosition ) };

	float newX = position->x();
	float newY = position->y();
	m_horizontalDisplacement.updateValue( m_speedX * dt, newX );
	m_verticalDisplacement.updateValue( m_speedY * dt, newY );

	position->set_x( newX );
	position->set_y( newY );
}
