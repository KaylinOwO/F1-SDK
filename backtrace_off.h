
#define _TRY
#undef _CATCH
#define _CATCH if( 0 )
#define _CATCH_SEH if( 0 )
#define _CATCH_SEH_REPORT_ERROR( Class, funcName )
#define _INSTALL_SEH_TRANSLATOR()

#define sehTranslator( code, e )
#define terminateHandler()
#define unexpectedHandler()
#define unhandledSehExceptionHandler()
#define setHandlers()