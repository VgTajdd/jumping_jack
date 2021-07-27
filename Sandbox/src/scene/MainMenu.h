#pragma once

#include "Scene.h"

class MainMenu : public Scene
{
public:
	explicit MainMenu();
	void init();
	void update( float dt );
};
