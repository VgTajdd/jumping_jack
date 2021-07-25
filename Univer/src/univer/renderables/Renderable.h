// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Renderable.h                                                              //
// ========================================================================= //

#pragma once

#include "univer/core/UDefines.h"

#include <glm/glm.hpp>

namespace univer
{
class Renderable
{
public:
	UVR_API explicit Renderable();
	UVR_API virtual ~Renderable() = default;
	UVR_API const glm::mat4& transform() const;
	UVR_API void setTransform( const glm::mat4& transform );
protected:
	UVR_API virtual void updateTransform();
	UVR_API void updateTranslation( const float& tx, const float& ty, const float& tz );
	UVR_API void updateTranslation( const float( &vec3 )[3] );
	UVR_API void updateRotation( const float& rotation );
	UVR_API void updateScale( const float& scaleX, const float& scaleY );
	UVR_API void updateScale( const float( &vec2 )[2] );
	UVR_API void updateCenter( const float&x, const float& y ); // Relative to center (default {0,0}).
private:
	glm::mat4 m_scale;
	glm::mat4 m_rotation;
	glm::mat4 m_translation;
	glm::mat4 m_transform;
	glm::mat4 m_centerTransform;
};

inline const glm::mat4& Renderable::transform() const
{
	return m_transform;
}

inline void Renderable::setTransform( const glm::mat4& transform )
{
	m_transform = transform;
}

}