#pragma once

// stuff for back tracing and getting a call stack (ideally)

#include <exception>
#include <vector>

#include "baseHeaders.hh"
//#include <windows.h>

#pragma warning(disable : 4091)
#include <dbghelp.h>
#pragma comment(lib, "DbgHelp.lib")
#pragma warning(default : 4091)

#include "Log.hh"

#define _TRYCATCH

#ifdef _MSC_VER

LONG UnhandledSehExceptionFilter (EXCEPTION_POINTERS *e, bool silent, const char *name = "");
LONG WINAPI UnhandledSehExceptionHandler (EXCEPTION_POINTERS *e);
LONG CALLBACK UnhandledVectoredExceptionHandler (EXCEPTION_POINTERS *e);
#endif

// stuff for try and catch
// ugly but could improve speed later on
#ifdef _TRYCATCH
#define __TRY __try {
#define __EXCEPT(x) \
	}               \
	__except (x)

#endif
