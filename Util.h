#pragma once

#include "../SDK/SDK.h"

CRC32_t GetChecksumForCmd (CUserCmd userCmd);

void allocConsole ();

// assumes the entity is valid
bool bulletTime (CBaseEntity *pLocalEntity);

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

mstudiohitboxset_t *GetHitboxset (DWORD *pHeader);

mstudiobbox_t *GetHitbox (int iHitbox, DWORD *pHeader);

int GetNumHitboxes (CBaseEntity *ent);

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

void DrawClientHitboxes (CBaseEntity *pBaseEntity, float duration, bool monocolor);
