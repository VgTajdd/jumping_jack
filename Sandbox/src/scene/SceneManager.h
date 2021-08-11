// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// SceneManager.h                                                            //
// ========================================================================= //

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
	void gotoScene( SCENE_TYPE type );

public:
	explicit SceneManager();
	void update( univer::Timestep ts );
	void setLayer( univer::Layer* layer );
	void clear();
	void init();
	void onKeyPressedEvent( univer::KeyPressedEvent& e );
	void onKeyReleasedEvent( univer::KeyReleasedEvent& e );
	void setNextScene( SCENE_TYPE type );

private:
	class Scene* m_currentScene;
	univer::Sprite* m_canvas;
	univer::Layer* m_layer;
	SCENE_TYPE m_nextScene;
};

inline void SceneManager::setLayer( univer::Layer* layer )
{
	m_layer = layer;
}
