#pragma once

#include "../SDK/SDK.h"

CRC32_t GetChecksumForCmd (CUserCmd userCmd);

void allocConsole ();

// assumes the entity is valid
bool bulletTime (const CBaseEntity *pLocalEntity);

void generateItemList ();

Vector EstimateAbsVelocity (CBaseEntity *ent);

// TODO: move this
DWORD WINAPI killCvars (LPVOID param);

int getMaxHealth (tf_classes Class);

const char *GetTFClassName (tf_classes Class);

std::string getPathForDll (HMODULE module);

// TODO: isnt this in the mathlib
void VectorTransform (Vector &in1, const matrix3x4 &in2, Vector &out);

DWORD redGreenGradiant (float percent);

DWORD redGreenGradiant (int i, int max);

mstudiohitboxset_t *GetHitboxset (studiohdr_t *pHeader);

mstudiobbox_t *GetHitbox (int iHitbox, studiohdr_t *pHeader);

int GetNumHitboxes (CBaseEntity *ent);

// SDK rip for getting entites from the partition manager
class CFlaggedEntitiesEnum : public IPartitionEnumerator
{
public:
	CFlaggedEntitiesEnum (CBaseEntity **pList, int listMax, int flagMask);

	// This gets called	by the enumeration methods with each element
	// that passes the test.
	virtual IterationRetval_t EnumElement (IHandleEntity *pHandleEntity);

	int GetCount ()
	{
		return m_count;
	}
	bool AddToList (CBaseEntity *pEntity);

private:
	CBaseEntity **m_pList;
	int           m_listMax;
	int           m_flagMask;
	int           m_count;
};

// Pass in an array of pointers and an array size, it fills the array and returns the number inserted
int UTIL_EntitiesInBox (const Vector &mins, const Vector &maxs, CFlaggedEntitiesEnum *pEnum);
int UTIL_EntitiesAlongRay (const Ray_t &ray, CFlaggedEntitiesEnum *pEnum);
int UTIL_EntitiesInSphere (const Vector &center, float radius, CFlaggedEntitiesEnum *pEnum);

inline int UTIL_EntitiesInBox (CBaseEntity **pList, int listMax, const Vector &mins, const Vector &maxs, int flagMask)
{
	CFlaggedEntitiesEnum boxEnum (pList, listMax, flagMask);
	return UTIL_EntitiesInBox (mins, maxs, &boxEnum);
}

inline int UTIL_EntitiesAlongRay (CBaseEntity **pList, int listMax, const Ray_t &ray, int flagMask)
{
	CFlaggedEntitiesEnum rayEnum (pList, listMax, flagMask);
	return UTIL_EntitiesAlongRay (ray, &rayEnum);
}

inline int UTIL_EntitiesInSphere (CBaseEntity **pList, int listMax, const Vector &center, float radius, int flagMask)
{
	CFlaggedEntitiesEnum sphereEnum (pList, listMax, flagMask);
	return UTIL_EntitiesInSphere (center, radius, &sphereEnum);
}

#include "F1_Gui.h"

// TODO: dont do this
// either make this an entire singleton
// or make everything global functions
class CUtil
{
public:
	static int  mouseState;
	static bool cursorVisible;
	static bool softwareCursor;

	// 0 for locked, 1 for unlocked
	static void setMouseState (int state)
	{
		mouseState = state;
	}
	static void setCursorVisible (bool visible)
	{
		cursorVisible = visible;
	}
	static void setSoftwareCursor (bool enabled)
	{
		if (softwareCursor == false)
			softwareCursor = true;
	}

	static bool isPointWithinRange (F1_Point p, F1_Point xy, F1_Point wh)
	{
		return ((p.x > xy.x) && (p.y > xy.y) && (p.x < (xy.x + wh.x)) && (p.y < (xy.y + wh.y)));
	}

	// ai or real player (robot or not)
	static bool isPlayer (CBaseEntity *pBaseEntity);

	static F1_Point getMousePos ();
};

void DrawClientHitboxes (const CBaseEntity *pBaseEntity, float duration, bool monocolor);
