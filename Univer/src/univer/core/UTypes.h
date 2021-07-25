// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// UTypes.h                                                                  //
// ========================================================================= //

#ifndef UTYPES_H_
#define UTYPES_H_

#include "univer/core/UDefines.h"

namespace univer
{
class UVR_API UVec2
{
public:
	explicit UVec2() = default;
	UVec2( const float _x, const float _y ) : x( _x ), y( _y ) {}
	UVec2( const float( &vec2 )[2] ) : x( vec2[0] ), y( vec2[1] ) {}
	UVec2& operator=( const float( &vec2 )[2] ) { x = vec2[0]; y = vec2[1]; return *this; };
	~UVec2() = default;
public:
	union
	{
		struct
		{
			float x;
			float y;
		};
		struct
		{
			float w;
			float h;
		};
	};
};
class UVR_API UVec3
{
public:
	explicit UVec3() = default;
	UVec3( const float _x, const float _y, const float _z ) : x( _x ), y( _y ), z( _z ) {}
	UVec3( const float( &vec3 )[3] ) : x( vec3[0] ), y( vec3[1] ), z( vec3[2] ) {}
	UVec3& operator=( const float( &vec3 )[3] ) { x = vec3[0]; y = vec3[1]; z = vec3[2]; return *this; };
	~UVec3() = default;
public:
	union
	{
		struct
		{
			float r;
			float g;
			float b;
		};
		struct
		{
			float x;
			float y;
			float z;
		};
	};
};
class UVR_API UVec4
{
public:
	explicit UVec4() = default;
	UVec4( const float _x, const float _y, const float _z, const float _w ) : x( _x ), y( _y ), z( _z ), w( _w ) {}
	UVec4( const float( &vec4 )[4] ) : r( vec4[0] ), g( vec4[1] ), b( vec4[2] ), a( vec4[3] ) {}
	UVec4& operator=( const float( &vec4 )[4] ) { x = vec4[0]; y = vec4[1]; z = vec4[2]; w = vec4[3]; return *this; };
	~UVec4() = default;
public:
	union
	{
		struct
		{
			float r;
			float g;
			float b;
			float a;
		};
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};
};
class UVR_API UColor32
{
public:
	explicit UColor32() = default;
	UColor32( const int _r, const int _g, const int _b, const int _a ) :r( _r ), g( _g ), b( _b ), a( _a ) {}
	UColor32( const int( &vec4 )[4] ) : r( vec4[0] ), g( vec4[1] ), b( vec4[2] ), a( vec4[3] ) {}
	UColor32& operator=( const int( &vec4 )[4] ){ r = vec4[0]; g = vec4[1]; b = vec4[2]; a = vec4[3]; return *this; }
	~UColor32() = default;
public:
	unsigned int r : 8;
	unsigned int g : 8;
	unsigned int b : 8;
	unsigned int a : 8;
};
}

#endif