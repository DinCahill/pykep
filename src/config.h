#ifndef KEP_TOOLBOX_CONFIG_H
#define KEP_TOOLBOX_CONFIG_H


/// The following lines define the behaviour of the symbols that will be included in libraries. These are, by default, 
/// made visible in unix systems, otherwise they need to be made visible explicitely in windows systems
#ifdef _WIN32
	#ifdef KEP_TOOL_DLL_EXPORT_API
		#define __KEP_TOOL_VISIBLE __declspec(dllexport)
	#elif defined ( KEP_TOOL_DLL_IMPORT_API )
		#define __KEP_TOOL_VISIBLE __declspec(dllimport)
	#else
		#define __KEP_TOOL_VISIBLE
	#endif
	#define __KEP_TOOL_VISIBLE_FUNC __KEP_TOOL_VISIBLE

	#if defined(_sims_flanagan_EXPORTS) || defined(_planet_EXPORTS) || defined(_core_EXPORTS)
		#define __PYKEP_VISIBLE __declspec(dllexport)
	#else
		#define __PYKEP_VISIBLE
	#endif
	#define __PYKEP_VISIBLE_FUNC __PYKEP_VISIBLE
#else
	#define __KEP_TOOL_VISIBLE __attribute__ ((visibility("default")))
	#define __KEP_TOOL_VISIBLE_FUNC

	#define __PYKEP_VISIBLE __attribute__ ((visibility("default")))
	#define __PYKEP_VISIBLE_FUNC
#endif
#endif
