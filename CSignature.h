#pragma once

#include "baseHeaders.h"

class CSignature
{
public:
    DWORD dwFindPattern( DWORD dwAddress, DWORD dwLength, const char *szPattern );
    HMODULE GetModuleHandleSafe( const char *pszModuleName );
    DWORD GetModuleSignature( const char *module, const char *chPattern );
    DWORD GetClientSignature( const char *chPattern );
    DWORD GetEngineSignature( const char *chPattern );
    DWORD GetServerSignature( char *chPattern );
};

extern CSignature gSignatures;
