// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// MainMenu.cpp                                                              //
// ========================================================================= //

#include "MainMenu.h"
#include "SceneManager.h"
#include "SceneType.h"

#include "data/Stats.h"

#include <Univer.h>
#include <univer/renderables/2d/Sprite.h>
#include <univer/utils/Timestep.h>

using univer::audio::UAudio;

MainMenu::MainMenu()
	: m_blinkBackground{ nullptr }
	, m_timeElapsed{ 0.f }
	, m_timer{ 0.f }
{
	m_type = SCENE_TYPE::MAIN_MENU;
}

void MainMenu::update( float dt )
{
	const float time = 0.5f;
	if ( m_timer > time )
	{
		m_blinkBackground->setAlpha( m_blinkBackground->color().a > 0.5f ? 0.f : 1.f );
		m_timer -= time;
	}
	m_timer += dt;

	if ( m_timeElapsed > 5.0f )
	{
		SceneManager::Get()->setNextScene( SCENE_TYPE::GAME );
	}
	m_timeElapsed += dt;
}

void MainMenu::init()
{
	stats::Stats::resetStats();

	float position1[3] = { 0, 0, 0 };
	UAudio::Get()->playSound( "assets/sandbox/sounds/Interface.mid", position1, UAudio::Get()->volumeTodB( 1.0f ) );

	univer::Sprite* secondSprite = new univer::Sprite();
	secondSprite->setTexture( "assets/sandbox/textures/frame1.png" );
	secondSprite->setSize( 640, 480 );
	m_canvas->addChild( secondSprite );

	m_blinkBackground = new univer::Sprite();
	m_blinkBackground->setTexture( "assets/sandbox/textures/frame2.png" );
	m_blinkBackground->setSize( 640, 480 );
	m_blinkBackground->setTintEnabled( true );
	m_canvas->addChild( m_blinkBackground );
}

MainMenu::~MainMenu()
{
	m_canvas->removeChildren( true );
}
