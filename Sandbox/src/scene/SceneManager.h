#pragma once

namespace univer
{
class Layer;
class Timestep;
class Sprite;
class KeyPressedEvent;
class KeyReleasedEvent;
} // namespace univer

enum class SCENE_TYPE;

class SceneManager
{
public:
	static SceneManager* Get();

public:
	explicit SceneManager();
	void update( univer::Timestep ts );
	void setLayer( univer::Layer* layer );
	void gotoScene( SCENE_TYPE type );
	void clear();
	void init();
	void onKeyPressedEvent( univer::KeyPressedEvent& e );
	void onKeyReleasedEvent( univer::KeyReleasedEvent& e );

private:
	class Scene* m_currentScene;
	univer::Sprite* m_canvas;
	univer::Layer* m_layer;
};

inline void SceneManager::setLayer( univer::Layer* layer )
{
	m_layer = layer;
}
