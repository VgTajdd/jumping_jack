// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// RendererAPI.h                                                             //
// ========================================================================= //

#pragma once

#include <memory>

namespace univer
{
class VertexArray;
class UVec4;
class RendererAPI
{
public:
	enum class API
	{
		None = 0,
		OpenGL = 1
	};
public:
	virtual void init() = 0;
	virtual void setViewport( unsigned int x, unsigned int y, unsigned int width, unsigned int height ) = 0;
	virtual void setClearColor( const UVec4& color ) = 0;
	virtual void clear() = 0;
	virtual void drawIndexed( const std::shared_ptr<VertexArray>& vertexArray, const unsigned int indexCount ) = 0;

	inline static API GetAPI() { return instance; }
	static std::unique_ptr<RendererAPI> Create();

private:
	static API instance;
};
}