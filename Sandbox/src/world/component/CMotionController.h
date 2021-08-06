#pragma once

#include "Component.h"

struct Displacement
{
	int goal;
	float current;
	bool enabled = false;
	bool completed = false;
	int direction = 0;
	void start( int displacement )
	{
		goal = displacement > 0 ? displacement : -displacement;
		direction = displacement > 0 ? 1 : -1;
		current = 0.f;
		enabled = true;
		completed = false;
	}
	void updateValue( float delta, float& value )
	{
		if ( enabled )
		{
			current += delta;
			if ( current > goal )
			{
				completed = true;
				enabled = false;
				delta = goal - ( current - delta );
			}
			value += delta * direction;
		}
	};
};

// Generic Motion Controller component.
class CMotionController : public Component
{
public:
	void moveVertically( int pixels );
	void moveHorizontally( int pixels );
	bool verticalMovementCompleted() const
	{
		return m_verticalDisplacement.completed;
	};
	bool horizontalMovementCompleted() const
	{
		return m_horizontalDisplacement.completed;
	};

	void update( float dt ) override;

private:
	Displacement m_verticalDisplacement;
	Displacement m_horizontalDisplacement;

	ADD_PROPERTY( float, speedX )
	ADD_PROPERTY( float, speedY )
};
