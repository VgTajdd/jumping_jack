#pragma once

#include "Component.h"

#include <map>

class CSoundManager : public Component
{
	void update( float dt ) override;

public:
	void playSound( const char* path, float time );

private:
	std::map<int, float> m_temporalChannels;
};
