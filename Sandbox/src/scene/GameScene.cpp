#include "GameScene.h"
#include "SceneType.h"

#include "world/jj/JJWorld.h"

GameScene::GameScene()
	: m_world{ std::make_shared<JJWorld>() }
{
	m_type = SCENE_TYPE::GAME;
}

GameScene::~GameScene()
{
	m_world->clear();
}

void GameScene::update( float dt )
{
	m_world->update( dt );
}

void GameScene::init()
{
	m_world->setCanvas( m_canvas );
	m_world->init();
}

void GameScene::onKeyPressedEvent( univer::KeyPressedEvent& e )
{
	m_world->onKeyPressedEvent( e );
}

void GameScene::onKeyReleasedEvent( univer::KeyReleasedEvent& e )
{
	m_world->onKeyReleasedEvent( e );
}
