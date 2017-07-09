#pragma once

//#define __DEBUG
//#define __XOR
#include "ignorewarnings_on.h"

#include "baseHeaders.h"

#include "CGlobalVars.h"
#include "CSignature.h"
#include "Log.h"
#include "WeaponList.h"
//#include "Netvar.h"
#include "CEtags.h"
#include "CGlobalVars.h"
#include "CHookManager.h"
#include "DynamicNetvars.h"

#include "BaseAnimatingLayer.h"
#include "Material.h"
#include "ScreenSpaceEffectManager.h"
#include "clientstate.h"
#include "netmessage.h"
#include "network.h"
#include "prediction.h"
#include <iconvar.h>

class CGameTrace;
typedef CGameTrace trace_t;
struct Ray_t;
class CEngineTrace;
class IUniformRandomStream;
class CPlayerResource;

typedef void *(*InstallUniformRandomStreamFn) (IUniformRandomStream *pStream);

using namespace toolkit;

#pragma optimize("gsy", on)
#pragma warning(disable : 4244) // Possible loss of data

// typedef float matrix3x4[3][4];

// TODO: remove
typedef matrix3x4_t matrix3x4;

class CEntList
{
public:
	CBaseEntity *GetClientEntity (int entnum);

	CBaseEntity *GetClientEntityFromHandle (CBaseHandle hEnt);

	int GetHighestEntityIndex (void);
};

typedef struct player_info_s
{
	char          name[32];
	int           userID;
	char          guid[33];
	unsigned long friendsID;
	char          friendsName[32];
	bool          fakeplayer;
	bool          ishltv;
	unsigned long customFiles[4];
	unsigned char filesDownloaded;
} player_info_t;

class EngineClient
{
public:
	void GetScreenSize (int &width, int &height);

	bool GetPlayerInfo (int ent_num, player_info_t *pinfo);

	player_info_t GetPlayerInfo (int ent_num);

	int GetPlayerForUserID (int userid);

	bool Con_IsVisible (void);

	int GetLocalPlayer (void);

	float Time (void);

	void GetViewAngles (QAngle &va);

	void SetViewAngles (QAngle &va);

	int GetMaxClients (void);

	bool IsInGame (void);

	bool IsConnected (void);

	bool IsDrawingLoadingImage (void);

	const VMatrix &WorldToScreenMatrix (void);

	bool IsTakingScreenshot (void);

	CNetChan *GetNetChannelInfo (void);

	void ExecuteClientCmd (const char *chCommandString);

	void ClientCmd_Unrestricted (const char *chCommandString);

	void ServerCmdKeyValues (PVOID keyval);

	void ServerCmdKeyValues (KeyValues *keyval);

	const char *Key_BindingForKey (ButtonCode_t c);
};

class CPanel
{
public:
	const char *GetName (unsigned int vguiPanel);
};

class CSurface
{
public:
	void DrawSetColor (int r, int g, int b, int a);

	void DrawFilledRect (int x0, int y0, int x1, int y1);

	void DrawOutlinedRect (int x0, int y0, int x1, int y1);

	void DrawOutlinedCircle (int x, int y, int radius, int segments);

	void DrawLine (int x0, int y0, int x1, int y1);

	void DrawPolyLine (int *x, int *y, int n);

	void DrawSetTextFont (unsigned long font);

	void DrawSetTextColor (int r, int g, int b, int a);

	void DrawSetTextPos (int x, int y);

	void DrawPrintText (const wchar_t *text, int textLen);

	unsigned long CreateFont ();

	void SetFontGlyphSet (unsigned long &font, const char *windowsFontName, int tall, int weight, int blur, int scanlines, int flags);

	void GetTextSize (unsigned long font, const wchar_t *text, int &wide, int &tall);

	void GetTextSize (unsigned long font, const char *text, int &wide, int &tall);

	void PlaySound (const char *sound);

	void UnlockCursor ();

	void LockCursor ();

	bool IsCursorLocked ();

	void SetCursorAlwaysVisible (bool vis);

	void SurfaceGetCursorPos (int &x, int &y);

	void SetSoftwareCursor (bool t);
};

class IPhysicsSurfaceProps
{
public:
	virtual ~IPhysicsSurfaceProps (void)
	{
	}

	// parses a text file containing surface prop keys
	virtual int ParseSurfaceData (const char *pFilename, const char *pTextfile) = 0;
	// current number of entries in the database
	virtual int SurfacePropCount (void) const = 0;

	virtual int GetSurfaceIndex (const char *pSurfacePropName) const = 0;
	virtual void GetPhysicsProperties (int surfaceDataIndex, float *density, float *thickness, float *friction, float *elasticity) const = 0;

	virtual /*surfacedata_t*/ void *GetSurfaceData (int surfaceDataIndex) = 0;
	virtual const char *GetString (unsigned short stringTableIndex) const = 0;

	virtual const char *GetPropName (int surfaceDataIndex) const = 0;

	// sets the global index table for world materials
	virtual void SetWorldMaterialIndexTable (int *pMapArray, int mapSize) = 0;

	// NOTE: Same as GetPhysicsProperties, but maybe more convenient
	virtual void GetPhysicsParameters (int surfaceDataIndex, /*surfacephysicsparams_t*/ void *pParamsOut) const = 0;
};

class ClientModeShared
{
public:
	bool IsChatPanelOutOfFocus (void);
};

class CInput
{
public:
	// get the current cmd
	class CUserCmd *GetUserCmd (int seq);

	bool CAM_IsThirdPerson ();
};

class CHLClient
{
public:
	ClientClass *GetAllClasses (void);

	void GetRenderView (CViewSetup &viewSetup);

	void RenderView (CViewSetup const &, int, int);
};

class CGlobals
{
public:
	float realtime;
	int   framecount;
	float absoluteframetime;
	float curtime;
	float frametime;
	int   maxclients;
	int   tickcount;
	float interval_per_tick;
	float interpolation_amount;
};

class CModelInfo
{
public:
	const char *GetModelName (DWORD *model);

	DWORD *GetStudiomodel (DWORD *model);

	int GetModelMaterialCount (model_t *model);

	void GetModelMaterials (model_t *model, int count, IMaterial **ppMaterials);
};

class CInterfaces
{
public:
	// Client
	CHLClient *       Client;
	CEntList *        EntList;
	CPrediction *     Prediction;
	IGameMovement *   GameMovement;
	ClientModeShared *ClientMode;
	// nn_interface<IMoveHelper *> MoveHelper;

	// EngineClient 			*Engine;
	EngineClient *        Engine;
	CModelInfo *          ModelInfo;
	CModelRender *        ModelRender;
	CRenderView *         RenderView;
	CEngineTrace *        EngineTrace;
	CUniformRandomStream *RandomStream;
	IGameEventManager2 *  EventManager;
	IVDebugOverlay *      DebugOverlay;
	IEngineSound *        SoundEngine;
	CDemoPlayer *         DemoPlayer;
	CClientState *        ClientState;

	CSurface *Surface;

	CPanel *Panels;

	ICvar *Cvar;

	CInput *Input;

	CGlobals *Globals;

	IPhysicsSurfaceProps *PhysicsSurfaceProps;

	CMaterialSystem *MatSystem;

	IEngineVGui *EngineVGUI;

	IScreenSpaceEffectManager *ScreenSpaceEffectManager;

	static class ILagCompensationManager *LagCompensation;

	CSteamAPIContext SteamContext;

	CInterfaces ();

	// TODO: remove this when linxu
	HWND    thisWindow;
	WNDPROC oldWindowProc;
	HMODULE thisDll;
};
extern CInterfaces *gInts;

class CUserCmd
{
public:
	CUserCmd ()
	{
		command_number = 0;
		tick_count     = 0;
		viewangles.Init ();
		forwardmove      = 0.0f;
		sidemove         = 0.0f;
		upmove           = 0.0f;
		buttons          = 0;
		impulse          = 0;
		weaponselect     = 0;
		weaponsubtype    = 0;
		random_seed      = 0;
		mousedx          = 0;
		mousedy          = 0;
		hasbeenpredicted = false;
	}

	void copyFrom (const CUserCmd &src)
	{
		// command_number = src.command_number;
		tick_count    = src.tick_count;
		viewangles    = src.viewangles;
		forwardmove   = src.forwardmove;
		sidemove      = src.sidemove;
		upmove        = src.upmove;
		buttons       = src.buttons;
		impulse       = src.impulse;
		weaponselect  = src.weaponselect;
		weaponsubtype = src.weaponsubtype;
		// random_seed = src.random_seed;
		mousedx = src.mousedx;
		mousedy = src.mousedy;

		hasbeenpredicted = src.hasbeenpredicted;
	}

	virtual ~CUserCmd (){};  // Destructor 0
	int    command_number;   // 4
	int    tick_count;       // 8
	QAngle viewangles;       // C
	float  forwardmove;      // 18
	float  sidemove;         // 1C
	float  upmove;           // 20
	int    buttons;          // 24
	BYTE   impulse;          // 28
	int    weaponselect;     // 2C
	int    weaponsubtype;    // 30
	int    random_seed;      // 34
	short  mousedx;          // 38
	short  mousedy;          // 3A
	bool   hasbeenpredicted; // 3C;
};

class CVerifiedUserCmd
{
public:
	CUserCmd m_cmd;
	CRC32_t  m_crc;
};

class ICollideable
{
public:
	// Gets at the entity handle associated with the collideable
	virtual IHandleEntity *GetEntityHandle () = 0;

	// These methods return the bounds of an OBB measured in "collision" space
	// which can be retreived through the CollisionToWorldTransform or
	// GetCollisionOrigin/GetCollisionAngles methods
	virtual const Vector &OBBMinsPreScaled () const = 0;
	virtual const Vector &OBBMaxsPreScaled () const = 0;
	virtual const Vector &OBBMins () const          = 0;
	virtual const Vector &OBBMaxs () const          = 0;

	// Returns the bounds of a world-space box used when the collideable is being traced
	// against as a trigger. It's only valid to call these methods if the solid flags
	// have the FSOLID_USE_TRIGGER_BOUNDS flag set.
	virtual void WorldSpaceTriggerBounds (Vector *pVecWorldMins, Vector *pVecWorldMaxs) const = 0;

	// custom collision test
	virtual bool TestCollision (const Ray_t &ray, unsigned int fContentsMask, trace_t &tr) = 0;

	// Perform hitbox test, returns true *if hitboxes were tested at all*!!
	virtual bool TestHitboxes (const Ray_t &ray, unsigned int fContentsMask, trace_t &tr) = 0;

	// Returns the BRUSH model index if this is a brush model. Otherwise, returns -1.
	virtual int GetCollisionModelIndex () = 0;

	// Return the model, if it's a studio model.
	virtual const model_t *GetCollisionModel () = 0;

	// Get angles and origin.
	virtual const Vector &   GetCollisionOrigin () const        = 0;
	virtual const Vector &   GetCollisionAngles () const        = 0;
	virtual const matrix3x4 &CollisionToWorldTransform () const = 0;

	// Return a SOLID_ define.
	virtual /*SolidType_t*/ int GetSolid () const      = 0;
	virtual int                 GetSolidFlags () const = 0;

	// Gets at the containing class...
	virtual CBaseEntity *GetIClientUnknown () = 0;

	// We can filter out collisions based on collision group
	virtual int GetCollisionGroup () const = 0;

	// Returns a world-aligned box guaranteed to surround *everything* in the collision representation
	// Note that this will surround hitboxes, trigger bounds, physics.
	// It may or may not be a tight-fitting box and its volume may suddenly change
	virtual void WorldSpaceSurroundingBounds (Vector *pVecMins, Vector *pVecMaxs) = 0;

	virtual bool ShouldTouchTrigger (int triggerSolidFlags) const = 0;

	// returns NULL unless this collideable has specified FSOLID_ROOT_PARENT_ALIGNED
	virtual const matrix3x4 *GetRootParentToWorldTransform () const = 0;
};

class CBaseEntity
{
public:
	template <typename T>
	T get (DWORD off)
	{
		return *(typename std::remove_reference<T>::type *)((DWORD)this + off);
	}
	template <typename T>
	void set (DWORD off, T val)
	{
		(*(T *)((DWORD)this + off)) = val;
		return;
	}

	CBaseHandle GetRefEHandle ();

	ICollideable *GetCollideable ();

	Vector &GetAbsOrigin ();

	void SetAbsOrigin (Vector &o);

	QAngle &GetAbsAngles ();

	void SetAbsAngles (QAngle &a);

	void GetWorldSpaceCenter (Vector &vWorldSpaceCenter);

	bool IsBaseCombatWeapon ();

	bool Interpolate (float currentTime);

	DWORD *GetModel ();
	int DrawModel (int flags);

	class CStudioHdr *GetStudioHdr ();

	bool SetupBones (matrix3x4 *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime);

	ClientClass *GetClientClass ();

	bool IsDormant ();

	int GetIndex ();

	void GetRenderBounds (Vector &mins, Vector &maxs);

	QAngle &GetPrevLocalAngles ();

	int GetHealth ();

	BYTE GetLifeState ();

	bool IsAlive ();

	int GetTeam ();

	tf_classes GetClass ();

	int &GetFlags ();

	class CBaseCombatWeapon *GetActiveWeapon ();

	bool IsReadyToBackstab ();

	Vector &GetViewOffset ();

	Vector GetViewPos ();

	float GetChargeDamage ();

	int &GetTickBase ();

	float GetNextAttack ();

	float GetLastFireTime ();

	Vector &GetVelocity ();

	int &GetCond ();
	int &GetCondEx ();
	int &GetCondEx2 ();
	int &GetCondEx3 ();

	void SetCond (int c);

	bool IsZoomed ();

	void SetZoomed (bool state);

	QAngle &GetPunchAngles ();

	CBaseEntity *GetOwner ();

	moveTypes GetMoveType ();

	ICollideable *GetCollision ();

	matrix3x4 &GetRgflCoordinateFrame ();

	int GetRoundState ();

	int GetFov ();

	void SetFov (int fov);

	QAngle &GetRotation ();

	Vector &GetRenderOrigin ();

	float GetChargeTime ();

	float GetZoomTime ();

	float &GetAnimTime ();
	float &GetOldAnimTime ();

	float &GetSimulationTime ();
	float &GetOldSimulationTime ();

	void SetSimulationTime (float t);

	int GetItemDefinitionIndex ();

	Vector &GetCollideableMinsPrescaled ();

	Vector &GetCollideableMaxsPrescaled ();

	Vector &GetCollideableMins ();

	Vector &GetCollideableMaxs ();

	CBaseEntity *GetGroundEntity ();

	bool IsTouchingGround ();

	float GetMaxSpeed ();

	int &GetSequence ();
	void SetSequence (int seq);

	float &GetCycle ();
	void SetCycle (int cyc);

	float &GetPlaybackRate ();

	C_AnimationLayer *GetAnimOverlay (int index);

	int GetNumAnimOverlays ();

	void SetSize (Vector &mins, Vector &maxs);

	QAngle GetEyeAngles ();
	void SetEyeAngles (QAngle ang);

	bool UseClassAnimations ();

	Vector &GetCustomModelOffset ();

	bool    GetCustomModelRotates ();
	bool    GetCustomModelRotationSet ();
	QAngle &GetCustomModelRotation ();

	float &GetModelScale ();

	bool  IsCritBoosted ();
	float GetCritMult ();
	float GetAttributeFloat (float value, const char *attrib);
	float GetObservedCritChance ();

	bool IsEffectActive (int effects);

	int GetModelIndex ();

	int &GetObserverMode ();
};

// allows upcasting without showing casts
#define DEFINE_FROM_BASEENTITY(type)                \
	static type *FromBaseEntity (CBaseEntity *pEnt) \
	{                                               \
		return (type *)pEnt;                        \
	}

class CBaseCombatWeapon : public CBaseEntity
{
public:
	DEFINE_FROM_BASEENTITY (CBaseCombatWeapon);

	int Clip1 ();

	int Clip2 ();

	int GetMaxClip1 ();

	int GetMaxClip2 ();

	int GetSlot ();

	char *GetName ();

	char *GetPrintName ();

	Vector &GetBulletSpread ();

	int         GetWeaponID ();
	const char *GetWeaponAlias ();

	struct WeaponData_t *GetWeaponData ();

	float GetProjectileSpeed ();
	float GetProjectileGravity ();
};

class CTFBaseWeapon : public CBaseCombatWeapon
{
public:
	// TODO impl necessary functions here
	DEFINE_FROM_BASEENTITY (CTFBaseWeapon);
};

class CTFBaseWeaponGun : public CTFBaseWeapon
{
public:
	DEFINE_FROM_BASEENTITY (CTFBaseWeaponGun);

	float WeaponGetSpread ();
};

class CBaseCombatCharacter : public CBaseEntity
{
public:
	DEFINE_FROM_BASEENTITY (CBaseCombatCharacter);
	// tested
	void UpdateGlowEffect ();

	void DestroyGlowEffect ();

	bool IsGlowEnabled ();

	void SetGlowEnabled (bool t);
};

class CTFBaseWeaponMelee : public CTFBaseWeapon
{
public:
	DEFINE_FROM_BASEENTITY (CTFBaseWeaponMelee);

	bool DoSwingTrace (trace_t &trace);

	// unused
private:
	bool CalcIsAttackCriticalHelper ();
};

class CObject : public CBaseEntity
{
public:
	int GetLevel ();

	bool IsSapped ();

	bool IsBuilding ();

	float GetPercentageConstructed ();

	int GetHealth ();

	int GetUpgradedMetal ();
};

class CObjectDispenser : public CObject
{
public:
	int GetMetalReserve ();
};

class CObjectSentryGun : public CObject
{
public:
	int GetRocket ();

	int GetAmmo ();

	bool IsControlled ();

	int GetState ();

	const char *GetStateString ();
};

class CObjectTeleporter : public CObject
{
public:
	int GetState ();

	const char *GetStateString ();
};
// extern playerVars_t gLocalPlayerVars;

class CHack;
extern CHack gHack;

//#include "CHack.h"

// doesnt do the running, for use on hack classes
// resulting function name is RecurseCall<name>
#define DEFINE_RECURSE_CALL_FUNCTION_NO_ARGS(name)                    \
	template <typename T>                                             \
	__forceinline void RecurseCall##name (T &curr)                    \
	{                                                                 \
		curr.name ();                                                 \
	}                                                                 \
	template <typename T, typename... Args_t>                         \
	__forceinline void RecurseCall##name (T &curr, Args_t &... other) \
	{                                                                 \
		curr.name ();                                                 \
		RecurseCall##name (other...);                                 \
	}
#define DEFINE_RECURSE_CALL_FUNCTION_1_ARG(name, type1)                         \
	template <typename T>                                                       \
	__forceinline void RecurseCall##name (type1 a1, T &curr)                    \
	{                                                                           \
		curr.name (a1);                                                         \
	}                                                                           \
	template <typename T, typename... Args_t>                                   \
	__forceinline void RecurseCall##name (type1 a1, T &curr, Args_t &... other) \
	{                                                                           \
		curr.name (a1);                                                         \
		RecurseCall##name (a1, other...);                                       \
	}
#define DEFINE_RECURSE_CALL_FUNCTION_2_ARG(name, type1, type2)                            \
	template <typename T>                                                                 \
	__forceinline void RecurseCall##name (type1 a1, type2 a2, T &curr)                    \
	{                                                                                     \
		curr.name (a1, a2);                                                               \
	}                                                                                     \
	template <typename T, typename... Args_t>                                             \
	__forceinline void RecurseCall##name (type1 a1, type2 a2, T &curr, Args_t &... other) \
	{                                                                                     \
		curr.name (a1, a2);                                                               \
		RecurseCall##name (a1, a2, other...);                                             \
	}

#include "ignorewarnings_off.h"
