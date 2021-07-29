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

	SceneManager::Get()->setLayer( layer );
	SceneManager::Get()->init();
	SceneManager::Get()->gotoScene( SCENE_TYPE::MAIN_MENU );
}

void GameContext::clear( univer::Layer* layer )
{
	SceneManager::Get()->clear();
}

void GameContext::update( univer::Layer* layer, const univer::Timestep& ts )
{
	SceneManager::Get()->update( ts );
}