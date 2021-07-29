#include "SceneManager.h"
#include "Scene.h"
#include "SceneFactory.h"
#include "SceneType.h"

#include <Univer.h>
#include <univer/renderables/2d/Sprite.h>

using univer::Sprite;

SceneManager* SceneManager::Get()
{
	static SceneManager instance;
	return &instance;
}

SceneManager::SceneManager()
	: m_currentScene( nullptr )
	, m_canvas( nullptr )
	, m_layer( nullptr )
{}

void SceneManager::gotoScene( SCENE_TYPE type )
{
	if ( m_currentScene != nullptr ) delete m_currentScene;
	m_currentScene = ::scene_factory::Create( type );
	if ( m_currentScene != nullptr )
	{
		m_currentScene->setCanvas( m_canvas );
		m_currentScene->init();
	}
}

void SceneManager::update( univer::Timestep ts )
{
	if ( m_currentScene )
	{
		m_currentScene->update( ts );
	}
}

void SceneManager::clear()
{
	if ( m_currentScene != nullptr ) delete m_currentScene;

	m_layer->remove( m_canvas );
	delete m_canvas;
	m_canvas = nullptr;
}

void SceneManager::init()
{
	if ( m_layer == nullptr ) UVR_ERROR( "Set a layer before init SceneManager." );

	m_canvas = new Sprite( 0, 0, 640, 480 );
	m_canvas->setColor( 1, 1, 1 );
	m_layer->add( m_canvas );
}