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

#define BIT(x) (1 << x)