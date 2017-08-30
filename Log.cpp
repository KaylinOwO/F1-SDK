#include "../SDK/SDK.h"
#include <time.h>

char g_logFile[MAX_PATH];
char g_debugLogFile[MAX_PATH];

CUtlQueue<char *> Log::LogQueue;
CThreadFastMutex  Log::LogMutex;
int               Log::MaxQueueItems;

void AddToQueue (const char *s)
{
	// alloc a new heap backed string
	//char *heapstr = new char[strlen (s) + 1];
	//V_strcpy (heapstr, s);
	//Log::LogMutex.TryLock ();
	//Log::LogQueue.Insert (heapstr);

	//while (Log::LogQueue.Count () > Log::MaxQueueItems) {
	//	// cleanup
	//	char *removed;
	//	if (Log::LogQueue.RemoveAtHead (removed)) {
	//		delete[] removed;
	//		// removed = nullptr;
	//	}
	//}
	//Log::LogMutex.Unlock ();
}

void Log::Init (HMODULE hModule)
{
	memset (g_logFile, 0, sizeof (g_logFile));

#ifdef _MSC_VER

	// create our own directory for logs

	char *homeDir = std::getenv ("USERPROFILE");

	std::string strHomeDir = homeDir;

	CreateDirectoryA ((strHomeDir + "\\F12017").c_str (), NULL);
	CreateDirectoryA ((strHomeDir + "\\F12017\\Logs").c_str (), NULL);

	strcpy_s (g_logFile, (strHomeDir + "\\F12017\\Logs\\").c_str ());
	size_t slash = -1;

	for (size_t i = 0; i < strlen (g_logFile); i++) {
		if (g_logFile[i] == '/' || g_logFile[i] == '\\') {
			slash = i;
		}
	}

	if (slash != -1) {
		g_logFile[slash + 1] = '\0';
		strcpy_s (g_debugLogFile, g_logFile);
		strcat_s (g_debugLogFile, "debug.log");
		strcat_s (g_logFile, "hook.log");
	} else {
		// Shitty manual mapper detected.
		MessageBoxA (NULL, "Unable to parse target module path", "ERROR", MB_OK);
		ExitProcess (0);
	}
#endif
}

void Log::Debug (const char *fmt, ...)
{
	va_list    va_alist;
	char       szLogbuf[4096];
	char       szParameters[4066];
	char       szTimestamp[30];
	struct tm *current_tm;
	time_t     current_time = time (NULL);
	FILE *     file;
	current_tm = localtime (&current_time);
	sprintf (szTimestamp, "[%02d:%02d:%02d]{DEBUG} %%s\n", current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec);
	va_start (va_alist, fmt);
	vsnprintf (szParameters, sizeof (szParameters), fmt, va_alist);
	va_end (va_alist);
	sprintf (szLogbuf, szTimestamp, szParameters);
	if (file = fopen (g_debugLogFile, "a")) {
		fprintf (file, "%s", szLogbuf);
		printf ("%s", szLogbuf);
		fclose (file);
	}
	AddToQueue (szLogbuf);
}
void Log::Msg (const char *fmt, ...)
{

	va_list    va_alist;
	char       szLogbuf[4096];
	char       szParameters[4066];
	char       szTimestamp[30];
	struct tm *current_tm;
	time_t     current_time = time (NULL);
	FILE *     file;
	current_tm = localtime (&current_time);
	sprintf (szTimestamp, "[%02d:%02d:%02d]{MSG} %%s\n", current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec);
	va_start (va_alist, fmt);
	vsnprintf (szParameters, sizeof (szParameters), fmt, va_alist);
	va_end (va_alist);
	sprintf (szLogbuf, szTimestamp, szParameters);
	if (file = fopen (g_logFile, "a")) {
		fprintf (file, "%s", szLogbuf);
		printf ("%s", szLogbuf);
		fclose (file);
	}
	printf ("%s", szLogbuf);
	AddToQueue (szLogbuf);
}
void Log::Error (const char *fmt, ...)
{

	va_list    va_alist;
	char       szLogbuf[4096];
	char       szParameters[4066];
	char       szTimestamp[30];
	struct tm *current_tm;
	time_t     current_time = time (NULL);
	FILE *     file;
	current_tm = localtime (&current_time);
	sprintf (szTimestamp, "[%02d:%02d:%02d]{ERROR} %%s\n", current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec);
	va_start (va_alist, fmt);
	vsnprintf (szParameters, sizeof (szParameters), fmt, va_alist);
	va_end (va_alist);
	sprintf (szLogbuf, szTimestamp, szParameters);
	if (file = fopen (g_debugLogFile, "a")) {
		fprintf (file, "%s", szLogbuf);
		printf ("%s", szLogbuf);
		fclose (file);
	}
#ifdef _MSC_VER
	MessageBoxA (NULL, szLogbuf, "ERROR", MB_ICONERROR);
#endif
	AddToQueue (szLogbuf);
}
void Log::Fatal (const char *fmt, ...)
{
	va_list    va_alist;
	char       szLogbuf[4096];
	char       szParameters[4066];
	char       szTimestamp[30];
	struct tm *current_tm;
	time_t     current_time = time (NULL);
	FILE *     file;
	current_tm = localtime (&current_time);
	sprintf (szTimestamp, "[%02d:%02d:%02d]{FATAL} %%s\n", current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec);
	va_start (va_alist, fmt);
	vsnprintf (szParameters, sizeof (szParameters), fmt, va_alist);
	va_end (va_alist);
	sprintf (szLogbuf, szTimestamp, szParameters);
	if (file = fopen (g_debugLogFile, "a")) {
		fprintf (file, "%s", szLogbuf);
		printf ("%s", szLogbuf);
		fclose (file);
	}
#ifdef _MSC_VER
	MessageBoxA (NULL, szLogbuf, "FATAL ERROR", MB_ICONERROR);
#endif
	AddToQueue (szLogbuf);
	// TODO ADD ME BACK
	exit (1);
}
void Log::Console (const char *fmt, ...)
{
	typedef void (*MsgFn) (char const *pMsg);
#if defined(F1_GCC)
	static MsgFn fpMsg = (MsgFn)GetProcAddress (gSignatures.GetModuleHandleSafe ("./bin/libtier0.so"), "Msg");
#else
	static MsgFn fpMsg = (MsgFn)GetProcAddress (gSignatures.GetModuleHandleSafe ("tier0.dll"), "Msg");
#endif
	if (fpMsg == NULL) {
		Log::Error ("msg in tier0 invalid");
		return;
	}
	char    buf[950]; // max is 989: https://developer.valvesoftware.com/wiki/Developer_Console_Control
	char    outbuf[950];
	va_list vlist;
	va_start (vlist, fmt);
	vsnprintf (buf, sizeof (buf), fmt, vlist);
	va_end (vlist);

	if (gInts->Cvar == nullptr) {
		// in case we need to print errors when we dont have the interfaces
		sprintf (outbuf, "{CONSOLE} %s\n", buf);
		fpMsg (outbuf);
	} else {
		ConColorMsg ({0, 0, 255, 255}, "%s\n", buf);
		AddToQueue (buf);
	}
}
