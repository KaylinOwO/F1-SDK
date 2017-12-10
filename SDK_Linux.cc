#include "baseHeaders.hh"

#include "../SDK/SDK.hh"

#include "../SDK/Util.hh"

#include <array>

#undef GetProp

#if !defined(_MSC_VER)

// ----------------------------------------------------------------------------
// Interfaces
// ----------------------------------------------------------------------------

CBaseEntity *CEntList::GetClientEntity (int entnum)
{
	typedef CBaseEntity *(__thiscall * OriginalFn) (PVOID, int);
	return getvfunc<OriginalFn> (this, 3) (this, entnum);
}

CBaseEntity *CEntList::GetClientEntityFromHandle (CBaseHandle hEnt)
{
	typedef CBaseEntity *(__thiscall * OriginalFn) (PVOID, CBaseHandle);
	return getvfunc<OriginalFn> (this, 4) (this, hEnt);
}

int CEntList::GetHighestEntityIndex ()
{
	typedef int(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 6) (this);
}

void EngineClient::GetScreenSize (int &width, int &height)
{
	// call the engine function
	typedef void(__thiscall * OriginalFn) (PVOID, int &, int &);
	getvfunc<OriginalFn> (this, 5) (this, width, height);

	// if we are fullscreen these will be 0
	// if(width == 0 || height == 0)
	//{
	//	RECT size;

	//	memset( &size, 0, sizeof( size ) );

	//	HWND tfWindow;

	//	while( ( tfWindow = FindWindow( "Valve001", NULL ) ) == false ) Sleep( 200 );

	//	if( tfWindow == NULL )
	//	{
	//		Log::Fatal( "We have failed." );
	//	}

	//	GetWindowRect( tfWindow, &size);

	//	width  = size.right - size.left;
	//	height = size.bottom - size.top;

	//	Log::Console("Right: %d, Left: %d", size.right, size.left);
	//	Log::Console("Bottom: %d, Top: %d", size.bottom, size.top);

	//	Log::Console("Height: %d, width: %d", height, width);
	//}
}

bool EngineClient::GetPlayerInfo (int ent_num, player_info_t *pinfo)
{
	typedef bool(__thiscall * OriginalFn) (PVOID, int, player_info_t *);
	return getvfunc<OriginalFn> (this, 8) (this, ent_num, pinfo);
}

player_info_t EngineClient::GetPlayerInfo (int ent_num)
{
	player_info_t tempInfo;
	GetPlayerInfo (ent_num, &tempInfo);
	return tempInfo;
}

bool EngineClient::Con_IsVisible ()
{
	typedef bool(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 11) (this);
}

int EngineClient::GetLocalPlayerIndex ()
{
	typedef int(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 12) (this);
}

float EngineClient::Time ()
{
	typedef float(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 14) (this);
}

void EngineClient::GetViewAngles (QAngle &va)
{
	typedef void(__thiscall * OriginalFn) (PVOID, QAngle &);
	return getvfunc<OriginalFn> (this, 19) (this, va);
}

void EngineClient::SetViewAngles (QAngle &va)
{
	typedef void(__thiscall * OriginalFn) (PVOID, QAngle &);
	return getvfunc<OriginalFn> (this, 20) (this, va);
}

int EngineClient::GetMaxClients ()
{
	typedef int(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 21) (this);
}

bool EngineClient::IsInGame ()
{
	typedef bool(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 26) (this);
}

bool EngineClient::IsConnected ()
{
	typedef bool(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 27) (this);
}

bool EngineClient::IsDrawingLoadingImage ()
{
	typedef bool(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 28) (this);
}

const matrix3x4 &EngineClient::WorldToScreenMatrix ()
{
	typedef const matrix3x4 &(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 36) (this);
}

bool EngineClient::IsTakingScreenshot ()
{
	typedef bool(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 85) (this);
}

CNetChan *EngineClient::GetNetChannelInfo ()
{
	typedef CNetChan *(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 72) (this);
}

void EngineClient::ExecuteClientCmd (const char *chCommandString)
{
	typedef void(__thiscall * OriginalFn) (PVOID, const char *);
	return getvfunc<OriginalFn> (this, 102) (this, chCommandString);
}

void EngineClient::ClientCmd_Unrestricted (const char *chCommandString)
{
	typedef void(__thiscall * OriginalFn) (PVOID, const char *);
	return getvfunc<OriginalFn> (this, 106) (this, chCommandString);
}

void EngineClient::ServerCmdKeyValues (PVOID keyval)
{
	typedef void(__thiscall * OriginalFn) (PVOID, PVOID);
	return getvfunc<OriginalFn> (this, 127) (this, keyval);
}

void EngineClient::ServerCmdKeyValues (KeyValues *keyval)
{
	// call the other one
	return ServerCmdKeyValues ((PVOID)keyval);
}

const char *EngineClient::Key_BindingForKey (ButtonCode_t c)
{
	typedef const char *(__thiscall * OriginalFn) (PVOID, ButtonCode_t);
	return getvfunc<OriginalFn> (this, 23) (this, c);
}

const char *CPanel::GetName (unsigned vguiPanel)
{
	typedef const char *(__thiscall * OriginalFn) (PVOID, unsigned int);
	return getvfunc<OriginalFn> (this, 37) (this, vguiPanel);
}

void CSurface::DrawSetColor (int r, int g, int b, int a)
{
	typedef void(__thiscall * OriginalFn) (PVOID, int, int, int, int);
	getvfunc<OriginalFn> (this, 10) (this, r, g, b, a);
}

void CSurface::DrawFilledRect (int x0, int y0, int x1, int y1)
{
	typedef void(__thiscall * OriginalFn) (PVOID, int, int, int, int);
	getvfunc<OriginalFn> (this, 12) (this, x0, y0, x1, y1);
}

void CSurface::DrawOutlinedRect (int x0, int y0, int x1, int y1)
{
	typedef void(__thiscall * OriginalFn) (PVOID, int, int, int, int);
	getvfunc<OriginalFn> (this, 14) (this, x0, y0, x1, y1);
}

void CSurface::DrawOutlinedCircle (int x, int y, int radius, int segments)
{
	typedef void(__thiscall * OriginalFn) (PVOID, int, int, int, int);
	return getvfunc<OriginalFn> (this, 99) (this, x, y, radius, segments);
}

void CSurface::DrawLine (int x0, int y0, int x1, int y1)
{
	typedef void(__thiscall * OriginalFn) (PVOID, int, int, int, int);
	getvfunc<OriginalFn> (this, 15) (this, x0, y0, x1, y1);
}

void CSurface::DrawPolyLine (int *x, int *y, int n)
{
	typedef void(__thiscall * OriginalFn) (PVOID, int *, int *, int);
	getvfunc<OriginalFn> (this, 16) (this, x, y, n);
}

void CSurface::DrawSetTextFont (unsigned long font)
{
	typedef void(__thiscall * OriginalFn) (PVOID, unsigned long);
	getvfunc<OriginalFn> (this, 17) (this, font);
}

void CSurface::DrawSetTextColor (int r, int g, int b, int a)
{
	typedef void(__thiscall * OriginalFn) (PVOID, int, int, int, int);
	getvfunc<OriginalFn> (this, 19) (this, r, g, b, a);
}

void CSurface::DrawSetTextPos (int x, int y)
{
	typedef void(__thiscall * OriginalFn) (PVOID, int, int);
	getvfunc<OriginalFn> (this, 20) (this, x, y);
}

void CSurface::DrawPrintText (const wchar_t *text, int textLen)
{
	typedef void(__thiscall * OriginalFn) (PVOID, const wchar_t *, int, int);
	return getvfunc<OriginalFn> (this, 22) (this, text, textLen, 0);
}

unsigned long CSurface::CreateFont ()
{
	typedef unsigned int(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 66) (this);
}

void CSurface::SetFontGlyphSet (unsigned long &font, const char *windowsFontName, int tall, int weight, int blur, int scanlines, int flags)
{
	typedef void(__thiscall * OriginalFn) (PVOID, unsigned long, const char *, int, int, int, int, int, int, int);
	getvfunc<OriginalFn> (this, 67) (this, font, windowsFontName, tall, weight, blur, scanlines, flags, 0, 0);
}

void CSurface::GetTextSize (unsigned long font, const wchar_t *text, int &wide, int &tall)
{
	typedef void(__thiscall * OriginalFn) (PVOID, unsigned long, const wchar_t *, int &, int &);
	getvfunc<OriginalFn> (this, 75) (this, font, text, wide, tall);
}

void CSurface::GetTextSize (unsigned long font, const char *text, int &wide, int &tall)
{
	int length = strlen (text);

	wchar_t *temp = new wchar_t[length + 1];

	mbstowcs (temp, text, length + 1);

	typedef void(__thiscall * OriginalFn) (PVOID, unsigned long, const wchar_t *, int &, int &);
	getvfunc<OriginalFn> (this, 75) (this, font, temp, wide, tall);

	delete[] temp;
}

void CSurface::PlaySound (const char *sound)
{
	typedef void(__thiscall * OriginalFn) (PVOID, const char *);
	return getvfunc<OriginalFn> (this, 78) (this, sound);
}

void CSurface::UnlockCursor ()
{
	return getvfunc<void(__thiscall *) (PVOID)> (this, 61) (this);
}

void CSurface::LockCursor ()
{
	return getvfunc<void(__thiscall *) (PVOID)> (this, 62) (this);
}

bool CSurface::IsCursorLocked ()
{
	return getvfunc<bool(__thiscall *) (PVOID)> (this, 104) (this);
}

void CSurface::SetCursorAlwaysVisible (bool vis)
{
	return getvfunc<void(__thiscall *) (PVOID, bool)> (this, 52) (this, vis);
}

void CSurface::SurfaceGetCursorPos (int &x, int &y)
{
	return getvfunc<void(__thiscall *) (PVOID, int &, int &)> (this, 96) (this, x, y);
}

void CSurface::SetSoftwareCursor (bool t)
{
	return getvfunc<void(__thiscall *) (PVOID, bool)> (this, 130) (this, t);
}

bool ClientModeShared::IsChatPanelOutOfFocus ()
{
	typedef PVOID (__thiscall * OriginalFn) (PVOID);
	PVOID CHudChat = getvfunc<OriginalFn> (this, 19) (this);
	if (CHudChat) {
		return *(PFLOAT) ((DWORD)CHudChat + 0xFC) == 0;
	}
	return false;
}

CUserCmd *CInput::GetUserCmd (int seq)
{
	// call the original one, which will  then call the hooked one
	typedef CUserCmd *(__thiscall * OriginalFn) (PVOID, int);
	return getvfunc<OriginalFn> (this, 8) (this, seq);
}

bool CInput::CAM_IsThirdPerson ()
{
	typedef bool(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 31) (this);
}

ClientClass *CHLClient::GetAllClasses ()
{
	typedef ClientClass *(__thiscall * OriginalFn) (PVOID); // Anything inside a VTable is a __thiscall unless it completly disregards the thisptr. You can
	// also call them as __stdcalls, but you won't have access to the __thisptr.
	return getvfunc<OriginalFn> (this, 8) (this); // Return the pointer to the head CClientClass.
}

void CHLClient::GetRenderView (CViewSetup &viewSetup)
{
	typedef void(__thiscall * OriginalFn) (PVOID, CViewSetup &);
	return getvfunc<OriginalFn> (this, 59) (this, viewSetup);
}

void CHLClient::RenderView (CViewSetup const &view, int nClearFlags, int whatToDraw)
{
	typedef void(__thiscall * OriginalFn) (PVOID, CViewSetup const &, int, int);
	return getvfunc<OriginalFn> (this, 27) (this, view, nClearFlags, whatToDraw);
}

const char *CModelInfo::GetModelName (model_t *model)
{
	typedef const char *(__thiscall * OriginalFn) (PVOID, DWORD *);
	return getvfunc<OriginalFn> (this, 4) (this, model);
}

studiohdr_t *CModelInfo::GetStudioModel (model_t *model)
{
	typedef DWORD *(__thiscall * OriginalFn) (PVOID, DWORD *);
	return getvfunc<OriginalFn> (this, 29) (this, model);
}

int CModelInfo::GetModelMaterialCount (model_t *model)
{
	typedef int(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 16) (this);
}

void CModelInfo::GetModelMaterials (model_t *model, int count, IMaterial **ppMaterials)
{
	typedef void(__thiscall * OriginalFn) (PVOID, model_t *, int, IMaterial **);
	return getvfunc<OriginalFn> (this, 17) (this, model, count, ppMaterials);
}

// CSteamInterfaces::CSteamInterfaces( ISteamClient017 *client, ISteamFriends002 *friends,
//								   ISteamUser017 *user, ISteamUserStats011 *userStats ) :
//	client(client), friends(friends), user(user), userStats(userStats)
//{
//
//}

CInterfaces::CInterfaces (CHLClient *chl, CEntList *ent, CPrediction *pred, IGameMovement *game, ClientModeShared *cms, EngineClient *eng, CModelInfo *info, CModelRender *render, CRenderView *view, CEngineTrace *trace, CUniformRandomStream *random, IGameEventManager2 *event, IVDebugOverlay *overlay, IEngineSound *sound, CDemoPlayer *demo, CClientState *state, CSurface *surf, CPanel *panel, ICvar *cvar, CGlobals *global, IPhysicsSurfaceProps *phys, CMaterialSystem *mat, IEngineVGui *EngineVGUI, class IScreenSpaceEffectManager *ssem, CSteamInterfaces &&steam)
    : Client (chl), EntList (ent), Prediction (pred), GameMovement (game), ClientMode (cms), Engine (eng), ModelInfo (info), ModelRender (render), RenderView (view), EngineTrace (trace), RandomStream (random), EventManager (event), DebugOverlay (overlay), SoundEngine (sound), DemoPlayer (demo), ClientState (state), Surface (surf), Panels (panel), Cvar (cvar), Input (**reinterpret_cast<CInput ***> ((*(DWORD **)chl)[15] + 0x1)), Globals (global), PhysicsSurfaceProps (phys), MatSystem (mat), EngineVGUI (EngineVGUI), ScreenSpaceEffectManager (ssem), steam (steam)
{
	SteamContext.Init ();
}

// ----------------------------------------------------------------------------
// CBaseEntity
// ----------------------------------------------------------------------------
CBaseHandle CBaseEntity::GetRefEHandle ()
{
	typedef CBaseHandle (__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 3) (this);
}

ICollideable *CBaseEntity::GetCollideable ()
{
	// typedef ICollideable *(__thiscall *OriginalFn)(PVOID);
	// return getvfunc<OriginalFn>(this, 2)(this);
	return GetCollision ();
}

Vector &CBaseEntity::GetAbsOrigin ()
{
	typedef Vector &(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 10) (this);
}

QAngle &CBaseEntity::GetAbsAngles ()
{
	typedef QAngle &(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 11) (this);
}

void CBaseEntity::SetAbsOrigin (Vector &o)
{
	typedef void(__thiscall * OriginalFn) (PVOID, Vector &);
	static OriginalFn fn = (OriginalFn)gSignatures.GetClientSignature ("55 89 E5 57 56 53 83 EC 1C 8B 5D 08 8B 75 0C 89 1C 24 E8 ?? ?? ?? ?? F3 0F 10 06 0F 2F 83 7C 02 00 00");
	return fn (this, o);
}

void CBaseEntity::SetAbsAngles (QAngle &a)
{
	typedef void(__thiscall * OriginalFn) (PVOID, QAngle &);
	static OriginalFn fn = (OriginalFn)gSignatures.GetClientSignature ("55 89 E5 57 56 53 81 EC 8C 00 00 00 8B 5D 08 8B 75 0C 89 1C 24");
	return fn (this, a);
}

void CBaseEntity::GetWorldSpaceCenter (Vector &vWorldSpaceCenter)
{
	Vector vMin, vMax;
	this->GetRenderBounds (vMin, vMax);
	vWorldSpaceCenter = this->GetAbsOrigin ();
	vWorldSpaceCenter.z += (vMin.z + vMax.z) / 2;
}

bool CBaseEntity::IsBaseCombatWeapon ()
{
	typedef bool(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 137) (this);
}

bool CBaseEntity::Interpolate (float currentTime)
{
	typedef bool(__thiscall * OriginalFn) (PVOID, float);
	return getvfunc<OriginalFn> (this, 97) (this, currentTime);
}

DWORD *CBaseEntity::GetModel ()
{
	typedef DWORD *(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 9) (this);
}

int CBaseEntity::DrawModel (int flags)
{
	typedef int(__thiscall * OriginalFn) (PVOID, int);
	return getvfunc<OriginalFn> (this, 9) (this, flags);
}

CStudioHdr *CBaseEntity::GetStudioHdr ()
{
	// from GetModelPtr in ida
	// v16 = this - 4;
	// v21 = *(_DWORD *)(v16 + 0x890)

	// therefore

	// TODO: either sig or virtual this!

	CStudioHdr *m_pStudioHdr = *(CStudioHdr **)(this + 0x890);

	if (!m_pStudioHdr) {
		Log::Console ("StudioHDR == NULL");
	}

	return m_pStudioHdr;
}

bool CBaseEntity::SetupBones (matrix3x4 *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime)
{
	typedef bool(__thiscall * OriginalFn) (PVOID, matrix3x4 *, int, int, float);
	return getvfunc<OriginalFn> (this, 96) (this, pBoneToWorldOut, nMaxBones, boneMask, currentTime);
}

ClientClass *CBaseEntity::GetClientClass ()
{
	typedef ClientClass *(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 17) (this);
}

bool CBaseEntity::IsDormant ()
{
	typedef bool(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 75) (this);
}

int CBaseEntity::GetIndex ()
{
	typedef int(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 79) (this);
}

void CBaseEntity::GetRenderBounds (Vector &mins, Vector &maxs)
{
	PVOID pRenderable = static_cast<PVOID> (this + 0x4);
	typedef void(__thiscall * OriginalFn) (PVOID, Vector &, Vector &);
	getvfunc<OriginalFn> (pRenderable, 20) (pRenderable, mins, maxs);
}

QAngle &CBaseEntity::GetPrevLocalAngles ()
{
	typedef QAngle &(__thiscall * OriginalFn) (PVOID);
	// could be 66
	return getvfunc<OriginalFn> (this, 102) (this);
}

matrix3x4 &CBaseEntity::GetRgflCoordinateFrame ()
{
	// NETVAR_OFF( n, DWORD, -0x4C, "DT_BaseEntity", "m_CollisionGroup" );
	// return *reinterpret_cast< matrix3x4 * >( n.getValue(this) );
	typedef matrix3x4 &(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 49) (this);
}

C_AnimationLayer *CBaseEntity::GetAnimOverlay (int index)
{
	// C_AnimationLayer *m_AnimOverlay = *(C_AnimationLayer **)(this + 2216); // check for "%8.4f : %30s : %5.3f : %4.2f : %1d\n"
	Log::Fatal ("::GetAnimOverlay Not defined");
	CUtlVector<C_AnimationLayer> &m_AnimOverlay = *(CUtlVector<C_AnimationLayer> *)(this + 2216);

	return &m_AnimOverlay[index];
}

int CBaseEntity::GetNumAnimOverlays ()
{
	Log::Fatal ("::GetAnimOverlay Not defined");
	CUtlVector<C_AnimationLayer> &m_AnimOverlay = *(CUtlVector<C_AnimationLayer> *)(this + 2216);
	return m_AnimOverlay.Count ();
	// return *(int *)(this + 2288); // dont ask - check for "%8.4f : %30s : %5.3f : %4.2f : %1d"
}

void CBaseEntity::SetSize (Vector &mins, Vector &maxs)
{
	static DWORD dwFunc = gSignatures.GetClientSignature ("55 89 E5 57 56 53 83 EC 4C 8B 5D 08 8B 75 0C 8B 7D 10 F3 0F 10 43 08 8D 53 08");
	typedef void(__thiscall * OriginalFn) (PVOID, Vector &, Vector &);
	return ((OriginalFn) (dwFunc)) ((this + 440), mins, maxs); // dont question it - check for "maxs" or "mins"
}

float CBaseEntity::GetAttributeFloat (float value, const char *attrib)
{
	Log::Fatal ("::GetAttributeFloat Not defined");
	static DWORD dwFuncLoc = RESOLVE_CALLGATE (gSignatures.GetClientSignature ("E8 ? ? ? ? 8B 47 08 8D 4F 08 83 C4 14 D9 5D F0") + 1);

	typedef float(__cdecl * OriginalFn) (float, const char *, CBaseEntity *);

	return ((OriginalFn)dwFuncLoc) (value, attrib, this);
}

// ----------------------------------------------------------------------------
// CBaseCombatWeapon
// ----------------------------------------------------------------------------

int CBaseCombatWeapon::GetMaxClip1 ()
{
	Log::Fatal ("::GetMaxClip1 Not defined");
	typedef int(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 318) (this);
}

int CBaseCombatWeapon::GetMaxClip2 ()
{
	Log::Fatal ("::GetMaxClip2 Not defined");
	typedef int(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 319) (this);
}

int CBaseCombatWeapon::GetSlot ()
{
	Log::Fatal ("::GetSlot Not defined");
	typedef int(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 327) (this);
}

char *CBaseCombatWeapon::GetName ()
{
	Log::Fatal ("::GetName Not defined");
	typedef char *(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 329) (this);
}

const char *CBaseCombatWeapon::GetWeaponAlias ()
{
	Log::Fatal ("::GetWeaponAlias Not defined");
	static DWORD dwFunc = gSignatures.GetClientSignature ("55 8B EC 8B 45 08 83 F8 68");
	typedef const char *(__cdecl * OriginalFn) (int);

	return ((OriginalFn)dwFunc) (GetWeaponID ());
}

struct WeaponData_t *CBaseCombatWeapon::GetWeaponData ()
{
	Log::Fatal ("::GetWeaponData Not defined");
	typedef unsigned short(__cdecl * LookupWeaponInfoSlotFn) (const char *);
	typedef WeaponData_t *(__cdecl * GetWeaponInfoFromHandleFn) (int slot);

	static LookupWeaponInfoSlotFn    LookupWeaponInfoSlot    = (LookupWeaponInfoSlotFn)gSignatures.GetClientSignature ("55 8B EC 8B 45 08 83 EC 08 85 C0 74 18");
	static GetWeaponInfoFromHandleFn GetWeaponInfoFromHandle = (GetWeaponInfoFromHandleFn)gSignatures.GetClientSignature ("55 8B EC 66 8B 45 08 66 3B 05 ? ? ? ? 73 1A");

	return GetWeaponInfoFromHandle (LookupWeaponInfoSlot (GetWeaponAlias ()));
}

int CBaseCombatWeapon::GetWeaponID ()
{
	Log::Fatal ("::GetWeaponID Not defined");
	typedef int(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 422) (this);
}

char *CBaseCombatWeapon::GetPrintName ()
{
	Log::Fatal ("::GetPrintName Not defined");
	typedef char *(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 330) (this);
}

Vector &CBaseCombatWeapon::GetBulletSpread ()
{
	Log::Fatal ("::GetBulletSpread Not defined");
	typedef Vector &(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 286) (this);
}

float CTFBaseWeaponGun::WeaponGetSpread ()
{
	Log::Fatal ("::WeaponGetSpread Not defined");
	typedef float(__thiscall * OriginalFn) (PVOID);
	// ida confirms 455
	return getvfunc<OriginalFn> (this, 455) (this);
}

void CBaseCombatCharacter::UpdateGlowEffect ()
{
	Log::Fatal ("::UpdateGlowEffect Not defined");
	typedef void(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 226) (this);
}

void CBaseCombatCharacter::DestroyGlowEffect ()
{
	Log::Fatal ("::DestroyGlowEffect Not defined");
	typedef void(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 227) (this);
}

bool CTFBaseWeaponMelee::DoSwingTrace (trace_t &trace)
{
	Log::Fatal ("::DoSwingTrace Not defined");
	typedef bool(__thiscall * OriginalFn) (PVOID, trace_t &);
	return getvfunc<OriginalFn> (this, 445) (this, trace);
}

bool CTFBaseWeaponMelee::CalcIsAttackCriticalHelper ()
{
	Log::Fatal ("::CalcIsAttackCriticalHelper Not defined");
	typedef bool(__thiscall * OriginalFn) (PVOID);
	return getvfunc<OriginalFn> (this, 389) (this);
}

#endif
