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
			UAudio::Get()->stopChannel( channelId, 0 );
			m_temporalChannels.erase( channelId );
		}
	}
}

void CSoundManager::playSound( const char* path, float time )
{
	float pos[3] = { 0, 0, 0 };
	auto channel = UAudio::Get()->playSound( path, pos, UAudio::Get()->volumeTodB( 1.0f ) );
	m_temporalChannels[channel] = time;
}
