// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// EntryPoint.h                                                              //
// ========================================================================= //

#ifndef ENTRY_POINT_H_
#define ENTRY_POINT_H_

#include "univer/profiling/Instrumentation.h"

#ifdef UVR_PLATFORM_WINDOWS
#include <Windows.h>

#ifdef UVR_DIST
int WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd )
#else
int main( int argc, char** argv )
#endif
{
	univer::Log::Init();

	UVR_PROFILE_BEGIN_SESSION( "Startup", "univer_profile_startup.json" );
	auto app = univer::createApplication();
	UVR_PROFILE_END_SESSION();

	UVR_PROFILE_BEGIN_SESSION( "Runtime", "univer_profile_runtime.json" );
	app->run();
	UVR_PROFILE_END_SESSION();

	UVR_PROFILE_BEGIN_SESSION( "ShutDown", "univer_profile_shutdown.json" );
	delete app;
	UVR_PROFILE_END_SESSION();
}

#endif

#endif