// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Sprite.h                                                                  //
// ========================================================================= //

#pragma once

#include "univer/renderables/Renderable.h"

#include "univer/core/UTypes.h"

#include <string>
#include <vector>

#include <glm/glm.hpp> // TOFIX

namespace univer
{
class Sprite : public Renderable
{
public:
	UVR_API explicit Sprite( const float& x = .0f, const float& y = .0f, const float& w = 0.0f, const float& h = 0.0f );
	UVR_API virtual ~Sprite();
	UVR_API static Sprite* loadFromAtlas( const std::string& name );
	UVR_API void setPosition( const UVec3& position );
	UVR_API void setPosition( const float& x, const float& y, const float& z = .0f );
	UVR_API void move( const float& x, const float& y, const float& z = .0f );
	UVR_API void setRotation( const float& rotation );
	UVR_API void rotate( const float& rotation );
	UVR_API void setColor( const glm::vec4& glmColor );
	UVR_API void setColor( const UVec4& color );
	UVR_API void setColor( const float& r, const float& g, const float& b, const float a = 1.0f );
	UVR_API void setAlpha( const float& a );
	UVR_API void setScale( const UVec2& scale );
	UVR_API void setScale( const float& sx, const float& sy );
	UVR_API void setSize( const UVec2& size );
	UVR_API void setSize( const float& w, const float& h );
	UVR_API void setCenter( const UVec2& center );
	UVR_API void setCenter( const float& cx, const float& cy );
	UVR_API void setTexture( const std::string& texturePath );
	UVR_API void setTexture( const std::string& texturePath, const UVec2( &textureUVs )[4] );
	UVR_API void setTilingFactor( const float factor );
	UVR_API void setTintEnabled( const bool enabled );
	UVR_API const UVec4& color() const;
	UVR_API const UVec3& position() const;
	UVR_API const UVec2& scale() const;
	UVR_API const UVec2& size() const;
	UVR_API const UVec2& textureUV( const int index ) const;
	UVR_API const float rotation() const;
	UVR_API const float tilingFactor() const;
	UVR_API const bool tintEnabled() const;
	UVR_API const std::string& texturePath() const;
	UVR_API const Sprite* parent() const;
	UVR_API int childrenCount() const;
	UVR_API bool addChild( Sprite* child );
	UVR_API bool removeChild( Sprite* child, bool deleteChild );
	UVR_API bool removeChildren( bool deleteChildren );
	UVR_API bool setParent( Sprite* parent );
public:
	const std::vector< Sprite* >& children() const;
	Sprite* parent();
public:
	void removeTexture();
private:
	UVec3 m_position;
	float m_rotation;
	UVec2 m_scale;
	UVec2 m_size;
	UVec4 m_color;
	UVec2 m_textureUVs[4];
	std::string m_texturePath;
	float m_tilingFactor;
	bool m_tintEnabled;
private:
	std::vector< Sprite* > m_children;
	Sprite* m_parent;
};
inline const UVec4& Sprite::color() const
{
	return m_color;
}
inline const UVec3& Sprite::position() const
{
	return m_position;
}
inline const UVec2& Sprite::scale() const
{
	return m_scale;
}
inline const UVec2& Sprite::size() const
{
	return m_size;
}
inline const UVec2& Sprite::textureUV( const int index ) const
{
	int safeIndex = index < 0 ? 0 : index;
	safeIndex = safeIndex > 3 ? 3 : safeIndex;
	return m_textureUVs[safeIndex];
}
inline const float Sprite::rotation() const
{
	return m_rotation;
}
inline const float Sprite::tilingFactor() const
{
	return m_tilingFactor;
}
inline const bool Sprite::tintEnabled() const
{
	return m_tintEnabled;
}
inline const std::string& Sprite::texturePath() const
{
	return m_texturePath;
}
inline const std::vector< Sprite* >& Sprite::children() const
{
	return m_children;
}
}