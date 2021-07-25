// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// RenderCommand.h                                                           //
// ========================================================================= //

#pragma once

#include <memory>

namespace univer
{
class RenderCommand
{
public:
	static void InitAPI();
	static void SetViewport( unsigned int x, unsigned int y, unsigned int width, unsigned int height );
	static void SetClearColor( const class UVec4& color );
	static void Clear();
	static void DrawIndexed( const std::shared_ptr<class VertexArray>& vertexArray, const unsigned int indexCount = 0 );
};
}