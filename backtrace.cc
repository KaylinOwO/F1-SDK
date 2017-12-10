#include "baseHeaders.hh"

#include "../SDK/backtrace.hh"

#include "../SDK/SDK.hh"

#ifdef _MSC_VER

LONG UnhandledSehExceptionFilter (EXCEPTION_POINTERS *e, bool silent, const char *name)
{
	Log::Console ("Unhandled SEH Exception!");

	// Create a unique filename from the current date + time

	SYSTEMTIME sTime;
	GetLocalTime (&sTime);

	char date[10];
	char time[10];
	GetDateFormat (LOCALE_USER_DEFAULT, 0, &sTime, "yyyyMMdd", date, 10);
	GetTimeFormat (LOCALE_USER_DEFAULT, TIME_FORCE24HOURFORMAT, &sTime, "hhmmss", time, 10);

	const char *homeDir = getenv ("USERPROFILE");
	std::string dumpDir = std::string (homeDir) + "\\F12017\\Dumps\\";

	CreateDirectory (dumpDir.c_str (), NULL);

	std::string path = dumpDir + date + time + "_" + name + ".dmp";

	HANDLE hFile = CreateFile (
	    path.c_str (),
	    GENERIC_READ | GENERIC_WRITE,
	    FILE_SHARE_DELETE | FILE_SHARE_READ | FILE_SHARE_WRITE,
	    NULL,
	    CREATE_ALWAYS,
	    FILE_ATTRIBUTE_NORMAL,
	    NULL);

	MINIDUMP_EXCEPTION_INFORMATION mei;
	mei.ThreadId          = GetCurrentThreadId ();
	mei.ClientPointers    = TRUE;
	mei.ExceptionPointers = e;

	MiniDumpWriteDump (
	    GetCurrentProcess (),
	    GetCurrentProcessId (),
	    hFile,
	    MiniDumpNormal,
	    &mei,
	    NULL,
	    NULL);

	if (silent == false)
		Log::Error ("Unhandled exception detected: a dump has been created at %s. Please upload this dump to the discord and tag F1ssi0N", path.c_str ());
	else
		Log::Console ("Unhandled exception detected: a dump has been created at %s. Please upload this dump to the discord and tag F1ssi0N", path.c_str ());

	CloseHandle (hFile);

	return EXCEPTION_EXECUTE_HANDLER;
}

LONG WINAPI UnhandledSehExceptionHandler (EXCEPTION_POINTERS *e)
{
	return UnhandledSehExceptionFilter (e, false);
}

LONG CALLBACK UnhandledVectoredExceptionHandler (EXCEPTION_POINTERS *e)
{
	ConMsg ("[VEH] 0x%X @ 0x%X\n", e->ExceptionRecord->ExceptionCode, e->ExceptionRecord->ExceptionAddress);
	return EXCEPTION_CONTINUE_SEARCH;
}

#endif
