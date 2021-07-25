// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Assert.h                                                                  //
// ========================================================================= //

#ifndef ASSERT_H_
#define ASSERT_H_

#include "univer/core/Log.h"
#include "univer/core/UDefines.h"

#ifdef UVR_ENABLE_ASSERTS
#define UVR_ASSERT(x, ...) { if(!(x)) { UVR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define UVR_CORE_ASSERT(x, ...) { if(!(x)) { UVR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define UVR_ASSERT(x, ...)
#define UVR_CORE_ASSERT(x, ...)
#endif

#endif // !ASSERT_H_