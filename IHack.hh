#pragma once

#include <string>
#include <vector>

#include "baseHeaders.hh"

class CUserCmd;
class CBaseEntity;

// base hack interface
// TODO: tidy up function and type names to be uniform with our style
template <typename Derived>
class IHack
{

private:
    Derived &derived()
    {
        return static_cast<Derived &>(*this);
    }

public:
    ~IHack()
    {
    }

    // These functions must be defined in doubles to allow the derived class
    // to not implement them
    // if they were not in this double format then there would be boundless recursion (which is caught as a compiler warning)

    // TODO: remove
    const char *_name() const
    {
        return ""
    }

    // called on init
    void _init()
    {
        return derived().init();
    }
    void init()
    {
        return;
    }

    // called during paint traverse
    bool _paint()
    {
        derived().paint();
        return false;
    }
    bool paint()
    {
        return false;
    }

    void _processCommandBeforePred(CUserCmd *user_cmd)
    {
        return derived().processCommandBeforePred(user_cmd);
    }
    void processCommandBeforePred(CUserCmd *user_cmd)
    {
        return;
    }

    // called during clientmode createmove - takes a CUserCMD
    void _processCommand(CUserCmd *user_cmd)
    {
        return derived().processCommand(user_cmd);
    }
    void processCommand(CUserCmd *user_cmd)
    {
        return;
    }

    // called during keyevent
    bool _keyEvent(ButtonCode_t keynum)
    {
        return derived().keyEvent(keynum);
    }
    bool keyEvent(ButtonCode_t keynum)
    {
        return;
    }

    // the entity here will not be the local player
    // and it will not be null
    void _processEntity(CBaseEntity *entity)
    {
        return derived().processEntity(entity);
    }
    void processEntity(CBaseEntity *entity)
    {
        return;
    }

    // called on CBaseGameSystemPerFrame::Update which is called AFTER CL_Move
    void _perFrame()
    {
        return derived().perFrame();
    }
    void perFrame()
    {
        return;
    }

    // called EVERY frame (not just when we are in game)
    void _everyFrame()
    {
        return derived().everyFrame();
    }
    void everyFrame()
    {
        return;
    }
};
