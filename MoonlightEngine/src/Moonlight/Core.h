#pragma once

#ifdef ML_PLATFORM_WINDOWS 
	#ifdef ML_BUILD_DLL
		#define MOONLIGHT_API __declspec(dllexport)
	#else
		#define MOONLIGHT_API __declspec(dllimport)
	#endif
#else
#error Moonlight only supports windows!
#endif

#ifdef ML_ENABLE_ASSERTS
	#define ML_ASSERT(x, ...) { if(!x) { HZ_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ML_CORE_ASSERT(x, ...) { if(!x) { HZ_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ML_ASSERT(x, ...)
	#define ML_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)