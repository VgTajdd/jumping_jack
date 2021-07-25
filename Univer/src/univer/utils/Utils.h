// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Utils.h                                                                   //
// ========================================================================= //

#pragma once

#include "univer/core/UDefines.h"

#include <string>
#include <vector>

namespace univer
{
	UVR_API bool convertRelativeToAbsolute( const std::string& relativePath, std::string& absolutePath );

	/*
	Returns value between min and max.
	x only will take values between 0 and 1 including them.
	*/
	UVR_API float interpolate( const float& x, const float& min, const float& max );

	std::vector< std::string > split( const std::string& str, const std::string& delim );

	int stoi( const std::string& str, int& int_value, std::size_t* pos, int base );
	UVR_API bool stoi( const std::string& str, int& int_value );
}