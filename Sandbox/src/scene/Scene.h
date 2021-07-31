#pragma once

namespace univer
{
class Sprite;
class KeyPressedEvent;
class KeyReleasedEvent;
} // namespace univer

enum class SCENE_TYPE;

// Abstract class for scenes.
class Scene
{
public:
	virtual ~Scene(){};
	virtual void init() = 0;
	virtual void update( float dt ) = 0;
	void setCanvas( univer::Sprite* canvas );
	virtual void onKeyPressedEvent( univer::KeyPressedEvent& e ){};
	virtual void onKeyReleasedEvent( univer::KeyReleasedEvent& e ){};

protected:
	univer::Sprite* m_canvas;
	SCENE_TYPE m_type;
};

inline void Scene::setCanvas( univer::Sprite* canvas )
{
	m_canvas = canvas;
}
