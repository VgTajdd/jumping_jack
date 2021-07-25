// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Instrumentation.h                                                         //
// ========================================================================= //

#pragma once

#include "univer/profiling/InstrumentationTimer.h"
#include "univer/profiling/Instrumentor.h"

#if UVR_PROFILE

// Resolve which function signature macro will be used. Note that this only
// is resolved when the (pre)compiler starts, so the syntax highlighting
// could mark the wrong one in your editor!
#if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
#define UVR_FUNC_SIG __PRETTY_FUNCTION__
#elif defined(__DMC__) && (__DMC__ >= 0x810)
#define UVR_FUNC_SIG __PRETTY_FUNCTION__
#elif defined(__FUNCSIG__)
#define UVR_FUNC_SIG __FUNCSIG__
#elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
#define UVR_FUNC_SIG __FUNCTION__
#elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
#define UVR_FUNC_SIG __FUNC__
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
#define UVR_FUNC_SIG __func__
#elif defined(__cplusplus) && (__cplusplus >= 201103)
#define UVR_FUNC_SIG __func__
#else
#define UVR_FUNC_SIG "UVR_FUNC_SIG unknown!"
#endif

#define UVR_PROFILE_BEGIN_SESSION(name, filepath) ::univer::Instrumentor::Get()->beginSession( name, filepath )
#define UVR_PROFILE_END_SESSION() ::univer::Instrumentor::Get()->endSession()
#define UVR_PROFILE_SCOPE(name) ::univer::InstrumentationTimer timer##__LINE__( name );
#define UVR_PROFILE_FUNCTION() UVR_PROFILE_SCOPE(UVR_FUNC_SIG)
#else
#define UVR_PROFILE_BEGIN_SESSION(name, filepath)
#define UVR_PROFILE_END_SESSION()
#define UVR_PROFILE_SCOPE(name)
#define UVR_PROFILE_FUNCTION()
#endif