#pragma once

#include "Component.h"

class CMotionController : public Component
{
public:
	void moveToLeft( bool on );
	void moveToRight( bool on );
	void jump( bool on );
	void update( float dt );

private:
	int m_motionFactorX = 0;
	bool m_inJump = false;

	ADD_PROPERTY( float, speedX )
	ADD_PROPERTY( float, speedY )
};
