// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// InstrumentationTimer.h                                                    //
// ========================================================================= //

#pragma once

#include "univer/core/UDefines.h"

namespace univer
{
class UVR_API InstrumentationTimer
{
public:
	explicit InstrumentationTimer( const char* );
	~InstrumentationTimer();
private:
	class InstrumentationTimerImpl* m_pimpl;
};
}