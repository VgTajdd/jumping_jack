// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Instrumentor.h                                                            //
// ========================================================================= //

#pragma once

#include "univer/core/UDefines.h"

namespace univer
{
class UVR_API Instrumentor
{
public:
	static Instrumentor* Get();
public:
	explicit Instrumentor();
	~Instrumentor();
	void beginSession( const char* name, const char* filepath = "results.json" );
	void endSession();
	void writeProfile( const char* name, long long start, long long end );
private:
	class InstrumentorImpl* m_pimpl;
};
}