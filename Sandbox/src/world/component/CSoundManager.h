// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// CSoundManager.h                                                           //
// ========================================================================= //

#pragma once

#include "Component.h"

#include <map>

class CSoundManager : public Component
{
	void update( float dt ) override;

public:
	~CSoundManager();
	void playSound( const char* path, float time, float fadeTime = 0.f );

private:
	std::map<int, float> m_temporalChannels;
	std::map<int, float> m_fadeTimes;
};
