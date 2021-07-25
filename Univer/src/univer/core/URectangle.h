// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// URectangle.h                                                              //
// ========================================================================= //

#ifndef URECTANGLE_H_
#define URECTANGLE_H_

#include "univer/core/UDefines.h"
#include "univer/core/UTypes.h"

namespace univer
{
class UVR_API URectangle
{
public:
	explicit URectangle();
	explicit URectangle( const UVec2& topLeft, const UVec2& size );
	explicit URectangle( const float l, const float r, const float t, const float b );
	void reset( const float l = 0.f, const float r = 0.f, const float t = 0.f, const float b = 0.f );
	void reset( const UVec2& topLeft, const UVec2& size );
	void growByUnion( const URectangle& other );
	void move( const UVec2& delta );
	void move( const float dx, const float dy );
	bool contains( const UVec2& p ) const;
	bool contains( const float x, const float y ) const;
	bool intersetcts( const URectangle& other ) const;
public:
	static URectangle intersection( const URectangle& a, const URectangle& b );
	static URectangle move( const URectangle& a, const UVec2& delta );
	static URectangle join( const URectangle& a, const URectangle& b );
public:
	const UVec2& size() const { return m_size; }
	const float left() const { return m_left; }
	const float right() const { return m_right; }
	const float top() const { return m_top; }
	const float bottom() const { return m_bottom; }

private:
	UVec2 m_size;
	float m_left;
	float m_right;
	float m_top;
	float m_bottom;
};
}

#endif // URECTANGLE_H_