// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// FPS.h                                                                     //
// ========================================================================= //

#ifndef FPS_H_
#define FPS_H_

#include "univer/core/UDefines.h"

namespace univer
{
class FPSImpl;

class UVR_API FPS
{
public:
	static FPS& GetInstance()
	{
		static FPS instance;
		return instance;
	}

public:
	void update( float dt );
	const float value() const;

private:
	FPS( const FPS& fps ) = delete;
	FPS& operator=( const FPS& ) = delete;
	explicit FPS();
	~FPS();

private:
	FPSImpl* m_pimpl;
};
}

#endif // !FPS_H_