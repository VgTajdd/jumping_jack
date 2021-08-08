#pragma once

#include "CStateMachine.h"

// Player's behavior manager.
class CPlayerStateMachine : public CStateMachine
{
	void stand();
	void walk();
	void jump();
	void endjump();
	void fall();
	void crash();
	void toFloor();
	bool verticalMovementCompleted();

private:
	float m_inFloorTimer;

public:
	void init() override;
	void update( float dt ) override;

	ADD_PROPERTY( bool, moveToLeftEnabled )
	ADD_PROPERTY( bool, moveToRightEnabled )
	ADD_PROPERTY( bool, jumpEnabled )
	ADD_PROPERTY( bool, fallEnabled )
	ADD_PROPERTY( bool, flipEnabled )

	ADD_PROPERTY( bool, evaluateJump )
	ADD_PROPERTY( bool, crashEnabled )

	ADD_PROPERTY( bool, inFloor )
};
