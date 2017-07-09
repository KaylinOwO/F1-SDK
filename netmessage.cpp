#include "netmessage.h"

#include "Log.h"

#include "CSignature.h"

bool CLC_RespondCvarValue::WriteToBuffer( bf_write &buffer )
{
    buffer.WriteUBitLong( 13, NETMSG_TYPE_BITS );

    buffer.WriteSBitLong( m_iCookie, 32 );
    buffer.WriteSBitLong( m_eStatusCode, 4 );

    buffer.WriteString( m_szCvarName );
    buffer.WriteString( m_szCvarValue );

    return !buffer.IsOverflowed();
}

bool CLC_RespondCvarValue::ReadFromBuffer( bf_read &buffer )
{
    m_iCookie = buffer.ReadSBitLong( 32 );
    m_eStatusCode = (EQueryCvarValueStatus)buffer.ReadSBitLong( 4 );

    // Read the name.
    buffer.ReadString( m_szCvarNameBuffer, sizeof( m_szCvarNameBuffer ) );
    m_szCvarName = m_szCvarNameBuffer;

    // Read the value.
    buffer.ReadString( m_szCvarValueBuffer, sizeof( m_szCvarValueBuffer ) );
    m_szCvarValue = m_szCvarValueBuffer;

    return !buffer.IsOverflowed();
}

bool NET_NOP::WriteToBuffer( bf_write &buffer )
{
    buffer.WriteUBitLong( GetType(), 6 );
    return !buffer.IsOverflowed();
}

bool NET_NOP::ReadFromBuffer( bf_read &buffer )
{
    return true;
}

bool NET_StringCmd::WriteToBuffer( bf_write &buffer )
{
    buffer.WriteUBitLong( GetType(), NETMSG_TYPE_BITS );
    return buffer.WriteString( m_szCommand ? m_szCommand : " NET_StringCmd NULL" );
}

bool NET_SetConVar::WriteToBuffer( bf_write &buffer )
{
    buffer.WriteUBitLong( GetType(), NETMSG_TYPE_BITS );

    int numvars = m_ConVars.Count();

    // Note how many we're sending
    buffer.WriteByte( numvars );

    for( int i = 0; i < numvars; i++ )
    {
        cvar_t *cvar = &m_ConVars[ i ];
        buffer.WriteString( cvar->name );
        buffer.WriteString( cvar->value );
    }

    return !buffer.IsOverflowed();
}

bool NET_SetConVar::ReadFromBuffer( bf_read &buffer )
{
    int numvars = buffer.ReadByte();

    m_ConVars.RemoveAll();

    for( int i = 0; i < numvars; i++ )
    {
        cvar_t cvar;
        buffer.ReadString( cvar.name, sizeof( cvar.name ) );
        buffer.ReadString( cvar.value, sizeof( cvar.value ) );
        m_ConVars.AddToTail( cvar );
    }
    return !buffer.IsOverflowed();
}

bool NET_StringCmd::ReadFromBuffer( bf_read &buffer )
{
    m_szCommand = m_szCommandBuffer;

    return buffer.ReadString( m_szCommandBuffer, sizeof( m_szCommandBuffer ) );
}

CLC_CmdKeyValues::CLC_CmdKeyValues( KeyValues *kv )
{
    /*
    this->byte4 = 1;
    this->dword8 = 0;
    this->KeyValuePtr = a2;
    */

    unk = 1;
    unk2 = 0;
    m_keyValues = kv;
}

bool CLC_CmdKeyValues::ReadFromBuffer( bf_read &buffer )
{
    // we dont do anything here so just return true until we need to do something
    Log::Error( "CLC_CmdkeyValues::ReadFromBuffer is not implemented!" );
    return true;
}

bool CLC_CmdKeyValues::WriteToBuffer( bf_write &buffer )
{
    // Log::Console("CLC_CmdKeyValues::WriteToBuffer writing to buffer!");

    typedef bool( __thiscall * OriginalFn )( CLC_CmdKeyValues *, bf_write & );

    static DWORD dwFuncCall = gSignatures.GetEngineSignature( "E8 ? ? ? ? 8B C8 EB 02 33 C9 85 F6 74 15" ) + 1;
    static DWORD dwWriteToBuffer = ( ( *( PDWORD )( dwFuncCall ) ) + dwFuncCall + 4 );
    static OriginalFn fn = (OriginalFn)dwWriteToBuffer;

    return fn( this, buffer );
}
