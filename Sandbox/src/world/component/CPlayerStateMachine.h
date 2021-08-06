#pragma once

#include "CStateMachine.h"

// Player's behavior manager.
class CPlayerStateMachine : public CStateMachine
{
	void stand();
	void walk();
	void jump();
	void fall();
	bool verticalMovementCompleted();

public:
	void init() override;

	ADD_PROPERTY( bool, moveToLeftEnabled )
	ADD_PROPERTY( bool, moveToRightEnabled )
	ADD_PROPERTY( bool, jumpEnabled )
	ADD_PROPERTY( bool, fallEnabled )
	ADD_PROPERTY( bool, flipEnabled )
};
