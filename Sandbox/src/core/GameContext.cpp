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
	layer->setMouseEventsEnabled( false );
	layer->setKeyboardEventsEnabled( true );

	SceneManager::Get()->setLayer( layer );
	SceneManager::Get()->init();
	SceneManager::Get()->setNextScene( SCENE_TYPE::MAIN_MENU );
}

void GameContext::clear( univer::Layer* layer )
{
	SceneManager::Get()->clear();
}

void GameContext::update( univer::Layer* layer, const univer::Timestep& ts )
{
	SceneManager::Get()->update( ts );
}

void GameContext::onKeyPressedEvent( univer::Layer* layer, univer::KeyPressedEvent& e )
{
	SceneManager::Get()->onKeyPressedEvent( e );
}

void GameContext::onKeyReleasedEvent( univer::Layer* layer, univer::KeyReleasedEvent& e )
{
	SceneManager::Get()->onKeyReleasedEvent( e );
}
