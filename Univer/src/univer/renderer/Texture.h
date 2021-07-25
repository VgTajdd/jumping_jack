// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Texture.h                                                                 //
// ========================================================================= //

#pragma once

#include <string>
#include <memory>

namespace univer
{
class Texture
{
public:
	virtual ~Texture() = default;

	virtual uint32_t GetWidth() const = 0;
	virtual uint32_t GetHeight() const = 0;

	virtual void SetData( void* data, uint32_t size ) = 0;

	virtual void Bind( uint32_t slot = 0 ) const = 0;
};

class Texture2D : public Texture
{
public:
	static std::shared_ptr< Texture2D > Create( const std::string& path );
	static std::shared_ptr< Texture2D > Create( uint32_t width, uint32_t height );
};
}