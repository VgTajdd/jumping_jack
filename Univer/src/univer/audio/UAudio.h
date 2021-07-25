// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// UAudio.h                                                                  //
// ========================================================================= //

#ifndef U_AUDIO_H_
#define U_AUDIO_H_

#include "univer/core/UDefines.h"

namespace univer::audio
{
class UVR_API UAudio
{
public:
	static void Create();
	static void Destroy();
	static UAudio* Get();

public:
	explicit UAudio();
	~UAudio();
	void init();
	void update( const float dt );
	void shutdown();

	int registerSound( const char* name,
					   const float defaultVolumeDB,
					   const float minDistance,
					   const float maxDistance,
					   const bool is3d,
					   const bool isLooping,
					   const bool isStreaming,
					   const bool load = true,
					   const bool useBinary = false );

	void unregisterSound( const int soundId );

	void loadSound( const int soundId,
					const bool b3d = true,
					const bool bLooping = false,
					const bool bStream = false,
					const void* data = nullptr,
					const size_t dataSize = 0 );

	void unLoadSound( const int soundId );

	int playSound( const char* path, const float vPos[3], const float fVolumedB = 0.0f );

	void setChannel3dPosition( const int channelId, const float vPosition[3] );
	void setChannelVolume( const int channelId, float fVolumedB );

	void set3dListenerAndOrientation( const float vPosition[3], const float vLook[3], const float vUp[3] );
	void stopChannel( const int channelId, const float fadeTimeSeconds = 0.f );
	void stopAllChannels();
	bool isPlaying( const int channelId ) const;

	float dBToVolume( const float dB );
	float volumeTodB( const float volume );

protected:
	int playSound( const int soundId, const float vPos[3], const float fVolumedB = 0.0f );

private:
	UAudio( const UAudio& ) = delete;
	UAudio& operator=( const UAudio& ) = delete;

private:
	static UAudio* m_instance;
};
}

#endif // !U_AUDIO_H_