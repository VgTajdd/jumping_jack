// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// MainMenu.h                                                                //
// ========================================================================= //

#pragma once

#include "Scene.h"

class MainMenu : public Scene
{
public:
	explicit MainMenu();
	~MainMenu();
	void init();
	void update( float dt );

private:
	univer::Sprite* m_blinkBackground;
	float m_timeElapsed;
	float m_timer;
};
