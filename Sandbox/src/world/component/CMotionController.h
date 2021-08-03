#pragma once

#include "Component.h"

class CMotionController : public Component
{
public:
	void moveToLeft( bool on );
	void moveToRight( bool on );
	void goUp();
	void update( float dt );

private:
	int m_motionFactor = 0;

	ADD_PROPERTY( float, speedX )
	ADD_PROPERTY( float, speedY )
};
