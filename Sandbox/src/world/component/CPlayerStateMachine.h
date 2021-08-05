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
	void moveToLeft( bool on );
	void moveToRight( bool off );
	void tryJump();

private:
	bool m_flip = false;

	ADD_PROPERTY( bool, moveToLeftEnabled )
	ADD_PROPERTY( bool, moveToRightEnabled )
	ADD_PROPERTY( bool, jumpEnabled )
	ADD_PROPERTY( bool, fallEnabled )
};
