#include "baseHeaders.h"

#include "SDK.h"

CBaseEntity *const GetBaseEntity(int index)
{
	return gInts->EntList->GetClientEntity(index);
}

CBaseEntity *const GetBaseEntity(CHandle<CBaseEntity> handle)
{
	return gInts->EntList->GetClientEntityFromHandle(handle);
}

CBaseEntity *const GetBaseEntity(IHandleEntity *ent)
{
	return GetBaseEntity(ent->GetRefEHandle());
}

CBaseEntity *const GetLocalPlayer()
{
	return GetBaseEntity(gInts->Engine->GetLocalPlayerIndex());
}

// TODO: should this be in a cpp?
CScreenSpaceEffectRegistration::CScreenSpaceEffectRegistration(const char *pName, IScreenSpaceEffect *pEffect)
{
#ifdef _MSC_VER
	static auto **s_pHead = *(CScreenSpaceEffectRegistration ***)(gSignatures.GetClientSignature("8B 35 ? ? ? ? 85 F6 74 2F") + 2);
#else
	static auto **s_pHead = *(CScreenSpaceEffectRegistration ***)(gSignatures.GetClientSignature("8B 35 ? ? ? ? 85 F6 74 34 8D 74 26 00") + 2);
#endif
	m_pEffectName = pName;
	m_pEffect     = pEffect;
	m_pNext       = *s_pHead;
	*s_pHead      = this;
}

// anything that is platform agnostic goes in this file

int CBaseEntity::GetHealth() const
{
	// should be one time across all instances
	// static CDynamicNetvar<int> n( "DT_BasePlayer", "m_iHealth" );
	// return n.GetValue( this );
	NETVAR_RETURN(int, this, "DT_BasePlayer", "m_iHealth");
}

BYTE CBaseEntity::GetLifeState() const
{
	// static CDynamicNetvar<BYTE> n( "DT_BasePlayer", "m_lifeState" );
	// return n.GetValue( this );
	NETVAR_RETURN(BYTE, this, "DT_BasePlayer", "m_lifeState");
}

bool CBaseEntity::IsAlive() const
{
	return GetLifeState() == LIFE_ALIVE;
}

int CBaseEntity::GetTeam() const
{
	NETVAR_RETURN(int, this, "DT_BaseEntity", "m_iTeamNum");
}

tf_classes CBaseEntity::GetClass() const
{
	NETVAR_RETURN(tf_classes, this, "DT_TFPlayer", "m_PlayerClass", "m_iClass");
}

int &CBaseEntity::GetFlags() const
{
	NETVAR_RETURN(int &, this, "DT_BasePlayer", "m_fFlags");
}

CBaseCombatWeapon *CBaseEntity::GetActiveWeapon() const
{
	NETVAR(n, CHandle<CBaseEntity>, "DT_BaseCombatCharacter", "m_hActiveWeapon");
	return (CBaseCombatWeapon *)gInts->EntList->GetClientEntityFromHandle(n.GetValue(this));
}

bool CBaseEntity::IsReadyToBackstab() const
{
	// TODO maybe move to CBaseCombatWeapon?
	NETVAR_RETURN(bool, this, "DT_TFWeaponKnife", "m_bReadyToBackstab");
}

Vector &CBaseEntity::GetViewOffset() const
{
	NETVAR_RETURN(Vector &, this, "DT_BasePlayer", "localdata", "m_vecViewOffset[0]");
}

Vector CBaseEntity::GetViewPos() const
{
	return GetAbsOrigin() + GetViewOffset();
}

float CBaseEntity::GetChargeDamage() const
{
	NETVAR_RETURN(float, this, "DT_TFSniperRifle", "SniperRifleLocalData", "m_flChargedDamage");
}

int &CBaseEntity::GetTickBase() const
{
	NETVAR_RETURN(int &, this, "DT_BasePlayer", "localdata", "m_nTickBase");
}

// TODO: move me to CBaseCombatWeapon
float CBaseEntity::GetNextAttack() const
{
	NETVAR_RETURN(float, this, "DT_BaseCombatWeapon", "LocalActiveWeaponData", "m_flNextPrimaryAttack");
}

float CBaseEntity::GetLastFireTime() const
{
	NETVAR_RETURN(float, this, "DT_TFWeaponBase", "LocalActiveTFWeaponData", "m_flLastFireTime");
}

Vector &CBaseEntity::GetVelocity() const
{
	NETVAR_RETURN(Vector &, this, "DT_BasePlayer", "localdata", "m_vecBaseVelocity");
}

int &CBaseEntity::GetCond() const
{
	NETVAR_RETURN(int &, this, "DT_TFPlayer", "m_Shared", "m_nPlayerCond");
}

int &CBaseEntity::GetCondEx() const
{
	NETVAR_RETURN(int &, this, "DT_TFPlayer", "m_Shared", "m_nPlayerCondEx");
}

int &CBaseEntity::GetCondEx2() const
{
	NETVAR_RETURN(int &, this, "DT_TFPlayer", "m_Shared", "m_nPlayerCondEx2");
}

int &CBaseEntity::GetCondEx3() const
{
	NETVAR_RETURN(int &, this, "DT_TFPlayer", "m_Shared", "m_nPlayerCondEx3");
}

void CBaseEntity::SetCond(int c) const
{
	NETVAR(n, int, "DT_TFPlayer", "m_Shared", "m_nPlayerCond");
	return n.SetValue(this, c);
}

// backup local player cond
bool realZoom = false;
bool CBaseEntity::IsZoomed() const
{
	return GetCond() & tf_cond::TFCond_Zoomed;
}

void CBaseEntity::SetZoomed(bool state)
{
	if (GetIndex() == gInts->Engine->GetLocalPlayerIndex()) {
		realZoom = state;
	} else {
		state ? GetCond() |= tf_cond::TFCond_Zoomed : GetCond() &= ~tf_cond::TFCond_Zoomed;
	}
}

QAngle &CBaseEntity::GetPunchAngles() const
{
	NETVAR_RETURN(QAngle &, this, "DT_BasePlayer", "localdata", "m_Local", "m_vecPunchAngle");
}

CBaseEntity *CBaseEntity::GetOwner() const
{
	NETVAR(n, CBaseHandle, "DT_BaseCombatWeapon", "m_hOwner");
	return gInts->EntList->GetClientEntityFromHandle(n.GetValue(this));
}

moveTypes CBaseEntity::GetMoveType() const
{
	NETVAR_RETURN(moveTypes, this, "DT_BaseEntity", "movetype");
}

ICollideable *CBaseEntity::GetCollision() const
{
	NETVAR_RETURN(ICollideable *, this, "DT_BaseEntity", "m_Collision");
}

int CBaseEntity::GetRoundState() const
{
	NETVAR_RETURN(int, this, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_iRoundState");
}

int CBaseEntity::GetFov() const
{
	NETVAR_RETURN(int, this, "DT_BasePlayer", "m_iFOV");
}

void CBaseEntity::SetFov(int fov) const
{
	NETVAR(n, int, "DT_BasePlayer", "m_iFOV");
	return n.SetValue(this, fov);
}

QAngle &CBaseEntity::GetRotation() const
{
	NETVAR_RETURN(QAngle &, this, "DT_BaseEntity", "m_angRotation");
}

Vector &CBaseEntity::GetRenderOrigin() const
{
	NETVAR_RETURN(Vector &, this, "DT_BaseEntity", "m_vecOrigin");
}

float CBaseEntity::GetChargeTime() const
{
	NETVAR_RETURN(float, this, "DT_WeaponPipebombLauncher", "PipebombLauncherLocalData", "m_flChargeBeginTime");
}

float lastZoomTime = 0.0f;
float CBaseEntity::GetZoomTime() const
{
	if (this->IsZoomed()) {
		if (lastZoomTime == 0.0f)
			return lastZoomTime = gInts->Globals->curtime;

		return gInts->Globals->curtime - lastZoomTime;
	} else
		return lastZoomTime = 0.0f;
}

float &CBaseEntity::GetAnimTime() const
{
	NETVAR_RETURN(float &, this, "DT_BaseEntity", "AnimTimeMustBeFirst", "m_flAnimTime");
}

float &CBaseEntity::GetOldAnimTime() const
{
	// TODO: insert return statement here
	NETVAR_OFF_RETURN(float &, this, 0x4, "DT_BaseEntity", "AnimTimeMustBeFirst", "m_flAnimTime");
}

float &CBaseEntity::GetSimulationTime() const
{
	NETVAR_RETURN(float &, this, "DT_BaseEntity", "m_flSimulationTime");
}

float &CBaseEntity::GetOldSimulationTime() const
{
	NETVAR_OFF_RETURN(float &, this, 0x4, "DT_BaseEntity", "m_flSimulationTime");
}

void CBaseEntity::SetSimulationTime(float t) const
{
	GetSimulationTime() = t;
}

int CBaseEntity::GetItemDefinitionIndex() const
{
	NETVAR_RETURN(int, this, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_iItemDefinitionIndex");
}

Vector &CBaseEntity::GetCollideableMinsPrescaled() const
{
	NETVAR_RETURN(Vector &, this, "DT_BaseEntity", "m_Collision", "m_vecMinsPreScaled");
}

Vector &CBaseEntity::GetCollideableMaxsPrescaled() const
{
	NETVAR_RETURN(Vector &, this, "DT_BaseEntity", "m_Collision", "m_vecMaxsPreScaled");
}

Vector &CBaseEntity::GetCollideableMins() const
{
	NETVAR_RETURN(Vector &, this, "DT_BaseEntity", "m_Collision", "m_vecMins");
}

Vector &CBaseEntity::GetCollideableMaxs() const
{
	NETVAR_RETURN(Vector &, this, "DT_BaseEntity", "m_Collision", "m_vecMaxs");
}

CBaseEntity *CBaseEntity::GetGroundEntity() const
{
	NETVAR(n, CHandle<CBaseEntity>, "DT_BasePlayer", "localdata", "m_hGroundEntity");
	return gInts->EntList->GetClientEntityFromHandle(n.GetValue(this));
}

bool CBaseEntity::IsTouchingGround() const
{
	return GetGroundEntity();
}

float CBaseEntity::GetMaxSpeed() const
{
	NETVAR_RETURN(float, this, "DT_BasePlayer", "m_flMaxspeed");
}

int &CBaseEntity::GetSequence() const
{
	NETVAR_RETURN(int &, this, "DT_BaseAnimating", "m_nSequence");
}

float &CBaseEntity::GetCycle() const
{
	//NETVAR_RETURN (float &, this, "DT_BaseAnimating", "serveranimdata", "m_flCycle");
	// look at C_BaseAnimating::PostDataUpdate
	return *((float *)this + 0x8 + 0x82C); // TODO: try and see if the netvar works again if not then split up
}

void CBaseEntity::SetSequence(int seq) const
{
	GetSequence() = seq;
}

void CBaseEntity::SetCycle(int cyc) const
{
	// TODO: invalidatephysicsrecursive "55 8B EC 53 8B 5D 08 B8 ? ? ? ? 56"
	GetCycle() = cyc;

	typedef void(__thiscall * InvalidatePhysicsRecursiveFn)(const void *, unsigned int flags);

	static InvalidatePhysicsRecursiveFn fn = (InvalidatePhysicsRecursiveFn)gSignatures.GetClientSignature("55 8B EC 51 53 8B 5D 08 56 8B F3 83 E6 04");

	// pass ANIMATION_CHANGED flag
	fn(this, 0x8);
}

float &CBaseEntity::GetPlaybackRate() const
{
	NETVAR_RETURN(float &, this, "DT_BaseAnimating", "m_flPlaybackRate");
}

QAngle CBaseEntity::GetEyeAngles() const
{
	// There is no way to ensure that we will not mess up the .z part
	// and since that overlaps another data member, bad things will happen !
	NETVAR(ang0, float, "DT_TFPlayer", "tfnonlocaldata", "m_angEyeAngles[0]");
	NETVAR(ang1, float, "DT_TFPlayer", "tfnonlocaldata", "m_angEyeAngles[1]");
	return {ang0.GetValue(this), ang1.GetValue(this), 0.0f}; // z angle will always be 0
}

void CBaseEntity::SetEyeAngles(QAngle ang) const
{
	NETVAR(ang0, float, "DT_TFPlayer", "tfnonlocaldata", "m_angEyeAngles[0]");
	NETVAR(ang1, float, "DT_TFPlayer", "tfnonlocaldata", "m_angEyeAngles[1]");
	ang0.SetValue(this, ang.x);
	ang0.SetValue(this, ang.y);
}

bool CBaseEntity::UseClassAnimations() const
{
	NETVAR_RETURN(bool, this, "DT_TFPlayer", "m_PlayerClass", "m_bUseClassAnimations");
}

Vector &CBaseEntity::GetCustomModelOffset() const
{
	NETVAR_RETURN(Vector &, this, "DT_TFPlayer", "m_PlayerClass", "m_vecCustomModelOffset");
}

bool CBaseEntity::GetCustomModelRotates() const
{
	NETVAR_RETURN(bool, this, "DT_TFPlayer", "m_PlayerClass", "m_bCustomModelRotates");
}

bool CBaseEntity::GetCustomModelRotationSet() const
{
	NETVAR_RETURN(bool, this, "DT_TFPlayer", "m_PlayerClass", "m_bCustomModelRotationSet");
}

QAngle &CBaseEntity::GetCustomModelRotation() const
{
	NETVAR_RETURN(QAngle &, this, "DT_TFPlayer", "m_PlayerClass", "m_vecCustomModelRotation");
}

float &CBaseEntity::GetModelScale() const
{
	NETVAR_RETURN(float &, this, "DT_BaseAnimating", "m_flModelScale");
}

bool CBaseEntity::IsCritBoosted() const
{
	int &cond   = GetCond();
	int &condEx = GetCondEx();

	return cond & tf_cond::TFCond_Kritzkrieged || condEx & tf_cond_ex::TFCondEx_CritCanteen || condEx & tf_cond_ex::TFCondEx_CritOnFirstBlood || condEx & tf_cond_ex::TFCondEx_CritOnWin || condEx & tf_cond_ex::TFCondEx_HalloweenCritCandy || condEx & tf_cond_ex::TFCondEx_PyroCrits;

	return false;
}

float CBaseEntity::GetCritMult() const
{
	// we need to do remap value on this
	NETVAR(n, float, "DT_TFPlayer", "m_Shared", "m_iCritMult");
	return RemapValClamped(n.GetValue(this), 0, 255, 1.0, 4.0);
}

float CBaseEntity::GetObservedCritChance() const
{
	NETVAR_RETURN(float, this, "DT_TFWeaponBase", "LocalActiveTFWeaponData", "m_flObservedCritChance");
}

bool CBaseEntity::IsEffectActive(int effects) const
{
	NETVAR(n, int, "DT_BaseEntity", "m_fEffects");
	return (n.GetValue(this) & effects) != 0;
}

int CBaseEntity::GetModelIndex() const
{
	NETVAR_RETURN(int, this, "DT_BaseEntity", "m_nModelIndex");
}

int &CBaseEntity::GetObserverMode() const
{
	NETVAR_RETURN(int &, this, "DT_BasePlayer", "m_iObserverMode");
}

int CBaseCombatWeapon::Clip1()
{
	NETVAR_RETURN(int, this, "DT_BaseCombatWeapon", "LocalWeaponData", "m_iClip1");
}

bool CBaseCombatCharacter::IsGlowEnabled() const
{
	NETVAR_RETURN(bool, this, "DT_TFPlayer", "m_bGlowEnabled");
}

void CBaseCombatCharacter::SetGlowEnabled(bool t) const
{
	NETVAR(n, bool, "DT_TFPlayer", "m_bGlowEnabled");
	return n.SetValue(this, t);
}

int CObject::GetLevel() const
{
	NETVAR_RETURN(int, this, "DT_BaseObject", "m_iUpgradeLevel");
}

bool CObject::IsSapped() const
{
	NETVAR_RETURN(int, this, "DT_BaseObject", "m_bHasSapper");
}

bool CObject::IsBuilding() const
{
	NETVAR_RETURN(int, this, "DT_BaseObject", "m_bBuilding");
}

float CObject::GetPercentageConstructed() const
{
	if (IsBuilding()) {
		NETVAR_RETURN(int, this, "DT_BaseObject", "m_flPercentageConstructed");
	} else
		return 0;
}

int CObject::GetHealth() const
{
	NETVAR_RETURN(int, this, "DT_BaseObject", "m_iHealth");
}

int CObject::GetUpgradedMetal() const
{
	NETVAR_RETURN(int, this, "DT_BaseObject", "m_iUpgradeMetal");
}

int CObjectTeleporter::GetState() const
{
	NETVAR_RETURN(int, this, "DT_ObjectTeleporter", "m_iState");
}

const char *CObjectTeleporter::GetStateString() const
{
	switch (GetState()) {
	case 1: {
		return "Idle";
	}
	case 2: {
		return "Active";
	}
	case 4: {
		return "Teleporting";
	}
	case 6: {
		return "Charging";
	}
	}

	return "Unknown";
}

int CObjectSentryGun::GetRocket() const
{
	if (GetLevel() == 3) {
		NETVAR_RETURN(int, this, "DT_ObjectSentrygun", "m_iAmmoRockets");
	}
	return NULL;
}

int CObjectSentryGun::GetAmmo() const
{
	NETVAR_RETURN(int, this, "DT_ObjectSentrygun", "m_iAmmoShells");
}

bool CObjectSentryGun::IsControlled() const
{
	NETVAR_RETURN(bool, this, "DT_ObjectSentrygun", "m_bPlayerControlled");
}

int CObjectSentryGun::GetState() const
{
	NETVAR_RETURN(int, this, "DT_ObjectSentrygun", "m_iState");
}

const char *CObjectSentryGun::GetStateString() const
{
	switch (GetState()) {
	case 1: {
		return "Idle";
	}
	case 2: {
		return "Attacking";
	}
	case 3: {
		return "Upgrading";
	}
	}
	return "Unknown";
}

int CObjectDispenser::GetMetalReserve() const
{
	NETVAR_RETURN(int, this, "DT_ObjectDispenser", "m_iAmmoMetal");
}
