// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Shader.h                                                                  //
// ========================================================================= //

#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <glm/glm.hpp>

namespace univer
{
class Shader
{
public:
	virtual ~Shader() = default;

	virtual void Bind() const = 0;
	virtual void Unbind() const = 0;

	virtual void SetInt( const std::string& name, int value ) = 0;
	virtual void SetFloat3( const std::string& name, const glm::vec3& value ) = 0;
	virtual void SetFloat4( const std::string& name, const glm::vec4& value ) = 0;
	virtual void SetMat4( const std::string& name, const glm::mat4& value ) = 0;
	virtual void SetSamplerArray( const std::string& name, int count, int* value ) = 0;

	virtual const std::string& GetName() const = 0;

	static std::shared_ptr<Shader> Create( const std::string& filepath );
	static std::shared_ptr<Shader> Create( const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc );

protected:
	virtual int findAndSaveUniformLocation( const std::string& name ) = 0;
};

class ShaderLibrary
{
public:
	void Add( const std::string& name, const std::shared_ptr<Shader>& shader );
	void Add( const std::shared_ptr<Shader>& shader );
	std::shared_ptr<Shader> Load( const std::string& filepath );
	std::shared_ptr<Shader> Load( const std::string& name, const std::string& filepath );

	std::shared_ptr<Shader> Get( const std::string& name );

	bool Exists( const std::string& name ) const;
private:
	std::unordered_map<std::string, std::shared_ptr<Shader>> m_shaders;
};
}