// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// VertexArray.h                                                             //
// ========================================================================= //

#pragma once

#include <memory>
#include <vector>

namespace univer
{
class VertexBuffer;
class IndexBuffer;
class VertexArray
{
public:
	virtual ~VertexArray() {}

	virtual void Bind() const = 0;
	virtual void Unbind() const = 0;

	virtual void AddVertexBuffer( const std::shared_ptr<VertexBuffer>& vertexBuffer ) = 0;
	virtual void SetIndexBuffer( const std::shared_ptr<IndexBuffer>& indexBuffer ) = 0;

	virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const = 0;
	virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;

	static std::shared_ptr< VertexArray > Create();
};
}