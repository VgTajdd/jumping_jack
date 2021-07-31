#pragma once

#include "Scene.h"
#include <world/World.h>

#include <memory>

namespace univer
{
class KeyPressedEvent;
class KeyReleasedEvent;
} // namespace univer

class GameScene : public Scene
{
public:
	explicit GameScene();
	~GameScene();
	void init();
	void update( float dt );
	void onKeyPressedEvent( univer::KeyPressedEvent& e );
	void onKeyReleasedEvent( univer::KeyReleasedEvent& e );

private:
	std::shared_ptr<World> m_world;
};
