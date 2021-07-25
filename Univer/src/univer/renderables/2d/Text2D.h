// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Text2D.h                                                                  //
// ========================================================================= //

#ifndef TEXT_2D_H_
#define TEXT_2D_H_

#include "univer/renderables/2d/Sprite.h"
#include "univer/core/URectangle.h"

namespace univer
{
struct TextFormat
{
	enum class ALIGNMENT
	{
		LEFT,
		CENTER,
		RIGHT
	};
	unsigned int fontSize = 24;
	std::string font = "arial.ttf";
	bool bold = false;
	bool italic = false;
	ALIGNMENT alignment = ALIGNMENT::LEFT;
};

class Text2D : public Sprite
{
public:
	UVR_API explicit Text2D() {}
	UVR_API explicit Text2D( const std::string& text ) : m_text( text ) {}
	UVR_API explicit Text2D( const std::string& text, const TextFormat& fmt ) : m_text( text ), m_format( fmt ) {}
	UVR_API void setText( const std::string& text );
	UVR_API const URectangle& bounds() const { return m_bounds; }
	UVR_API const TextFormat& format() const { return m_format; }
	UVR_API void setFormat( const TextFormat& format );
private:
	void update();
	void clear();
private:
	std::string m_text;
	TextFormat m_format;
	URectangle m_bounds;
};
}

#endif