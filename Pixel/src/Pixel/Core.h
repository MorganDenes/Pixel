 #pragma once

#ifdef PXL_PLATFORM_WINDOWS
	#ifdef PXL_BUILD_DLL
		#define PIXEL_API __declspec(dllexport)
	#else
		#define PIXEL_API __declspec(dllimport)
	#endif // PXl_BUILD_DLL
#else
	#error Pixel Only Supports Windows!
#endif // PXL_PLATFORM_WINDOWS


#define BIT(x) (1 << x)