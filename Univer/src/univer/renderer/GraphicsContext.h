// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// GraphicsContext.h                                                         //
// ========================================================================= //

#pragma once

#include <memory>

namespace univer
{
class GraphicsContext
{
public:
	virtual void Init() = 0;
	virtual void SwapBuffers() = 0;

	static std::unique_ptr<GraphicsContext> Create( void* window );
};
}