// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Emitter.h                                                                 //
// ========================================================================= //

#pragma once

#include "univer/core/UDefines.h"

namespace univer { class Timestep; }
namespace univer { class Sprite; }
namespace univer { struct EmitterSettings; }

namespace univer
{
class UVR_API Emitter
{
public:
	explicit Emitter();
	~Emitter();
	void update( const Timestep& ts );
	void setSettings( const EmitterSettings& settings );
	void setPosition( const float& x, const float& y );
	const EmitterSettings& settings() const;
	Sprite* canvas() const;

private:
	class EmitterImpl* m_pimpl;
};
}