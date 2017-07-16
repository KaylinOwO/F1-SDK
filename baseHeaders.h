#pragma once

// base, common and standalone headers are defined here

// auto define lean and mean
#define WIN32_LEAN_AND_MEAN
#undef min
#undef max
#include "WindowsProxy.h"
#include <algorithm>
#include <cstdarg>
#include <float.h>
#include <fstream>
#include <math.h>
#include <memory>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>
//#include <vld.h>

// SOURCE SDK COMES FIRST
#include "SourceSDK.h"

// DEFINE OVERRIDES HERE
// use SSE2 for fast sqrt's
__forceinline float fsqrtf (float x)
{
#if !defined(F1_GCC)
	// we should be able to get NRVO here
	// it should be inlined anyway
	float root = 0.0f;
	__asm
	{
		sqrtss xmm0, x;
		movss root, xmm0;
	}
	return root;
#else
	return sqrtf (x);
#endif
}
//#define sqrtf( x ) fsqrtf( x )

__forceinline float SinFast (float x)
{
	float s, c;
	SinCos (DEG2RAD (x), &s, &c);

	return s;
}
__forceinline float CosFast (float x)
{
	float s, c;
	SinCos (DEG2RAD (x), &s, &c);

	return c;
}

#define sin SinFast
#define cos CosFast

__forceinline void SinCosDeg (float deg, float &s, float &c)
{
	return SinCos (DEG2RAD (deg), &s, &c);
}

#define SinCos SinCosDeg

#include "commonEnums.h"

#include "CGlobalVars.h"
#include "ClassId.h"
#include "VMTHooks.h"
#include "dt_recv2.h"
#include "factory.h"
#include "getvfunc.h"

// xorstring stuff
#ifdef __XOR
#include "XorString.h" // compile time string encryption
#else
#define XorString(X) X
#define XorS(X, String) String
#endif

// moved out of sdk.h
class ClientClass
{
private:
	void *createFn;
	void *createEventFn; // Only called for event objects.

public:
	char *       name;
	RecvTable *  table;
	ClientClass *nextClass;
	classId      classId;
};

// TODO: move to common enums
enum
{
	FLOW_OUTGOING = 0,
	FLOW_INCOMING,
	MAX_FLOWS   = 2, // in & out
	MAX_STREAMS = 2,
};

#define MAX_OSPATH 260

enum
{
	SUBCHANNEL_FREE = 0, // subchannel is free to use
	SUBCHANNEL_TOSEND,   // subchannel has data, but not send yet
	SUBCHANNEL_WAITING,  // sbuchannel sent data, waiting for ACK
	SUBCHANNEL_DIRTY,    // subchannel is marked as dirty during changelevel
};

// typedef DWORD IDemoRecorder;
typedef void *FileHandle_t;
typedef int   QueryCvarCookie_t;

typedef enum {
	NA_NULL = 0,
	NA_LOOPBACK,
	NA_BROADCAST,
	NA_IP,
} netadrtype_t;

typedef enum {
	eQueryCvarValueStatus_ValueIntact   = 0, // It got the value fine.
	eQueryCvarValueStatus_CvarNotFound  = 1,
	eQueryCvarValueStatus_NotACvar      = 2, // There's a ConCommand, but it's not a ConVar.
	eQueryCvarValueStatus_CvarProtected = 3  // The cvar was marked with FCVAR_SERVER_CAN_NOT_QUERY, so the server is not allowed to have its value.
} EQueryCvarValueStatus;

// TODO: why is this here
inline void quickCrash ()
{
	// volatile ensures that it gets compiled
	volatile int x = 0;
	*(int *)x      = 10;
}

// TODO: remove
//#define me gInts->Engine->GetLocalPlayerIndex ()

// some helper functions for less typing
// TODO: these should really be defined in SDK.h
CBaseEntity *GetBaseEntity (int index);
CBaseEntity *GetBaseEntity (CHandle<CBaseEntity> handle);
CBaseEntity *GetBaseEntity (IHandleEntity *handle);
CBaseEntity *GetLocalPlayer ();

enum HitboxMasks
{
	MASK_AIMBOT        = 0x200400B,
	CASUAL_HACKER_MASK = 0x4600400B,
};

#define PI M_PI
#define RADPI 57.295779513082f

enum tf_teams
{
	SPECTATOR,
	TEAM_1,
	RED_TEAM,
	BLU_TEAM,
	TEAM_4,
};

__forceinline DWORD RESOLVE_CALLGATE (DWORD dwLocation)
{
	return ((*(PDWORD) (dwLocation)) + dwLocation + 4);
}

#define RED(COLORCODE) ((int)(COLORCODE >> 24))
#define BLUE(COLORCODE) ((int)(COLORCODE >> 8) & 0xFF)
#define GREEN(COLORCODE) ((int)(COLORCODE >> 16) & 0xFF)
#define ALPHA(COLORCODE) ((int)COLORCODE & 0xFF)
#define COLORCODE(r, g, b, a) ((DWORD) ((((r)&0xff) << 24) | (((g)&0xff) << 16) | (((b)&0xff) << 8) | ((a)&0xff)))

#include "../SDK/backtrace.h"
