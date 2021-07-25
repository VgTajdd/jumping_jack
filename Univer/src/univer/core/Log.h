// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// Log.h                                                                     //
// ========================================================================= //

#ifndef LOG_H_
#define LOG_H_

#include "univer/core/UDefines.h"
#include "univer/core/LogVerbosity.h"

namespace univer
{
class UVR_API Log
{
public:
	static Log* I();
	static void Init();

public:
	virtual void setCoreVerbosityLevel( const VERBOSITY_LEVEL& level ) = 0;
	virtual void setClientVerbosityLevel( const VERBOSITY_LEVEL& level ) = 0;
	virtual const VERBOSITY_LEVEL& coreVerbosityLevel() = 0;
	virtual const VERBOSITY_LEVEL& clientVerbosityLevel() = 0;

	template<typename T, typename... Types>
	void log( const VERBOSITY_LEVEL& level, bool core, const char* fmt, T arg1, Types ...args );
	template<typename T>
	void log( const VERBOSITY_LEVEL& level, bool core, T msg );

protected:
	virtual void initializeLoggers() = 0;
};
}

#define UVR_CORE_TRACE(...)			::univer::Log::I()->log(univer::VERBOSITY_LEVEL::L_TRACE, true, __VA_ARGS__)
#define UVR_CORE_DEBUG(...)			::univer::Log::I()->log(univer::VERBOSITY_LEVEL::L_DEBUG, true, __VA_ARGS__)
#define UVR_CORE_INFO(...)			::univer::Log::I()->log(univer::VERBOSITY_LEVEL::L_INFO, true, __VA_ARGS__)
#define UVR_CORE_WARN(...)			::univer::Log::I()->log(univer::VERBOSITY_LEVEL::L_WARN, true, __VA_ARGS__)
#define UVR_CORE_ERROR(...)			::univer::Log::I()->log(univer::VERBOSITY_LEVEL::L_ERROR, true, __VA_ARGS__)
#define UVR_CORE_CRITICAL(...)		::univer::Log::I()->log(univer::VERBOSITY_LEVEL::L_CRITICAL,true,  __VA_ARGS__)

#define UVR_TRACE(...)				::univer::Log::I()->log(univer::VERBOSITY_LEVEL::L_TRACE, false, __VA_ARGS__)
#define UVR_D3BUG(...)				::univer::Log::I()->log(univer::VERBOSITY_LEVEL::L_DEBUG, false, __VA_ARGS__)
#define UVR_INFO(...)				::univer::Log::I()->log(univer::VERBOSITY_LEVEL::L_INFO, false, __VA_ARGS__)
#define UVR_WARN(...)				::univer::Log::I()->log(univer::VERBOSITY_LEVEL::L_WARN, false, __VA_ARGS__)
#define UVR_ERROR(...)				::univer::Log::I()->log(univer::VERBOSITY_LEVEL::L_ERROR, false, __VA_ARGS__)
#define UVR_CRITICAL(...)			::univer::Log::I()->log(univer::VERBOSITY_LEVEL::L_CRITICAL,false,  __VA_ARGS__)

#define SET_CLIENT_LOG_VERBOSITY	::univer::Log::I()->setClientVerbosityLevel
#define SET_CORE_LOG_VERBOSITY		::univer::Log::I()->setCoreVerbosityLevel
#define CLIENT_LOG_VERBOSITY		::univer::Log::I()->clientVerbosityLevel()
#define CORE_LOG_VERBOSITY			::univer::Log::I()->coreVerbosityLevel()

#endif