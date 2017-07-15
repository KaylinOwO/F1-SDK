#include "../SDK/Util.h"

CRC32_t GetChecksumForCmd (CUserCmd userCmd)
{
	CRC32_t crc;

	CRC32_Init (&crc);
	CRC32_ProcessBuffer (&crc, &userCmd.command_number, sizeof (userCmd.command_number));
	CRC32_ProcessBuffer (&crc, &userCmd.tick_count, sizeof (userCmd.tick_count));
	CRC32_ProcessBuffer (&crc, &userCmd.viewangles, sizeof (userCmd.viewangles));
	CRC32_ProcessBuffer (&crc, &userCmd.forwardmove, sizeof (userCmd.forwardmove));
	CRC32_ProcessBuffer (&crc, &userCmd.sidemove, sizeof (userCmd.sidemove));
	CRC32_ProcessBuffer (&crc, &userCmd.upmove, sizeof (userCmd.upmove));
	CRC32_ProcessBuffer (&crc, &userCmd.buttons, sizeof (userCmd.buttons));
	CRC32_ProcessBuffer (&crc, &userCmd.impulse, sizeof (userCmd.impulse));
	CRC32_ProcessBuffer (&crc, &userCmd.weaponselect, sizeof (userCmd.weaponselect));
	CRC32_ProcessBuffer (&crc, &userCmd.weaponsubtype, sizeof (userCmd.weaponsubtype));
	CRC32_ProcessBuffer (&crc, &userCmd.random_seed, sizeof (userCmd.random_seed));
	CRC32_ProcessBuffer (&crc, &userCmd.mousedx, sizeof (userCmd.mousedx));
	CRC32_ProcessBuffer (&crc, &userCmd.mousedy, sizeof (userCmd.mousedy));
	CRC32_Final (&crc);

	return crc;
}

void allocConsole ()
{
	static bool alloced;

	if (!alloced) {
		if (!AllocConsole ()) {
			Log::Error ("Alloc console failed.");
		} else {
			alloced = true;

			// reopen the i/o streams with the new console
			freopen ("CONOUT$", "w", stdout);
			freopen ("CONOUT$", "w", stderr);
		}
	}
}

// assumes the entity is valid
bool bulletTime (CBaseEntity *pLocalEntity)
{

	int tickBase = pLocalEntity->GetTickBase ();

	CBaseEntity *pLocalWeapon = pLocalEntity->GetActiveWeapon ();

	if (pLocalWeapon == nullptr)
		return false;

	float nextAttack = pLocalWeapon->GetNextAttack ();

	bool canTickbase = nextAttack >= TICKS_TO_TIME (tickBase);

	// bool canCurTime = nextAttack > tickBase * interval;

	// Log::Console("bullettime? tickbase: %s curTime: %s", canTickbase ? "true"
	// : "false", canCurTime ? "true" : "false");

	return canTickbase;
}

void generateItemList ()
{
	printf ("enum class classId : int\n{\n");
	for (ClientClass *pCC = gInts->Client->GetAllClasses (); pCC; pCC = pCC->nextClass) {
		printf ("\t%s = %i,\n", pCC->name, pCC->classId);
	}

	printf ("};");
}

Vector EstimateAbsVelocity (CBaseEntity *ent)
{
	typedef void(__thiscall * EstimateAbsVelocityFn) (CBaseEntity *, Vector &);

	static DWORD dwFn =
	    gSignatures.GetClientSignature (
	        "E8 ? ? ? ? F3 0F 10 4D ? 8D 85 ? ? ? ? F3 0F 10 45 ? F3 0F 59 C9 "
	        "56 F3 0F 59 C0 F3 0F 58 C8 0F 2F 0D ? ? ? ? 76 07") +
	    0x1;

	static DWORD dwEstimate = ((*(PDWORD) (dwFn)) + dwFn + 4);

	EstimateAbsVelocityFn vel = (EstimateAbsVelocityFn)dwEstimate;

	Vector v;
	vel (ent, v);

	return v;
}

// TODO: move this
DWORD WINAPI killCvars (LPVOID param)
{
	ConCommandBase *c = gInts->Cvar->GetCommands ();

	int count = 0;

	// set all flags to 0
	while (c) {
		// TODO fix masking
		// maskCvar("tf", (ConVar *)base);

		if (c->m_nFlags & FCVAR_CHEAT)
			c->m_nFlags &= ~FCVAR_CHEAT;

		if (c->m_nFlags & FCVAR_REPLICATED)
			c->m_nFlags &= ~FCVAR_REPLICATED;

		if (c->m_nFlags & FCVAR_PROTECTED)
			c->m_nFlags &= ~FCVAR_PROTECTED;

		if (c->m_nFlags & FCVAR_SPONLY) // single player only
			c->m_nFlags &= ~FCVAR_SPONLY;

		if (c->m_nFlags & FCVAR_HIDDEN)
			c->m_nFlags &= ~FCVAR_HIDDEN;

		if (c->m_nFlags & FCVAR_DEVELOPMENTONLY)
			c->m_nFlags &= ~FCVAR_DEVELOPMENTONLY;

		if (c->m_nFlags & FCVAR_NOT_CONNECTED)
			c->m_nFlags &= ~FCVAR_NOT_CONNECTED;

		if (ConVar *cc = dynamic_cast<ConVar *> (c)) {
			cc->m_bHasMax = false;
			cc->m_bHasMin = false;
		}

		c = c->GetNext ();
		count++;
	}

	gInts->Cvar->ConsolePrintf ("Unprotected %d cvars\n", count);

	return 0;
}

int getMaxHealth (tf_classes Class)
{
	switch (Class) {
	case tf_classes::TF2_Scout:
		return 125;
	case tf_classes::TF2_Sniper:
		return 125;
	case tf_classes::TF2_Soldier:
		return 200;
	case tf_classes::TF2_Demoman:
		return 175;
	case tf_classes::TF2_Medic:
		return 150;
	case tf_classes::TF2_Heavy:
		return 300;
	case tf_classes::TF2_Pyro:
		return 175;
	case tf_classes::TF2_Spy:
		return 125;
	case tf_classes::TF2_Engineer:
		return 125;
	default:
		return 100;
	}
}

const char *GetTFClassName (tf_classes Class)
{
	switch (Class) {
	case tf_classes::TF2_Invalid:
		return "Invalid";
		break;
	case tf_classes::TF2_Scout:
		return "Scout";
		break;
	case tf_classes::TF2_Sniper:
		return "Sniper";
		break;
	case tf_classes::TF2_Soldier:
		return "Soldier";
		break;
	case tf_classes::TF2_Demoman:
		return "Demoman";
		break;
	case tf_classes::TF2_Medic:
		return "Medic";
		break;
	case tf_classes::TF2_Heavy:
		return "Heavy";
		break;
	case tf_classes::TF2_Pyro:
		return "Pyro";
		break;
	case tf_classes::TF2_Spy:
		return "Spy";
		break;
	case tf_classes::TF2_Engineer:
		return "Engineer";
		break;
	default:
		return "Invalid";
	}
}

std::string getPathForDll (HMODULE module)
{
	std::string ret;

	char path[MAX_PATH];

	if (GetModuleFileNameA (module, path, MAX_PATH) != 0) {
		size_t slash = (size_t)-1;

		for (size_t i = 0; i < strlen (path); i++) {
			if (path[i] == '/' || path[i] == '\\') {
				slash = i;
			}
		}

		if (slash != -1) {
			path[slash + 1] = '\0';
			ret             = path;
		} else {
			Log::Error ("unable to get path for dll selected");
		}
	}
	return ret;
}

void VectorTransform (Vector &in1, const matrix3x4 &in2, Vector &out)
{
	out[0] = (in1[0] * in2[0][0] + in1[1] * in2[0][1] + in1[2] * in2[0][2]) + in2[0][3];
	out[1] = (in1[0] * in2[1][0] + in1[1] * in2[1][1] + in1[2] * in2[1][2]) + in2[1][3];
	out[2] = (in1[0] * in2[2][0] + in1[1] * in2[2][1] + in1[2] * in2[2][2]) + in2[2][3];
}

DWORD redGreenGradiant (float percent)
{
	if (percent < 0) {
		return COLORCODE (255, 0, 0, 255);
	}

	int r = 0, g = 0, b = 0;
	if (percent > 1) {
		g = 255;
		b = (int)(255 * (percent - 1) / 0.5);
	} else if (percent < 0.5) {
		r = 255;
		g = (int)(255 * percent / 0.5); // closer to 0.5, closer to yellow (255,255,0)
	} else {
		g = 255;
		r = 255 - (int)(255 * (percent - 0.5) / 0.5); // closer to 1.0, closer to green (0,255,0)
	}
	return COLORCODE (r, g, b, 255);
}

DWORD redGreenGradiant (int i, int max)
{
	float percent = float(i) / float(max);
	return redGreenGradiant (percent);
}

mstudiohitboxset_t *GetHitboxset (DWORD *pHeader)
{
	int HitboxSetIndex = *(int *)((DWORD)pHeader + 0xB0);
	return (mstudiohitboxset_t *)(((PBYTE)pHeader) + HitboxSetIndex);
}

mstudiobbox_t *GetHitbox (int iHitbox, DWORD *pHeader)
{
	return GetHitboxset (pHeader)->pHitbox (iHitbox);
}

int GetNumHitboxes (CBaseEntity *ent)
{
	// OPTIMISE:
	auto *model   = ent->GetModel ();
	auto *pHeader = gInts->ModelInfo->GetStudiomodel (model);

	int                 HitboxSetIndex = *(int *)((DWORD)pHeader + 0xB0);
	mstudiohitboxset_t *pSet           = (mstudiohitboxset_t *)(((PBYTE)pHeader) + HitboxSetIndex);
	return pSet->numhitboxes;
}

//-----------------------------------------------------------------------------
// class CFlaggedEntitiesEnum
//-----------------------------------------------------------------------------

CFlaggedEntitiesEnum::CFlaggedEntitiesEnum (CBaseEntity **pList, int listMax, int flagMask)
{
	m_pList    = pList;
	m_listMax  = listMax;
	m_flagMask = flagMask;
	m_count    = 0;
}

bool CFlaggedEntitiesEnum::AddToList (CBaseEntity *pEntity)
{
	if (m_count >= m_listMax) {
		//AssertMsgOnce (0, "reached enumerated list limit.  Increase limit, decrease radius, or make it so entity flags will work for you");
		Log::Console ("Enumeration limit reached.");
		return false;
	}
	m_pList[m_count] = pEntity;
	m_count++;
	return true;
}

IterationRetval_t CFlaggedEntitiesEnum::EnumElement (IHandleEntity *pHandleEntity)
{
	CBaseEntity *pEntity = GetBaseEntity (pHandleEntity);
	if (pEntity) {
		if (m_flagMask && !(pEntity->GetFlags () & m_flagMask)) // Does it meet the criteria?
			return ITERATION_CONTINUE;

		if (!AddToList (pEntity))
			return ITERATION_STOP;
	}

	return ITERATION_CONTINUE;
}

int UTIL_EntitiesInBox (const Vector &mins, const Vector &maxs, CFlaggedEntitiesEnum *pEnum)
{
	gInts->Partition->EnumerateElementsInBox (PARTITION_ENGINE_NON_STATIC_EDICTS, mins, maxs, false, pEnum);
	return pEnum->GetCount ();
}

int UTIL_EntitiesAlongRay (const Ray_t &ray, CFlaggedEntitiesEnum *pEnum)
{
	gInts->Partition->EnumerateElementsAlongRay (PARTITION_ENGINE_NON_STATIC_EDICTS, ray, false, pEnum);
	return pEnum->GetCount ();
}

int UTIL_EntitiesInSphere (const Vector &center, float radius, CFlaggedEntitiesEnum *pEnum)
{
	gInts->Partition->EnumerateElementsInSphere (PARTITION_ENGINE_NON_STATIC_EDICTS, center, radius, false, pEnum);
	return pEnum->GetCount ();
}

int  CUtil::mouseState     = 1;
bool CUtil::cursorVisible  = false;
bool CUtil::softwareCursor = false;

bool CUtil::isPlayer (CBaseEntity *pBaseEntity)
{
	return false;
}

F1_Point CUtil::getMousePos ()
{
	F1_Point xy{0, 0};
	gInts->Surface->SurfaceGetCursorPos (xy.x, xy.y);
	return xy;
}

// This does what the SDK does, whether that be bad or good
extern void GetBoneTransform (int index, int iBone, matrix3x4_t &pBoneToWorld);

void GetBonePosition (int index, int iBone, Vector &origin, QAngle &angles)
{
	matrix3x4_t bonetoworld;
	GetBoneTransform (index, iBone, bonetoworld);

	MatrixAngles (bonetoworld, angles, origin);
}

static Vector hullcolor[8] = {
    Vector (1.0, 1.0, 1.0), Vector (1.0, 0.5, 0.5), Vector (0.5, 1.0, 0.5),
    Vector (1.0, 1.0, 0.5), Vector (0.5, 0.5, 1.0), Vector (1.0, 0.5, 1.0),
    Vector (0.5, 1.0, 1.0), Vector (1.0, 1.0, 1.0)};

void DrawClientHitboxes (CBaseEntity *pBaseEntity, float duration, bool monocolor)
{
	DWORD *pStudioHdr = gInts->ModelInfo->GetStudiomodel (pBaseEntity->GetModel ());
	if (!pStudioHdr)
		return;

	mstudiohitboxset_t *set = GetHitboxset (pStudioHdr);
	if (!set)
		return;

	Vector position;
	QAngle angles;

	int r = 255;
	int g = 0;
	int b = 0;

	for (int i = 0; i < set->numhitboxes; i++) {
		mstudiobbox_t *pbox = set->pHitbox (i);

		GetBonePosition (pBaseEntity->GetIndex (), pbox->bone, position, angles);

		if (!monocolor) {
			int j = (pbox->group % 8);
			r     = (int)(255.0f * hullcolor[j][0]);
			g     = (int)(255.0f * hullcolor[j][1]);
			b     = (int)(255.0f * hullcolor[j][2]);
		}

		gInts->DebugOverlay->AddBoxOverlay (position, pbox->bbmin, pbox->bbmax, angles, r, g, b, 0, duration);
	}
}
