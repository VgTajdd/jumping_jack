#pragma once

#include "CStateMachine.h"

class CPlayerStateMachine : public CStateMachine
{
public:
	void init();
	void stand();
	void walk();

public:
	// External interaction (events).
	void moveToLeft( bool on );
	void moveToRight( bool off );
	void jump();

private:
	bool m_flip = false;

	ADD_PROPERTY( bool, moveToLeftEnabled )
	ADD_PROPERTY( bool, moveToRightEnabled )
	ADD_PROPERTY( bool, jumpEnabled )
};