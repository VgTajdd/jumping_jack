// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// JJWorld.cpp                                                               //
// ========================================================================= //

#include "JJWorld.h"
#include "Platform.h"
#include "data/Constants.h"
#include "data/Stats.h"

#include <univer/renderables/2d/Sprite.h>
#include <univer/renderables/2d/Text2D.h>

#include <sstream>

using univer::Text2D;
using univer::TextFormat;

std::shared_ptr<JJWorld>& JJWorld::GetPrivate()
{
	static std::shared_ptr<JJWorld> instance;
	return instance;
}

const std::shared_ptr<JJWorld>& JJWorld::Get()
{
	return GetPrivate();
}

void JJWorld::init()
{
	World::init();

	// Add platforms.
	for ( int i = 1; i <= 8; i++ )
	{
		addActor( std::move( std::make_shared<Platform>( i ) ) );
	}

	// Set bg color.
	canvas()->setColor( constants::getLevelColor( stats::Stats::LEVEL ) );

	initializeTexts();

	GetPrivate() = std::dynamic_pointer_cast<JJWorld>( shared_from_this() );
}

void JJWorld::clear()
{
	GetPrivate().reset();

	canvas()->removeChild( m_lifes, true );
	canvas()->removeChild( m_score, true );

	World::clear();
}

void JJWorld::initializeTexts()
{
	m_lifes = new Text2D();
	{
		m_lifes->setText( "Lifes: 6" );
		m_lifes->setPosition( 10, 470 );
		auto format = m_lifes->format();
		format.alignment = TextFormat::ALIGNMENT::LEFT;
		format.fontSize = 36;
		m_lifes->setFormat( format );
	}

	m_score = new Text2D();
	{
		m_score->setText( "Score: 0" );
		m_score->setPosition( 630, 470 );
		auto format = m_score->format();
		format.alignment = TextFormat::ALIGNMENT::RIGHT;
		format.fontSize = 36;
		m_score->setFormat( format );
	}

	canvas()->addChild( m_lifes );
	canvas()->addChild( m_score );

	setLifes( stats::Stats::LIFES );
	setScore( stats::Stats::SCORE );
}
void JJWorld::setLifes( int lifes )
{
	std::stringstream ss;
	ss << "Lifes: ";
	ss << lifes;
	m_lifes->setText( ss.str() );
}

void JJWorld::setScore( int score )
{
	std::stringstream ss;
	ss << "Score: ";
	ss << score;
	m_score->setText( ss.str() );
}
