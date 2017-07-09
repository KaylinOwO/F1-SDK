#pragma once

#include <string>
#include <vector>

#include "baseHeaders.h"

class CUserCmd;
class CBaseEntity;

// base hack interface
template <typename Derived>
class IHack
{

private:
	Derived &derived ()
	{
		return static_cast<Derived &> (*this);
	}

public:
	~IHack ()
	{
	}

	// each hack must impl the name function

	// These functions must be defined in doubles to allow the derived class
	// to not implement them

	// TODO: remove
	const char *_name () const
	{
		return ""
	}

	// called on init
	void _init ()
	{
		return derived ().init ();
	}
	void init ()
	{
		return;
	}

	// called during paint traverse
	bool _paint ()
	{
		return derived ().paint ();
	}
	bool paint ()
	{
		return false;
	}

	void _processCommandBeforePred (CUserCmd *pCommand)
	{
		return derived ().processCommandBeforePred (pCommand);
	}
	void processCommandBeforePred (CUserCmd *pCommand)
	{
		return;
	}

	// called during clientmode createmove - takes a CUserCMD
	void _processCommand (CUserCmd *pUserCmd)
	{
		return derived ().processCommand (pUserCmd);
	}
	void processCommand (CUserCmd *pUserCmd)
	{
		return;
	}

	// called during keyevent
	bool _keyEvent (ButtonCode_t keynum)
	{
		return derived ().keyEvent (keynum);
	}
	bool keyEvent (ButtonCode_t keynum)
	{
		return;
	}

	// the entity here will not be the local player
	// and it will not be null
	void _processEntity (CBaseEntity *pBaseEntity)
	{
		return derived ().processEntity (pBaseEntity);
	}
	void processEntity (CBaseEntity *pBaseEntity)
	{
		return;
	}

	// called on CBaseGameSystemPerFrame::Update which is called AFTER CL_Move
	void _perFrame ()
	{
		return derived ().perFrame ();
	}
	void perFrame ()
	{
		return;
	}
};