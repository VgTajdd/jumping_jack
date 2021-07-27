#pragma once

namespace univer
{
class Layer;
class Timestep;
class Sprite;
} // namespace univer

enum class SCENE_TYPE;

class SceneManager
{
public:
	explicit SceneManager( univer::Layer* layer );
	void update( univer::Timestep ts );
	void gotoScene( SCENE_TYPE type );
	void clear();

public:
	class Scene* m_currentScene;
	univer::Sprite* m_canvas;
	univer::Layer* m_layer;
};