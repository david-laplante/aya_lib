#pragma once

#ifdef AYA_LIB_DLL
	#ifdef AYA_LIB_EXPORTS
		#define AYA_LIB_API __declspec(dllexport)
	#else
		#define AYA_LIB_API __declspec(dllimport)
	#endif
#else
	#define AYA_LIB_API
#endif
