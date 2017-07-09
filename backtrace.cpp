#include "../SDK/backtrace.h"

#include "../SDK/SDK.h"

#ifdef _TRYCATCH
void sehTranslator (unsigned int code, EXCEPTION_POINTERS *e)
{
    // create a new exception base off of these and then throw it.
    // Log::Error("preparing to throw seh exception!");
    throw sehException (code, e);
}

void destructHack ()
{
    extern CHack gHack;

    gHack.~CHack ();
}

void terminateHandler ()
{
    Log::Error ("Termination called!");

    destructHack ();

    return;
}

void unexpectedHandler ()
{
    Log::Error ("Unhandled exception!!");

    destructHack ();
    return;
}
#endif

#ifdef _MSC_VER
LONG WINAPI UnhandledSehExceptionHandler (EXCEPTION_POINTERS *e)
{
    Log::Msg ("Unhandled SEH Exception!");

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

    std::string path = dumpDir + date + time + ".dmp";

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

    Log::Error ("Unhandled exception detected: a dump has been created at %s. Please upload this dump to the discord and tag F1ssi0N", path.c_str ());

    CloseHandle (hFile);

    return EXCEPTION_EXECUTE_HANDLER;
}
#endif
