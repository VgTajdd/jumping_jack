#pragma once

#include "Component.h"

struct Displacement
{
	int goal;
	float current;
	bool enabled;
	void start( int _goal )
	{
		goal = _goal;
		current = 0.f;
		enabled = true;
	}
};

class CMotionController : public Component
{
public:
	void moveToLeft( bool on );
	void moveToRight( bool on );
	void moveVertically( int pixels );
	bool verticalMovementCompleted() const
	{
		return m_verticalMovementCompleted;
	};

	void update( float dt );

private:
	int m_motionFactorX = 0;
	int m_motionFactorY = 0;
	bool m_verticalMovementCompleted = false;
	Displacement m_verticalDisplacement;

	ADD_PROPERTY( float, speedX )
	ADD_PROPERTY( float, speedY )
};
