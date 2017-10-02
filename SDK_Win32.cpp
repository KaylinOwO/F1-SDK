#include "baseHeaders.h"

#include "../SDK/SDK.h"

#include "../SDK/Util.h"

#include <array>

// for FontFlags
#include "CDrawManager.h"

#undef GetProp

// TODO: stop using _MSC_VER ! ! ! ! !!  !  ! !  ! ! ! !! !  !!  ! ! ! ! !
#if defined(_MSC_VER)

// ----------------------------------------------------------------------------
// Interfaces
// ----------------------------------------------------------------------------

CBaseEntity *CEntList::GetClientEntity(int entnum)
{
	typedef CBaseEntity *(__thiscall * OriginalFn)(PVOID, int);
	return getvfunc<OriginalFn>(this, 3)(this, entnum);
}

CBaseEntity *CEntList::GetClientEntityFromHandle(CBaseHandle hEnt)
{
	typedef CBaseEntity *(__thiscall * OriginalFn)(PVOID, CBaseHandle);
	return getvfunc<OriginalFn>(this, 4)(this, hEnt);
}

int CEntList::GetHighestEntityIndex()
{
	typedef int(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 6)(this);
}

void EngineClient::GetScreenSize(int &width, int &height)
{
	// call the engine function
	typedef void(__thiscall * OriginalFn)(PVOID, int &, int &);
	getvfunc<OriginalFn>(this, 5)(this, width, height);

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

bool EngineClient::GetPlayerInfo(int ent_num, player_info_t *pinfo)
{
	typedef bool(__thiscall * OriginalFn)(PVOID, int, player_info_t *);
	return getvfunc<OriginalFn>(this, 8)(this, ent_num, pinfo);
}

player_info_t EngineClient::GetPlayerInfo(int ent_num)
{
	player_info_t tempInfo;
	GetPlayerInfo(ent_num, &tempInfo);
	return tempInfo;
}

int EngineClient::GetPlayerForUserID(int userID)
{
	typedef int(__thiscall * OriginalFn)(PVOID, int);
	return getvfunc<OriginalFn>(this, 9)(this, userID);
}

bool EngineClient::Con_IsVisible()
{
	typedef bool(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 11)(this);
}

int EngineClient::GetLocalPlayerIndex()
{
	typedef int(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 12)(this);
}

float EngineClient::Time()
{
	typedef float(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 14)(this);
}

float EngineClient::GetLastTimeStamp()
{
	typedef float(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 15)(this);
}

void EngineClient::GetViewAngles(QAngle &va)
{
	typedef void(__thiscall * OriginalFn)(PVOID, QAngle &);
	return getvfunc<OriginalFn>(this, 19)(this, va);
}

void EngineClient::SetViewAngles(QAngle &va)
{
	typedef void(__thiscall * OriginalFn)(PVOID, QAngle &);
	return getvfunc<OriginalFn>(this, 20)(this, va);
}

int EngineClient::GetMaxClients()
{
	typedef int(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 21)(this);
}

bool EngineClient::IsInGame()
{
	typedef bool(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 26)(this);
}

bool EngineClient::IsConnected()
{
	typedef bool(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 27)(this);
}

bool EngineClient::IsDrawingLoadingImage()
{
	typedef bool(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 28)(this);
}

const VMatrix &EngineClient::WorldToScreenMatrix()
{
	typedef const matrix3x4 &(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 36)(this);
}

bool EngineClient::IsTakingScreenshot()
{
	typedef bool(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 85)(this);
}

CNetChan *EngineClient::GetNetChannelInfo()
{
	typedef CNetChan *(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 72)(this);
}

void EngineClient::ExecuteClientCmd(const char *chCommandString)
{
	typedef void(__thiscall * OriginalFn)(PVOID, const char *);
	return getvfunc<OriginalFn>(this, 102)(this, chCommandString);
}

void EngineClient::ClientCmd_Unrestricted(const char *chCommandString)
{
	typedef void(__thiscall * OriginalFn)(PVOID, const char *);
	return getvfunc<OriginalFn>(this, 106)(this, chCommandString);
}

void EngineClient::ServerCmdKeyValues(PVOID keyval)
{
	typedef void(__thiscall * OriginalFn)(PVOID, PVOID);
	return getvfunc<OriginalFn>(this, 127)(this, keyval);
}

void EngineClient::ServerCmdKeyValues(KeyValues *keyval)
{
	// call the other one
	return ServerCmdKeyValues((PVOID)keyval);
}

const char *EngineClient::Key_BindingForKey(ButtonCode_t c)
{
	typedef const char *(__thiscall * OriginalFn)(PVOID, ButtonCode_t);
	return getvfunc<OriginalFn>(this, 23)(this, c);
}

const char *CPanel::GetName(unsigned vguiPanel)
{
	typedef const char *(__thiscall * OriginalFn)(PVOID, unsigned int);
	return getvfunc<OriginalFn>(this, 36)(this, vguiPanel);
}

void CSurface::DrawSetColor(int r, int g, int b, int a)
{
	typedef void(__thiscall * OriginalFn)(PVOID, int, int, int, int);
	getvfunc<OriginalFn>(this, 11)(this, r, g, b, a);
}

void CSurface::DrawFilledRect(int x0, int y0, int x1, int y1)
{
	typedef void(__thiscall * OriginalFn)(PVOID, int, int, int, int);
	getvfunc<OriginalFn>(this, 12)(this, x0, y0, x1, y1);
}

void CSurface::DrawOutlinedRect(int x0, int y0, int x1, int y1)
{
	typedef void(__thiscall * OriginalFn)(PVOID, int, int, int, int);
	getvfunc<OriginalFn>(this, 14)(this, x0, y0, x1, y1);
}

void CSurface::DrawOutlinedCircle(int x, int y, int radius, int segments)
{
	typedef void(__thiscall * OriginalFn)(PVOID, int, int, int, int);
	return getvfunc<OriginalFn>(this, 99)(this, x, y, radius, segments);
}

void CSurface::DrawLine(int x0, int y0, int x1, int y1)
{
	typedef void(__thiscall * OriginalFn)(PVOID, int, int, int, int);
	getvfunc<OriginalFn>(this, 15)(this, x0, y0, x1, y1);
}

void CSurface::DrawPolyLine(int *x, int *y, int n)
{
	typedef void(__thiscall * OriginalFn)(PVOID, int *, int *, int);
	getvfunc<OriginalFn>(this, 16)(this, x, y, n);
}

void CSurface::DrawSetTextFont(unsigned long font)
{
	typedef void(__thiscall * OriginalFn)(PVOID, unsigned long);
	getvfunc<OriginalFn>(this, 17)(this, font);
}

void CSurface::DrawSetTextColor(int r, int g, int b, int a)
{
	typedef void(__thiscall * OriginalFn)(PVOID, int, int, int, int);
	getvfunc<OriginalFn>(this, 19)(this, r, g, b, a);
}

void CSurface::DrawSetTextPos(int x, int y)
{
	typedef void(__thiscall * OriginalFn)(PVOID, int, int);
	getvfunc<OriginalFn>(this, 20)(this, x, y);
}

void CSurface::DrawPrintText(const wchar_t *text, int textLen)
{
	typedef void(__thiscall * OriginalFn)(PVOID, const wchar_t *, int, int);
	return getvfunc<OriginalFn>(this, 22)(this, text, textLen, 0);
}

unsigned long CSurface::CreateFont()
{
	typedef unsigned int(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 66)(this);
}

void CSurface::SetFontGlyphSet(unsigned long &font, const char *windowsFontName, int tall, int weight, int blur, int scanlines, int flags)
{
	typedef void(__thiscall * OriginalFn)(PVOID, unsigned long, const char *, int, int, int, int, int, int, int);
	getvfunc<OriginalFn>(this, 67)(this, font, windowsFontName, tall, weight, blur, scanlines, flags, 0, 0);
}

void CSurface::GetTextSize(unsigned long font, const wchar_t *text, int &wide, int &tall)
{
	typedef void(__thiscall * OriginalFn)(PVOID, unsigned long, const wchar_t *, int &, int &);
	getvfunc<OriginalFn>(this, 75)(this, font, text, wide, tall);
}

void CSurface::GetTextSize(unsigned long font, const char *text, int &wide, int &tall)
{
	// TODO: this needs to take wchars instead of converting them
	int length = strlen(text);

	wchar_t *temp = new wchar_t[length + 1];

	mbstowcs(temp, text, length + 1);

	typedef void(__thiscall * OriginalFn)(PVOID, unsigned long, const wchar_t *, int &, int &);
	getvfunc<OriginalFn>(this, 75)(this, font, temp, wide, tall);

	delete[] temp;
}

void CSurface::PlaySound(const char *sound)
{
	typedef void(__thiscall * OriginalFn)(PVOID, const char *);
	return getvfunc<OriginalFn>(this, 78)(this, sound);
}

void CSurface::UnlockCursor()
{
	return getvfunc<void(__thiscall *)(PVOID)>(this, 61)(this);
}

void CSurface::LockCursor()
{
	return getvfunc<void(__thiscall *)(PVOID)>(this, 62)(this);
}

bool CSurface::IsCursorLocked()
{
	return getvfunc<bool(__thiscall *)(PVOID)>(this, 104)(this);
}

void CSurface::SetCursorAlwaysVisible(bool vis)
{
	return getvfunc<void(__thiscall *)(PVOID, bool)>(this, 52)(this, vis);
}

void CSurface::SurfaceGetCursorPos(int &x, int &y)
{
	return getvfunc<void(__thiscall *)(PVOID, int &, int &)>(this, 96)(this, x, y);
}

void CSurface::SetSoftwareCursor(bool t)
{
	return getvfunc<void(__thiscall *)(PVOID, bool)>(this, 130)(this, t);
}

bool ClientModeShared::IsChatPanelOutOfFocus()
{
	typedef PVOID(__thiscall * OriginalFn)(PVOID);
	PVOID CHudChat = getvfunc<OriginalFn>(this, 19)(this);
	if (CHudChat) {
		return *(PFLOAT)((DWORD)CHudChat + 0xFC) == 0;
	}
	return false;
}

CUserCmd *CInput::GetUserCmd(int seq)
{
	// call the original one, which will  then call the hooked one
	typedef CUserCmd *(__thiscall * OriginalFn)(PVOID, int);
	return getvfunc<OriginalFn>(this, 8)(this, seq);
}

bool CInput::CAM_IsThirdPerson()
{
	typedef bool(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 31)(this);
}

ClientClass *CHLClient::GetAllClasses()
{
	typedef ClientClass *(__thiscall * OriginalFn)(PVOID); // Anything inside a VTable is a __thiscall unless it completly disregards the thisptr. You can
	// also call them as __stdcalls, but you won't have access to the __thisptr.
	return getvfunc<OriginalFn>(this, 8)(this); // Return the pointer to the head CClientClass.
}

void CHLClient::GetRenderView(CViewSetup &viewSetup)
{
	typedef void(__thiscall * OriginalFn)(PVOID, CViewSetup &);
	return getvfunc<OriginalFn>(this, 59)(this, viewSetup);
}

void CHLClient::RenderView(CViewSetup const &view, int nClearFlags, int whatToDraw)
{
	typedef void(__thiscall * OriginalFn)(PVOID, CViewSetup const &, int, int);
	return getvfunc<OriginalFn>(this, 27)(this, view, nClearFlags, whatToDraw);
}

const char *CModelInfo::GetModelName(model_t *model)
{
	typedef const char *(__thiscall * OriginalFn)(PVOID, model_t *);
	return getvfunc<OriginalFn>(this, 3)(this, model);
}

studiohdr_t *CModelInfo::GetStudioModel(model_t *model)
{
	typedef studiohdr_t *(__thiscall * OriginalFn)(PVOID, model_t *);
	return getvfunc<OriginalFn>(this, 28)(this, model);
}

int CModelInfo::GetModelMaterialCount(model_t *model)
{
	typedef int(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 15)(this);
}

void CModelInfo::GetModelMaterials(model_t *model, int count, IMaterial **ppMaterials)
{
	typedef void(__thiscall * OriginalFn)(PVOID, model_t *, int, IMaterial **);
	return getvfunc<OriginalFn>(this, 16)(this, model, count, ppMaterials);
}

// CSteamInterfaces::CSteamInterfaces( ISteamClient017 *client, ISteamFriends002 *friends,
//								   ISteamUser017 *user, ISteamUserStats011 *userStats ) :
//	client(client), friends(friends), user(user), userStats(userStats)
//{
//
//}

CInterfaces::CInterfaces()
{
	SteamContext.Init();
}

// ----------------------------------------------------------------------------
// CBaseEntity
// ----------------------------------------------------------------------------
CBaseHandle CBaseEntity::GetRefEHandle() const
{
	typedef CBaseHandle(__thiscall * OriginalFn)(const CBaseEntity *);
	return getvfunc<OriginalFn>(this, 1)(this);
}

ICollideable *CBaseEntity::GetCollideable() const
{
	// typedef ICollideable *(__thiscall *OriginalFn)(PVOID);
	// return getvfunc<OriginalFn>(this, 2)(this);
	return GetCollision();
}

void CBaseEntity::SetAbsOrigin(Vector &o) const
{
	typedef void(__thiscall * OriginalFn)(const CBaseEntity *, Vector &);
	// search for "origin" and "angles"
	static OriginalFn fn = (OriginalFn)gSignatures.GetClientSignature("55 8B EC 56 57 8B F1 E8 ? ? ? ? 8B 7D 08 F3 0F 10 07");
	return fn(this, o);
}

void CBaseEntity::SetAbsAngles(QAngle &a) const
{
	typedef void(__thiscall * OriginalFn)(const CBaseEntity *, QAngle &);
	static OriginalFn fn = (OriginalFn)gSignatures.GetClientSignature("55 8B EC 83 EC 60 56 57 8B F1");
	return fn(this, a);
}

Vector &CBaseEntity::GetAbsOrigin() const
{
	typedef Vector &(__thiscall * OriginalFn)(const CBaseEntity *);
	return getvfunc<OriginalFn>(this, 9)(this);
}

QAngle &CBaseEntity::GetAbsAngles() const
{
	typedef QAngle &(__thiscall * OriginalFn)(const CBaseEntity *);
	return getvfunc<OriginalFn>(this, 10)(this);
}

void CBaseEntity::GetWorldSpaceCenter(Vector &vWorldSpaceCenter) const
{
	Vector vMin, vMax;
	this->GetRenderBounds(vMin, vMax);
	vWorldSpaceCenter = this->GetAbsOrigin();
	vWorldSpaceCenter.z += (vMin.z + vMax.z) / 2;
}

bool CBaseEntity::IsBaseCombatWeapon() const
{
	typedef bool(__thiscall * OriginalFn)(const CBaseEntity *);
	return getvfunc<OriginalFn>(this, 137)(this);
}

bool CBaseEntity::Interpolate(float currentTime) const
{
	typedef bool(__thiscall * OriginalFn)(const CBaseEntity *, float);
	return getvfunc<OriginalFn>(this, 97)(this, currentTime);
}

model_t *CBaseEntity::GetModel() const
{
	const PVOID pRenderable = (const PVOID)(this + 0x4);
	typedef model_t *(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(pRenderable, 9)(pRenderable);
}

int CBaseEntity::DrawModel(int flags) const
{
	const PVOID pRenderable = (const PVOID)(this + 0x4);
	typedef int(__thiscall * OriginalFn)(PVOID, int);
	return getvfunc<OriginalFn>(pRenderable, 10)(pRenderable, flags);
}

const CStudioHdr *CBaseEntity::GetStudioHdr() const
{
	// from GetModelPtr in ida
	// v16 = this - 4;
	// v21 = *(_DWORD *)(v16 + 0x890)

	// therefore

	// TODO: either sig or virtual this!

	CStudioHdr *m_pStudioHdr = *(CStudioHdr **)(this + 0x890);

	if (!m_pStudioHdr) {
		Log::Console("StudioHDR == NULL");
	}

	return m_pStudioHdr;
}

bool CBaseEntity::SetupBones(matrix3x4 *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime) const
{
	const PVOID pRenderable = (const PVOID)(this + 0x4);
	typedef bool(__thiscall * OriginalFn)(PVOID, matrix3x4 *, int, int, float);
	return getvfunc<OriginalFn>(pRenderable, 16)(pRenderable, pBoneToWorldOut, nMaxBones, boneMask, currentTime);
}

const ClientClass *CBaseEntity::GetClientClass() const
{
	const PVOID pNetworkable = (const PVOID)(this + 0x8);
	typedef ClientClass *(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(pNetworkable, 2)(pNetworkable);
}

bool CBaseEntity::IsDormant() const
{
	const PVOID pNetworkable = (const PVOID)(this + 0x8);
	typedef bool(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(pNetworkable, 8)(pNetworkable);
}

const int CBaseEntity::GetIndex() const
{
	const PVOID pNetworkable = (const PVOID)(this + 0x8);
	typedef int(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(pNetworkable, 9)(pNetworkable);
}

void CBaseEntity::GetRenderBounds(Vector &mins, Vector &maxs) const
{
	const PVOID pRenderable = (const PVOID)(this + 0x4);
	typedef void(__thiscall * OriginalFn)(PVOID, Vector &, Vector &);
	getvfunc<OriginalFn>(pRenderable, 20)(pRenderable, mins, maxs);
}

QAngle &CBaseEntity::GetPrevLocalAngles() const
{
	typedef QAngle &(__thiscall * OriginalFn)(const CBaseEntity *);
	// could be 66
	return getvfunc<OriginalFn>(this, 142)(this);
}

matrix3x4 &CBaseEntity::GetRgflCoordinateFrame()
{
	// NETVAR_OFF( n, DWORD, -0x4C, "DT_BaseEntity", "m_CollisionGroup" );
	// return *reinterpret_cast< matrix3x4 * >( n.getValue(this) );
	PVOID pRenderable = static_cast<PVOID>(this + 0x4);
	typedef matrix3x4 &(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(pRenderable, 34)(pRenderable);
}

C_AnimationLayer *CBaseEntity::GetAnimOverlay(int index) const
{
	// C_AnimationLayer *m_AnimOverlay = *(C_AnimationLayer **)(this + 2216); // check for "%8.4f : %30s : %5.3f : %4.2f : %1d\n"

	CUtlVector<C_AnimationLayer> &m_AnimOverlay = *(CUtlVector<C_AnimationLayer> *)(this + 2216);

	return &m_AnimOverlay[index];
}

int CBaseEntity::GetNumAnimOverlays() const
{
	CUtlVector<C_AnimationLayer> &m_AnimOverlay = *(CUtlVector<C_AnimationLayer> *)(this + 2216);
	return m_AnimOverlay.Count();
	// return *(int *)(this + 2288); // dont ask - check for "%8.4f : %30s : %5.3f : %4.2f : %1d"
}

void CBaseEntity::UpdateAnimation() const
{
	const void *pAnimating = (const void *)(this + 0x4);
	return getvfunc<void(__thiscall *)(const void *)>(this, 191)(this);
}

void CBaseEntity::SetSize(Vector &mins, Vector &maxs) const
{
	static DWORD dwFunc = gSignatures.GetClientSignature("55 8B EC 83 EC 28 53 8B 5D 08 56 8B 75 0C 57 8B 03");
	typedef void(__thiscall * OriginalFn)(const CBaseEntity *, Vector &, Vector &);
	return ((OriginalFn)(dwFunc))((this + 456), mins, maxs); // dont question it - check for "maxs" or "mins"
}

float CBaseEntity::GetAttributeFloat(float value, const char *attrib) const
{
	static DWORD dwFuncLoc = RESOLVE_CALLGATE(gSignatures.GetClientSignature("E8 ? ? ? ? 8B 47 08 8D 4F 08 83 C4 14 D9 5D F0") + 1);

	// this appears to take more arguments then the TF2C sourcecode suggests

	typedef float(__cdecl * OriginalFn)(float, const char *, const CBaseEntity *, int, int);

	return ((OriginalFn)dwFuncLoc)(value, attrib, this, 0, 1);
}

// ----------------------------------------------------------------------------
// CBaseCombatWeapon
// ----------------------------------------------------------------------------

int CBaseCombatWeapon::GetMaxClip1()
{
	typedef int(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 318)(this);
}

int CBaseCombatWeapon::GetMaxClip2()
{
	typedef int(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 319)(this);
}

int CBaseCombatWeapon::GetSlot()
{
	typedef int(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 327)(this);
}

char *CBaseCombatWeapon::GetName()
{
	typedef char *(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 329)(this);
}

const char *CBaseCombatWeapon::GetWeaponAlias()
{
	static DWORD dwFunc = gSignatures.GetClientSignature("55 8B EC 8B 45 08 83 F8 68");
	typedef const char *(__cdecl * OriginalFn)(int);

	return ((OriginalFn)dwFunc)(GetWeaponID());
}

// TODO: linxu
// vtable indexes for these functions on windows
// look for "custom projectile model" xref and then GetProjectileSpeed is next in the vtable, followed by getprojectilegravity
// 456	sub_105D53F0
// 457	GetProjectileSpeed
// 458	GetProjectileGravity

float CBaseCombatWeapon::GetProjectileSpeed()
{
	return getvfunc<float(__thiscall *)(PVOID)>(this, 457)(this);
}

float CBaseCombatWeapon::GetProjectileGravity()
{
	return getvfunc<float(__thiscall *)(PVOID)>(this, 458)(this);
}

struct WeaponData_t *CBaseCombatWeapon::GetWeaponData()
{
	typedef unsigned short(__cdecl * LookupWeaponInfoSlotFn)(const char *);
	typedef WeaponData_t *(__cdecl * GetWeaponInfoFromHandleFn)(int slot);

	static LookupWeaponInfoSlotFn    LookupWeaponInfoSlot    = (LookupWeaponInfoSlotFn)gSignatures.GetClientSignature("55 8B EC 8B 45 08 83 EC 08 85 C0 74 18");
	static GetWeaponInfoFromHandleFn GetWeaponInfoFromHandle = (GetWeaponInfoFromHandleFn)gSignatures.GetClientSignature("55 8B EC 66 8B 45 08 66 3B 05 ? ? ? ? 73 1A");

	return GetWeaponInfoFromHandle(LookupWeaponInfoSlot(GetWeaponAlias()));
}

int CBaseCombatWeapon::GetWeaponID()
{
	typedef int(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 422)(this);
}

char *CBaseCombatWeapon::GetPrintName()
{
	typedef char *(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 330)(this);
}

Vector &CBaseCombatWeapon::GetBulletSpread()
{
	typedef Vector &(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 286)(this);
}

float CTFBaseWeaponGun::WeaponGetSpread()
{
	typedef float(__thiscall * OriginalFn)(PVOID);
	// ida confirms 455
	return getvfunc<OriginalFn>(this, 456)(this);
}

void CBaseCombatCharacter::UpdateGlowEffect()
{
	typedef void(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 226)(this);
}

void CBaseCombatCharacter::DestroyGlowEffect()
{
	typedef void(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 227)(this);
}

bool CTFBaseWeaponMelee::DoSwingTrace(trace_t &trace)
{
	typedef bool(__thiscall * OriginalFn)(PVOID, trace_t &);
	return getvfunc<OriginalFn>(this, 445)(this, trace);
}

bool CTFBaseWeaponMelee::CalcIsAttackCriticalHelper()
{
	typedef bool(__thiscall * OriginalFn)(PVOID);
	return getvfunc<OriginalFn>(this, 389)(this);
}

#endif