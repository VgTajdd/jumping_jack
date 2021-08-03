#include "GameScene.h"
#include "SceneType.h"

GameScene::GameScene()
	: m_world{ std::make_shared<World>() }
{
	m_type = SCENE_TYPE::GAME;
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

GameScene::~GameScene()
{}

void GameScene::onKeyPressedEvent( univer::KeyPressedEvent& e )
{
	m_world->onKeyPressedEvent( e );
}

void GameScene::onKeyReleasedEvent( univer::KeyReleasedEvent& e )
{
	m_world->onKeyReleasedEvent( e );
}
