#pragma once

#include "Scene.h"

class GameScene : public Scene
{
public:
	explicit GameScene();
	void init();
	void update( float dt );
};