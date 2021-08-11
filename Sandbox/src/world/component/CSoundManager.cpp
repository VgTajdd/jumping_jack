// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// CSoundManager.cpp                                                         //
// ========================================================================= //

#include "CSoundManager.h"

#include <univer/audio/UAudio.h>
using univer::audio::UAudio;

void CSoundManager::update( float dt )
{
	for ( auto& [channelId, time] : m_temporalChannels )
	{
		time -= dt;
		if ( time <= 0 )
		{
			UAudio::Get()->stopChannel( channelId, m_fadeTimes[channelId] * 1000 );
			m_temporalChannels.erase( channelId );
			m_fadeTimes.erase( channelId );
		}
	}
}

CSoundManager::~CSoundManager()
{
	for ( auto& [channelId, time] : m_temporalChannels )
	{
		UAudio::Get()->stopChannel( channelId, 500 );
	}
}

void CSoundManager::playSound( const char* path, float time, float fadeTime )
{
	float pos[3] = { 0, 0, 0 };
	auto channelId = UAudio::Get()->playSound( path, pos, UAudio::Get()->volumeTodB( 1.0f ) );
	m_temporalChannels[channelId] = time;
	m_fadeTimes[channelId] = fadeTime;
}
