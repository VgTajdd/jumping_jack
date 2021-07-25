// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// LogVerbosity.h                                                            //
// ========================================================================= //

#pragma once

namespace univer
{
enum class VERBOSITY_LEVEL
{
	L_CRITICAL = 50,
	L_ERROR = 40,
	L_WARN = 30,
	L_INFO = 20,
	L_DEBUG = 10,
	L_TRACE = 0
};
}