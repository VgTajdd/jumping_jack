// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// CPlayerStateMachine.h                                                     //
// ========================================================================= //

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
	void endCrash();
	bool verticalMovementCompleted();

private:
	float m_timer;

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
	ADD_PROPERTY( bool, inCrash )

	ADD_PROPERTY( bool, collideWithEnemy )
};
