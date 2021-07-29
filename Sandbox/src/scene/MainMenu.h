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
