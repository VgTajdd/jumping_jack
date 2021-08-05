#pragma once

#include "CStateMachine.h"

// Player's behavior system.
class CPlayerStateMachine : public CStateMachine
{
	void stand();
	void walk();

public:
	void init() override;
	void moveToLeft( bool on );
	void moveToRight( bool off );
	void jump();

private:
	bool m_flip = false;

	ADD_PROPERTY( bool, moveToLeftEnabled )
	ADD_PROPERTY( bool, moveToRightEnabled )
	ADD_PROPERTY( bool, jumpEnabled )
};
