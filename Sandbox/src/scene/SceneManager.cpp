// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// SceneManager.cpp                                                          //
// ========================================================================= //

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
	, m_nextScene( SCENE_TYPE::NONE )
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
	if ( m_nextScene != SCENE_TYPE::NONE )
	{
		gotoScene( m_nextScene );
		m_nextScene = SCENE_TYPE::NONE;
	}
}

void SceneManager::clear()
{
	if ( m_currentScene != nullptr ) delete m_currentScene;

	m_layer->remove( m_canvas );
	m_canvas = nullptr;
}

void SceneManager::init()
{
	if ( m_layer == nullptr ) UVR_ERROR( "Set a layer before init SceneManager." );

	m_canvas = new Sprite( 0, 0, 640, 480 );
	m_canvas->setColor( 1, 1, 1 );
	m_layer->add( m_canvas );
}

void SceneManager::onKeyPressedEvent( univer::KeyPressedEvent& e )
{
	m_currentScene->onKeyPressedEvent( e );
}

void SceneManager::onKeyReleasedEvent( univer::KeyReleasedEvent& e )
{
	m_currentScene->onKeyReleasedEvent( e );
}

void SceneManager::setNextScene( SCENE_TYPE type )
{
	m_nextScene = type;
}