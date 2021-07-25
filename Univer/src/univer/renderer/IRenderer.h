// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// IRenderer.h                                                               //
// ========================================================================= //

#pragma once

namespace univer
{
class IRenderer
{
public:
	virtual ~IRenderer() {}

	virtual void init() = 0;
	virtual void shutdown() = 0;

	virtual void beginScene( const class ICamera* camera ) = 0;
	virtual void drawSprite( const class Sprite* sprite ) = 0;
	virtual void endScene() = 0;
};
}