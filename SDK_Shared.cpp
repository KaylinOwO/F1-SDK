#include "SDK.h"

CBaseEntity *GetBaseEntity (int index)
{
	return gInts->EntList->GetClientEntity (index);
}

CBaseEntity *GetBaseEntity (CHandle<CBaseEntity> handle)
{
	return gInts->EntList->GetClientEntityFromHandle (handle);
}

CBaseEntity *GetLocalPlayer ()
{
	return GetBaseEntity (gInts->Engine->GetLocalPlayer ());
}

// TODO: should this be in a cpp?
CScreenSpaceEffectRegistration::CScreenSpaceEffectRegistration (const char *pName, IScreenSpaceEffect *pEffect)
{
#ifdef _MSC_VER
	static auto **s_pHead = *(CScreenSpaceEffectRegistration ***)(gSignatures.GetClientSignature ("8B 35 ? ? ? ? 85 F6 74 2F") + 2);
#else
	static auto **s_pHead = *(CScreenSpaceEffectRegistration ***)(gSignatures.GetClientSignature ("8B 35 ? ? ? ? 85 F6 74 34 8D 74 26 00") + 2);
#endif
	m_pEffectName = pName;
	m_pEffect     = pEffect;
	m_pNext       = *s_pHead;
	*s_pHead      = this;
}

// anything that is platform agnostic goes in this file

int CBaseEntity::GetHealth ()
{
	// should be one time across all instances
	// static CDynamicNetvar<int> n( "DT_BasePlayer", "m_iHealth" );
	// return n.GetValue( this );
	DYNVAR_RETURN (int, this, "DT_BasePlayer", "m_iHealth");
}

BYTE CBaseEntity::GetLifeState ()
{
	// static CDynamicNetvar<BYTE> n( "DT_BasePlayer", "m_lifeState" );
	// return n.GetValue( this );
	DYNVAR_RETURN (BYTE, this, "DT_BasePlayer", "m_lifeState");
}

bool CBaseEntity::IsAlive ()
{
	return GetLifeState () == LIFE_ALIVE;
}

int CBaseEntity::GetTeam ()
{
	DYNVAR_RETURN (int, this, "DT_BaseEntity", "m_iTeamNum");
}

tf_classes CBaseEntity::GetClass ()
{
	DYNVAR_RETURN (tf_classes, this, "DT_TFPlayer", "m_PlayerClass", "m_iClass");
}

int &CBaseEntity::GetFlags ()
{
	DYNVAR_RETURN (int &, this, "DT_BasePlayer", "m_fFlags");
}

CBaseCombatWeapon *CBaseEntity::GetActiveWeapon ()
{
	DYNVAR (n, CHandle<CBaseEntity>, "DT_BaseCombatCharacter", "m_hActiveWeapon");
	return (CBaseCombatWeapon *)gInts->EntList->GetClientEntityFromHandle (n.GetValue (this));
}

bool CBaseEntity::IsReadyToBackstab ()
{
	// TODO maybe move to CBaseCombatWeapon?
	DYNVAR_RETURN (bool, this, "DT_TFWeaponKnife", "m_bReadyToBackstab");
}

Vector &CBaseEntity::GetViewOffset ()
{
	DYNVAR_RETURN (Vector &, this, "DT_BasePlayer", "localdata", "m_vecViewOffset[0]");
}

Vector CBaseEntity::GetViewPos ()
{
	return GetAbsOrigin () + GetViewOffset ();
}

float CBaseEntity::GetChargeDamage ()
{
	DYNVAR_RETURN (float, this, "DT_TFSniperRifle", "SniperRifleLocalData", "m_flChargedDamage");
}

int &CBaseEntity::GetTickBase ()
{
	DYNVAR_RETURN (int &, this, "DT_BasePlayer", "localdata", "m_nTickBase");
}

// TODO: move me to CBaseCombatWeapon
float CBaseEntity::GetNextAttack ()
{
	DYNVAR_RETURN (float, this, "DT_BaseCombatWeapon", "LocalActiveWeaponData", "m_flNextPrimaryAttack");
}

float CBaseEntity::GetLastFireTime ()
{
	DYNVAR_RETURN (float, this, "DT_TFWeaponBase", "LocalActiveTFWeaponData", "m_flLastFireTime");
}

Vector &CBaseEntity::GetVelocity ()
{
	DYNVAR_RETURN (Vector &, this, "DT_BasePlayer", "localdata", "m_vecBaseVelocity");
}

int &CBaseEntity::GetCond ()
{
	DYNVAR_RETURN (int &, this, "DT_TFPlayer", "m_Shared", "m_nPlayerCond");
}

int &CBaseEntity::GetCondEx ()
{
	DYNVAR_RETURN (int &, this, "DT_TFPlayer", "m_Shared", "m_nPlayerCondEx");
}

int &CBaseEntity::GetCondEx2 ()
{
	DYNVAR_RETURN (int &, this, "DT_TFPlayer", "m_Shared", "m_nPlayerCondEx2");
}

int &CBaseEntity::GetCondEx3 ()
{
	DYNVAR_RETURN (int &, this, "DT_TFPlayer", "m_Shared", "m_nPlayerCondEx3");
}

void CBaseEntity::SetCond (int c)
{
	DYNVAR (n, int, "DT_TFPlayer", "m_Shared", "m_nPlayerCond");
	return n.SetValue (this, c);
}

// backup local player cond
bool realZoom = false;
bool CBaseEntity::IsZoomed ()
{
	return GetCond () & tf_cond::TFCond_Zoomed;
}

void CBaseEntity::SetZoomed (bool state)
{
	if (GetIndex () == me) {
		realZoom = state;
	} else {
		state ? GetCond () |= tf_cond::TFCond_Zoomed : GetCond () &= ~tf_cond::TFCond_Zoomed;
	}
}

QAngle &CBaseEntity::GetPunchAngles ()
{
	DYNVAR_RETURN (QAngle &, this, "DT_BasePlayer", "localdata", "m_Local", "m_vecPunchAngle");
}

CBaseEntity *CBaseEntity::GetOwner ()
{
	DYNVAR (n, CBaseHandle, "DT_BaseCombatWeapon", "m_hOwner");
	return gInts->EntList->GetClientEntityFromHandle (n.GetValue (this));
}

moveTypes CBaseEntity::GetMoveType ()
{
	DYNVAR_RETURN (moveTypes, this, "DT_BaseEntity", "movetype");
}

ICollideable *CBaseEntity::GetCollision ()
{
	DYNVAR_RETURN (ICollideable *, this, "DT_BaseEntity", "m_Collision");
}

int CBaseEntity::GetRoundState ()
{
	DYNVAR_RETURN (int, this, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_iRoundState");
}

int CBaseEntity::GetFov ()
{
	DYNVAR_RETURN (int, this, "DT_BasePlayer", "m_iFOV");
}

void CBaseEntity::SetFov (int fov)
{
	DYNVAR (n, int, "DT_BasePlayer", "m_iFOV");
	return n.SetValue (this, fov);
}

QAngle &CBaseEntity::GetRotation ()
{
	DYNVAR_RETURN (QAngle &, this, "DT_BaseEntity", "m_angRotation");
}

Vector &CBaseEntity::GetRenderOrigin ()
{
	DYNVAR_RETURN (Vector &, this, "DT_BaseEntity", "m_vecOrigin");
}

float CBaseEntity::GetChargeTime ()
{
	DYNVAR_RETURN (float, this, "DT_WeaponPipebombLauncher", "PipebombLauncherLocalData", "m_flChargeBeginTime");
}

float lastZoomTime = 0.0f;
float CBaseEntity::GetZoomTime ()
{
	if (this->IsZoomed ()) {
		if (lastZoomTime == 0.0f)
			return lastZoomTime = gInts->Globals->curtime;

		return gInts->Globals->curtime - lastZoomTime;
	} else
		return lastZoomTime = 0.0f;
}

float &CBaseEntity::GetAnimTime ()
{
	DYNVAR_RETURN (float &, this, "DT_BaseEntity", "AnimTimeMustBeFirst", "m_flAnimTime");
}

float &CBaseEntity::GetOldAnimTime ()
{
	// TODO: insert return statement here
	DYNVAR_OFF_RETURN (float &, this, 0x4, "DT_BaseEntity", "AnimTimeMustBeFirst", "m_flAnimTime");
}

float &CBaseEntity::GetSimulationTime ()
{
	DYNVAR_RETURN (float &, this, "DT_BaseEntity", "m_flSimulationTime");
}

float &CBaseEntity::GetOldSimulationTime ()
{
	DYNVAR_OFF_RETURN (float &, this, 0x4, "DT_BaseEntity", "m_flSimulationTime");
}

void CBaseEntity::SetSimulationTime (float t)
{
	GetSimulationTime () = t;
}

int CBaseEntity::GetItemDefinitionIndex ()
{
	DYNVAR_RETURN (int, this, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_iItemDefinitionIndex");
}

Vector &CBaseEntity::GetCollideableMinsPrescaled ()
{
	DYNVAR_RETURN (Vector &, this, "DT_BaseEntity", "m_Collision", "m_vecMinsPreScaled");
}

Vector &CBaseEntity::GetCollideableMaxsPrescaled ()
{
	DYNVAR_RETURN (Vector &, this, "DT_BaseEntity", "m_Collision", "m_vecMaxsPreScaled");
}

Vector &CBaseEntity::GetCollideableMins ()
{
	DYNVAR_RETURN (Vector &, this, "DT_BaseEntity", "m_Collision", "m_vecMins");
}

Vector &CBaseEntity::GetCollideableMaxs ()
{
	DYNVAR_RETURN (Vector &, this, "DT_BaseEntity", "m_Collision", "m_vecMaxs");
}

CBaseEntity *CBaseEntity::GetGroundEntity ()
{
	DYNVAR (n, CHandle<CBaseEntity>, "DT_BasePlayer", "localdata", "m_hGroundEntity");
	return gInts->EntList->GetClientEntityFromHandle (n.GetValue (this));
}

bool CBaseEntity::IsTouchingGround ()
{
	return GetGroundEntity ();
}

float CBaseEntity::GetMaxSpeed ()
{
	DYNVAR_RETURN (float, this, "DT_BasePlayer", "m_flMaxspeed");
}

int &CBaseEntity::GetSequence ()
{
	DYNVAR_RETURN (int &, this, "DT_BaseAnimating", "m_nSequence");
}

float &CBaseEntity::GetCycle ()
{
	DYNVAR_RETURN (float &, this, "DT_BaseAnimating", "serveranimdata", "m_flCycle");
}

void CBaseEntity::SetSequence (int seq)
{
	GetSequence () = seq;
}

void CBaseEntity::SetCycle (int cyc)
{
	// TODO: invalidatephysicsrecursive "55 8B EC 51 53 8B 5D 08 56 8B F3 83 E6 04"
	GetCycle () = cyc;
}

float &CBaseEntity::GetPlaybackRate ()
{
	DYNVAR_RETURN (float &, this, "DT_BaseAnimating", "m_flPlaybackRate");
}

QAngle CBaseEntity::GetEyeAngles ()
{
	// There is no way to ensure that we will not mess up the .z part
	// and since that overlaps another data member, bad things will happen !
	DYNVAR (ang0, float, "DT_TFPlayer", "tfnonlocaldata", "m_angEyeAngles[0]");
	DYNVAR (ang1, float, "DT_TFPlayer", "tfnonlocaldata", "m_angEyeAngles[1]");
	return {ang0.GetValue (this), ang1.GetValue (this), 0.0f}; // z angle will always be 0
}

void CBaseEntity::SetEyeAngles (QAngle ang)
{
	DYNVAR (ang0, float, "DT_TFPlayer", "tfnonlocaldata", "m_angEyeAngles[0]");
	DYNVAR (ang1, float, "DT_TFPlayer", "tfnonlocaldata", "m_angEyeAngles[1]");
	ang0.SetValue (this, ang.x);
	ang0.SetValue (this, ang.y);
}

bool CBaseEntity::UseClassAnimations ()
{
	DYNVAR_RETURN (bool, this, "DT_TFPlayer", "m_PlayerClass", "m_bUseClassAnimations");
}

Vector &CBaseEntity::GetCustomModelOffset ()
{
	DYNVAR_RETURN (Vector &, this, "DT_TFPlayer", "m_PlayerClass", "m_vecCustomModelOffset");
}

bool CBaseEntity::GetCustomModelRotates ()
{
	DYNVAR_RETURN (bool, this, "DT_TFPlayer", "m_PlayerClass", "m_bCustomModelRotates");
}

bool CBaseEntity::GetCustomModelRotationSet ()
{
	DYNVAR_RETURN (bool, this, "DT_TFPlayer", "m_PlayerClass", "m_bCustomModelRotationSet");
}

QAngle &CBaseEntity::GetCustomModelRotation ()
{
	DYNVAR_RETURN (QAngle &, this, "DT_TFPlayer", "m_PlayerClass", "m_vecCustomModelRotation");
}

float &CBaseEntity::GetModelScale ()
{
	DYNVAR_RETURN (float &, this, "DT_BaseAnimating", "m_flModelScale");
}

bool CBaseEntity::IsCritBoosted ()
{
	int &cond   = GetCond ();
	int &condEx = GetCondEx ();

	return cond & tf_cond::TFCond_Kritzkrieged || condEx & tf_cond_ex::TFCondEx_CritCanteen || condEx & tf_cond_ex::TFCondEx_CritOnFirstBlood || condEx & tf_cond_ex::TFCondEx_CritOnWin || condEx & tf_cond_ex::TFCondEx_HalloweenCritCandy || condEx & tf_cond_ex::TFCondEx_PyroCrits;

	return false;
}

float CBaseEntity::GetCritMult ()
{
	// we need to do remap value on this
	DYNVAR (n, float, "DT_TFPlayer", "m_Shared", "m_iCritMult");
	return RemapValClamped (n.GetValue (this), 0, 255, 1.0, 4.0);
}

float CBaseEntity::GetObservedCritChance ()
{
	DYNVAR_RETURN (float, this, "DT_TFWeaponBase", "LocalActiveTFWeaponData", "m_flObservedCritChance");
}

bool CBaseEntity::IsEffectActive (int effects)
{
	DYNVAR (n, int, "DT_BaseEntity", "m_fEffects");
	return (n.GetValue (this) & effects) != 0;
}

int CBaseEntity::GetModelIndex ()
{
	DYNVAR_RETURN (int, this, "DT_BaseEntity", "m_nModelIndex");
}

int &CBaseEntity::GetObserverMode ()
{
	DYNVAR_RETURN (int &, this, "DT_BasePlayer", "m_iObserverMode");
}

bool CBaseCombatCharacter::IsGlowEnabled ()
{
	DYNVAR_RETURN (bool, this, "DT_TFPlayer", "m_bGlowEnabled");
}

void CBaseCombatCharacter::SetGlowEnabled (bool t)
{
	DYNVAR (n, bool, "DT_TFPlayer", "m_bGlowEnabled");
	return n.SetValue (this, t);
}

int CObject::GetLevel ()
{
	DYNVAR_RETURN (int, this, "DT_BaseObject", "m_iUpgradeLevel");
}

bool CObject::IsSapped ()
{
	DYNVAR_RETURN (int, this, "DT_BaseObject", "m_bHasSapper");
}

bool CObject::IsBuilding ()
{
	DYNVAR_RETURN (int, this, "DT_BaseObject", "m_bBuilding");
}

float CObject::GetPercentageConstructed ()
{
	if (IsBuilding ()) {
		DYNVAR_RETURN (int, this, "DT_BaseObject", "m_flPercentageConstructed");
	} else
		return 0;
}

int CObject::GetHealth ()
{
	DYNVAR_RETURN (int, this, "DT_BaseObject", "m_iHealth");
}

int CObject::GetUpgradedMetal ()
{
	DYNVAR_RETURN (int, this, "DT_BaseObject", "m_iUpgradeMetal");
}

int CObjectTeleporter::GetState ()
{
	DYNVAR_RETURN (int, this, "DT_ObjectTeleporter", "m_iState");
}

const char *CObjectTeleporter::GetStateString ()
{
	switch (GetState ()) {
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

int CObjectSentryGun::GetRocket ()
{
	if (GetLevel () == 3) {
		DYNVAR_RETURN (int, this, "DT_ObjectSentrygun", "m_iAmmoRockets");
	}
	return NULL;
}

int CObjectSentryGun::GetAmmo ()
{
	DYNVAR_RETURN (int, this, "DT_ObjectSentrygun", "m_iAmmoShells");
}

bool CObjectSentryGun::IsControlled ()
{
	DYNVAR_RETURN (bool, this, "DT_ObjectSentrygun", "m_bPlayerControlled");
}

int CObjectSentryGun::GetState ()
{
	DYNVAR_RETURN (int, this, "DT_ObjectSentrygun", "m_iState");
}

const char *CObjectSentryGun::GetStateString ()
{
	switch (GetState ()) {
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

int CObjectDispenser::GetMetalReserve ()
{
	DYNVAR_RETURN (int, this, "DT_ObjectDispenser", "m_iAmmoMetal");
}
