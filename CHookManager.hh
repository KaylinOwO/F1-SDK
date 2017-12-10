#pragma once

#include <memory>
#include <unordered_map>

#include "VMTHooks.hh"

#include "Log.hh"

using namespace toolkit;

template <>
struct std::hash< std::pair< void *, unsigned > >
{
    size_t operator()( const std::pair< void *, unsigned > &c ) const
    {
        // we dont need to hash this, each index is unique anyway
        return reinterpret_cast< size_t >( c.first ) + c.second;
    }
};

// manager for vmt hooks
class CHookManager
{

    std::unordered_map< std::pair< void *, unsigned >, std::vector< int > > hookedMethods;

public:
    ~CHookManager();

    bool isHooked( void *address, unsigned offset = 0 );

    // performs no initialisation on the hook created
    VMTBaseManager *findOrCreateHook( void *address, unsigned offset = 0 );

    bool methodHooked( void *address, int index, int offset = 0 );

    void hookMethod( void *address, int index, void *newFunc, unsigned offset = 0 );

    template < typename T >
    T getMethod( void *address, int index, unsigned offset = 0 )
    {
        if( !isHooked( address, offset ) )
        {
            if( offset == 0 )
                Log::Error( "trying to find function index '%d' from address 0x%X with no hook!!", index, address );
            else
                Log::Error( "trying to find function index '%d' from address 0x%X with offset 0x%X with no hook!!", index, address, offset );
        }

        return findOrCreateHook( address, offset )->GetMethod< T >( index );
    }
};

extern CHookManager gHookManager;
