// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// CDynamicSkin2.cpp                                                         //
// ========================================================================= //

#include "CDynamicSkin2.h"

#include <univer/renderables/2d/Sprite.h>

void CDynamicSkin2::update( float dt )
{
	CSkin::update( dt );
	m_timer += dt;
	if ( m_timer > m_period )
	{
		m_direction = -m_direction;
		m_timer = 0.f;
	}
	m_factor = ( m_timer / m_period );
	m_factor = m_direction == -1 ? ( 1.f - m_factor ) : m_factor;
	univer::UVec4 finalColor{ interpolate( color(), color2(), m_factor ) };
	sprite()->setColor( finalColor );
}

univer::UVec4 CDynamicSkin2::interpolate( const univer::UVec4& c1, const univer::UVec4& c2, float factor )
{
	univer::UVec4 finalColor;
	finalColor.r = c1.r * factor + c2.r * ( 1 - factor );
	finalColor.g = c1.g * factor + c2.g * ( 1 - factor );
	finalColor.b = c1.b * factor + c2.b * ( 1 - factor );
	finalColor.a = c1.a * factor + c2.a * ( 1 - factor );
	return finalColor;
}