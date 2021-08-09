#pragma once

#include "CSkin.h"

class CDynamicSkin2 : public CSkin
{
	univer::UVec4 interpolate( const univer::UVec4& c1, const univer::UVec4& c2, float factor );
	void update( float dt ) override;

private:
	int m_direction = 1;
	float m_factor = 0.f;
	float m_timer = 0.f;

private:
	ADD_PROPERTY( univer::UVec4, color2 )
	ADD_PROPERTY( float, period )
};
