// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Random.h                                                                  //
// ========================================================================= //

#ifndef RANDOM_H_
#define RANDOM_H_

#include "univer/core/UDefines.h"

namespace univer
{
class RandomImpl;

class UVR_API Random
{
public:
	static Random& GetInstance()
	{
		static Random instance;
		return instance;
	}
public:
	void init();
	float value() const;
	float valueInRange( const float min, const float max ) const;
	int intInRange( const int min, const int max ) const;

private:
	Random( const Random& fps ) = delete;
	Random& operator=( const Random& ) = delete;
	explicit Random();
	~Random();

private:
	RandomImpl* m_impl;
};
}
#endif // !RANDOM_H_