#include "GameContext.h"
#include "scene/SceneManager.h"
#include "scene/SceneType.h"

#include <Univer.h>

using univer::Sprite;

GameContext::GameContext()
{}

GameContext::~GameContext()
{}

void GameContext::init( univer::Layer* layer )
{
	layer->setMouseEventsEnabled( true );
	layer->setKeyboardEventsEnabled( true );

	m_sceneManager = new SceneManager( layer );
	m_sceneManager->gotoScene( SCENE_TYPE::MAIN_MENU );
}

void GameContext::clear( univer::Layer* layer )
{
	delete m_sceneManager;
}

void GameContext::update( univer::Layer* layer, const univer::Timestep& ts )
{
	m_sceneManager->update( ts );
}