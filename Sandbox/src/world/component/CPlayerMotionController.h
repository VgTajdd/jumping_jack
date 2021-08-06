#pragma once

#include "CMotionController.h"

// Player's Motion Controller Component
class CPlayerMotionController : public CMotionController
{
public:
	void moveToLeft( bool on );
	void moveToRight( bool on );
	void update( float dt ) override;

private:
	int m_motionFactorX = 0;

	ADD_PROPERTY( bool, horizontalLoopEnabled )
};
