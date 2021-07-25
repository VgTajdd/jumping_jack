// ========================================================================= //
// Copyright (c) 2021 Agustin Jesus Durand Diaz.                             //
// This code is licensed under the Apache License 2.0.                       //
// UDefines.h                                                                //
// ========================================================================= //

#ifndef UDEFINES_H_
#define UDEFINES_H_

// Platform detection using predefined macros
#ifdef _WIN32
	/* Windows x64/x86 */
	#ifdef _WIN64
		/* Windows x64  */
		#define UVR_PLATFORM_WINDOWS
	#else
		/* Windows x86 */
		#error "x86 Builds are not supported!"
	#endif

#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	/* TARGET_OS_MAC exists on all the platforms
	 * so we must check all of them (in this order)
	 * to ensure that we're running on MAC
	 * and not some other Apple platform */
	#if TARGET_IPHONE_SIMULATOR == 1
	#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
	#define UVR_PLATFORM_IOS
	#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
	#define UVR_PLATFORM_MACOS
	#error "MacOS is not supported!"
	#else
	#error "Unknown Apple platform!"
	#endif
 /* We also have to check __ANDROID__ before __linux__
  * since android is based on the linux kernel
  * it has __linux__ defined */
#elif defined(__ANDROID__)
	#define UVR_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)
	#define UVR_PLATFORM_LINUX
	#error "Linux is not supported!"
#else
	/* Unknown compiler/platform */
	#error "Unknown platform!"
#endif // End of platform detection

#ifdef UVR_PLATFORM_WINDOWS
#if UVR_DYNAMIC_LINK
	#ifdef UVR_BUILD_DLL
		#define UVR_API __declspec(dllexport)
	#else
		#define UVR_API __declspec(dllimport)
	#endif
#else
	#define UVR_API
#endif
#else
	#error Univer only supports Windows!
#endif

#ifdef UVR_DEBUG
#define UVR_ENABLE_ASSERTS
#endif
//=========================================================
#define BIT(x) (1 << x)
//=========================================================
#define STRINGIFY(x) #x							// It returns const char*
#define CONCAT(x, y) x ## y						// It only concatenates!
#define STRINGIFY_CONCAT(x, y) CONCAT(#x, #y)	// It returns const char*
/*
Examples:
const char* s = STRINGIFY_CONCAT( Hi, There );
const char* s = STRINGIFY_CONCAT( Hi, "There" );
const char* s = STRINGIFY_CONCAT( 4, 5 );
*/
//=========================================================

#endif