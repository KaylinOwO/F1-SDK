
#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include "DynamicNetvars.hh"
#include "SourceSDK.hh"

#define NETVAR(name, type, ...) static Netvar<type> name (__VA_ARGS__)
#define NETVAR_RETURN(type, base, ...) \
	NETVAR (n, type, __VA_ARGS__);     \
	return n.GetValue (base)
#define NETVAR_RETURN_THIS(type, ...) \
	NETVAR (n, type, __VA_ARGS__);    \
	return n.GetValue (this)
#define NETVAR_RETURN_ARRAY_THIS(type, ...) \
	NETVAR (n, type, __VA_ARGS__);          \
	return (type) ((DWORD)this + n.GetOffset ())

#define NETVAR_REFLECTION(className, baseClassName) \
	typedef baseClassName BaseClass;                \
	typedef className     ThisClass;                \
	\
public:                                             \
	static char const *ClassName ()                 \
	{                                               \
		return #className;                          \
	}                                               \
	static char const *BaseClassName ()             \
	{                                               \
		return #baseClassName;                      \
	}

#define NETVAR_REFLECTION_NOBASE(className) \
	typedef className ThisClass;            \
	\
public:                                     \
	static char const *ClassName ()         \
	{                                       \
		return #className;                  \
	}

struct DT_BaseEntity
{
	NETVAR_REFLECTION_NOBASE (DT_BaseEntity);
	struct CAnimTimeMustBeFirst
	{
		NETVAR_REFLECTION (CAnimTimeMustBeFirst, DT_BaseEntity);
		inline float &flAnimTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_BaseEntity", "AnimTimeMustBeFirst", "m_flAnimTime");
		}
	};
	struct CCollisionProperty
	{
		NETVAR_REFLECTION (CCollisionProperty, DT_BaseEntity);
		inline Vector &vecMinsPreScaled ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BaseEntity", "m_Collision", "m_vecMinsPreScaled");
		}
		inline Vector &vecMaxsPreScaled ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BaseEntity", "m_Collision", "m_vecMaxsPreScaled");
		}
		inline Vector &vecMins ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BaseEntity", "m_Collision", "m_vecMins");
		}
		inline Vector &vecMaxs ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BaseEntity", "m_Collision", "m_vecMaxs");
		}
		inline int &nSolidType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_Collision", "m_nSolidType");
		}
		inline int &usSolidFlags ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_Collision", "m_usSolidFlags");
		}
		inline int &nSurroundType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_Collision", "m_nSurroundType");
		}
		inline int &triggerBloat ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_Collision", "m_triggerBloat");
		}
		inline Vector &vecSpecifiedSurroundingMinsPreScaled ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BaseEntity", "m_Collision", "m_vecSpecifiedSurroundingMinsPreScaled");
		}
		inline Vector &vecSpecifiedSurroundingMaxsPreScaled ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BaseEntity", "m_Collision", "m_vecSpecifiedSurroundingMaxsPreScaled");
		}
		inline Vector &vecSpecifiedSurroundingMins ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BaseEntity", "m_Collision", "m_vecSpecifiedSurroundingMins");
		}
		inline Vector &vecSpecifiedSurroundingMaxs ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BaseEntity", "m_Collision", "m_vecSpecifiedSurroundingMaxs");
		}
	};
	struct CPredictableId
	{
		NETVAR_REFLECTION (CPredictableId, DT_BaseEntity);
		inline int &PredictableID ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "predictable_id", "m_PredictableID");
		}
		inline bool &bIsPlayerSimulated ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_BaseEntity", "predictable_id", "m_bIsPlayerSimulated");
		}
	};
	inline CAnimTimeMustBeFirst &AnimTimeMustBeFirst ()
	{
		NETVAR_RETURN_THIS (CAnimTimeMustBeFirst &, "DT_BaseEntity", "AnimTimeMustBeFirst");
	}
	inline float &flSimulationTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseEntity", "m_flSimulationTime");
	}
	inline int &ubInterpolationFrame ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_ubInterpolationFrame");
	}
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_BaseEntity", "m_vecOrigin");
	}
	inline QAngle &angRotation ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_BaseEntity", "m_angRotation");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_nModelIndex");
	}
	inline int &fEffects ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_fEffects");
	}
	inline int &nRenderMode ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_nRenderMode");
	}
	inline int &nRenderFX ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_nRenderFX");
	}
	inline int &clrRender ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_clrRender");
	}
	inline int &iTeamNum ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_iTeamNum");
	}
	inline int &CollisionGroup ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_CollisionGroup");
	}
	inline float &flElasticity ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseEntity", "m_flElasticity");
	}
	inline float &flShadowCastDistance ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseEntity", "m_flShadowCastDistance");
	}
	inline EHANDLE &hOwnerEntity ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BaseEntity", "m_hOwnerEntity");
	}
	inline EHANDLE &hEffectEntity ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BaseEntity", "m_hEffectEntity");
	}
	inline int &moveparent ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "moveparent");
	}
	inline int &iParentAttachment ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_iParentAttachment");
	}
	inline int &movetype ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "movetype");
	}
	inline int &movecollide ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "movecollide");
	}
	inline CCollisionProperty &Collision ()
	{
		NETVAR_RETURN_THIS (CCollisionProperty &, "DT_BaseEntity", "m_Collision");
	}
	inline int &iTextureFrameIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseEntity", "m_iTextureFrameIndex");
	}
	inline CPredictableId &predictable_id ()
	{
		NETVAR_RETURN_THIS (CPredictableId &, "DT_BaseEntity", "predictable_id");
	}
	inline bool &bSimulatedEveryTick ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseEntity", "m_bSimulatedEveryTick");
	}
	inline bool &bAnimatedEveryTick ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseEntity", "m_bAnimatedEveryTick");
	}
	inline bool &bAlternateSorting ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseEntity", "m_bAlternateSorting");
	}
	inline int *nModelIndexOverrides ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseEntity", "m_nModelIndexOverrides");
	} // Array size = 4
};
struct DT_BaseAnimating : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_BaseAnimating, DT_BaseEntity);
	struct CServerAnimationData
	{
		NETVAR_REFLECTION (CServerAnimationData, DT_BaseAnimating);
		inline float &flCycle ()
		{
			NETVAR_RETURN_THIS (float &, "DT_BaseAnimating", "serveranimdata", "m_flCycle");
		}
	};
	inline int &nSequence ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseAnimating", "m_nSequence");
	}
	inline int &nForceBone ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseAnimating", "m_nForceBone");
	}
	inline Vector &vecForce ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_BaseAnimating", "m_vecForce");
	}
	inline int &nSkin ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseAnimating", "m_nSkin");
	}
	inline int &nBody ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseAnimating", "m_nBody");
	}
	inline int &nHitboxSet ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseAnimating", "m_nHitboxSet");
	}
	inline float &flModelScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseAnimating", "m_flModelScale");
	}
	inline float &flModelWidthScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseAnimating", "m_flModelWidthScale");
	}
	inline float *flPoseParameter ()
	{
		NETVAR_RETURN_ARRAY_THIS (float *, "DT_BaseAnimating", "m_flPoseParameter");
	} // Array size = 24
	inline float &flPlaybackRate ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseAnimating", "m_flPlaybackRate");
	}
	inline float *flEncodedController ()
	{
		NETVAR_RETURN_ARRAY_THIS (float *, "DT_BaseAnimating", "m_flEncodedController");
	} // Array size = 4
	inline bool &bClientSideAnimation ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseAnimating", "m_bClientSideAnimation");
	}
	inline bool &bClientSideFrameReset ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseAnimating", "m_bClientSideFrameReset");
	}
	inline int &nNewSequenceParity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseAnimating", "m_nNewSequenceParity");
	}
	inline int &nResetEventsParity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseAnimating", "m_nResetEventsParity");
	}
	inline int &nMuzzleFlashParity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseAnimating", "m_nMuzzleFlashParity");
	}
	inline EHANDLE &hLightingOrigin ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BaseAnimating", "m_hLightingOrigin");
	}
	inline EHANDLE &hLightingOriginRelative ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BaseAnimating", "m_hLightingOriginRelative");
	}
	inline CServerAnimationData &serveranimdata ()
	{
		NETVAR_RETURN_THIS (CServerAnimationData &, "DT_BaseAnimating", "serveranimdata");
	}
	inline int &fadeMinDist ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseAnimating", "m_fadeMinDist");
	}
	inline int &fadeMaxDist ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseAnimating", "m_fadeMaxDist");
	}
	inline float &flFadeScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseAnimating", "m_flFadeScale");
	}
};
struct DT_EconEntity : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_EconEntity, DT_BaseAnimating);
	struct CAttributeContainer
	{
		NETVAR_REFLECTION (CAttributeContainer, DT_EconEntity);
		struct CScriptCreatedItem
		{
			NETVAR_REFLECTION (CScriptCreatedItem, CAttributeContainer);
			struct CAttributeList
			{
				NETVAR_REFLECTION (CAttributeList, CScriptCreatedItem);
			}; // Fail count = 1
			inline int &iItemDefinitionIndex ()
			{
				NETVAR_RETURN_THIS (int &, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_iItemDefinitionIndex");
			}
			inline int &iEntityLevel ()
			{
				NETVAR_RETURN_THIS (int &, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_iEntityLevel");
			}
			inline int &iItemIDHigh ()
			{
				NETVAR_RETURN_THIS (int &, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_iItemIDHigh");
			}
			inline int &iItemIDLow ()
			{
				NETVAR_RETURN_THIS (int &, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_iItemIDLow");
			}
			inline int &iAccountID ()
			{
				NETVAR_RETURN_THIS (int &, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_iAccountID");
			}
			inline int &iEntityQuality ()
			{
				NETVAR_RETURN_THIS (int &, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_iEntityQuality");
			}
			inline bool &bInitialized ()
			{
				NETVAR_RETURN_THIS (bool &, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_bInitialized");
			}
			inline bool &bOnlyIterateItemViewAttributes ()
			{
				NETVAR_RETURN_THIS (bool &, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_bOnlyIterateItemViewAttributes");
			}
			inline CAttributeList &AttributeList ()
			{
				NETVAR_RETURN_THIS (CAttributeList &, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_AttributeList");
			}
			inline int &iTeamNumber ()
			{
				NETVAR_RETURN_THIS (int &, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_iTeamNumber");
			}
			inline CAttributeList &NetworkedDynamicAttributesForDemos ()
			{
				NETVAR_RETURN_THIS (CAttributeList &, "DT_EconEntity", "m_AttributeManager", "m_Item", "m_NetworkedDynamicAttributesForDemos");
			}
		};
		inline EHANDLE &hOuter ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_EconEntity", "m_AttributeManager", "m_hOuter");
		}
		inline int &ProviderType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_EconEntity", "m_AttributeManager", "m_ProviderType");
		}
		inline int &iReapplyProvisionParity ()
		{
			NETVAR_RETURN_THIS (int &, "DT_EconEntity", "m_AttributeManager", "m_iReapplyProvisionParity");
		}
		inline CScriptCreatedItem &Item ()
		{
			NETVAR_RETURN_THIS (CScriptCreatedItem &, "DT_EconEntity", "m_AttributeManager", "m_Item");
		}
	};
	inline CAttributeContainer &AttributeManager ()
	{
		NETVAR_RETURN_THIS (CAttributeContainer &, "DT_EconEntity", "m_AttributeManager");
	}
	inline bool &bValidatedAttachedEntity ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_EconEntity", "m_bValidatedAttachedEntity");
	}
};
struct DT_WearableItem : public DT_EconEntity
{
	NETVAR_REFLECTION (DT_WearableItem, DT_EconEntity);
};
struct DT_TFWearable : public DT_WearableItem
{
	NETVAR_REFLECTION (DT_TFWearable, DT_WearableItem);
	inline bool &bDisguiseWearable ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFWearable", "m_bDisguiseWearable");
	}
	inline EHANDLE &hWeaponAssociatedWith ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFWearable", "m_hWeaponAssociatedWith");
	}
};
struct DT_TFWearableLevelableItem : public DT_TFWearable
{
	NETVAR_REFLECTION (DT_TFWearableLevelableItem, DT_TFWearable);
	inline int &unLevel ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFWearableLevelableItem", "m_unLevel");
	}
};
struct DT_TFWearableDemoShield : public DT_TFWearable
{
	NETVAR_REFLECTION (DT_TFWearableDemoShield, DT_TFWearable);
};
struct DT_BaseProjectile : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_BaseProjectile, DT_BaseAnimating);
	inline EHANDLE &hOriginalLauncher ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BaseProjectile", "m_hOriginalLauncher");
	}
};
struct DT_TFBaseRocket : public DT_BaseProjectile
{
	NETVAR_REFLECTION (DT_TFBaseRocket, DT_BaseProjectile);
	inline Vector &vInitialVelocity ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TFBaseRocket", "m_vInitialVelocity");
	}
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TFBaseRocket", "m_vecOrigin");
	}
	inline QAngle &angRotation ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_TFBaseRocket", "m_angRotation");
	}
	inline int &iDeflected ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFBaseRocket", "m_iDeflected");
	}
	inline EHANDLE &hLauncher ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFBaseRocket", "m_hLauncher");
	}
};
struct DT_BaseGrenade : public DT_BaseProjectile
{
	NETVAR_REFLECTION (DT_BaseGrenade, DT_BaseProjectile);
	inline float &flDamage ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseGrenade", "m_flDamage");
	}
	inline float &DmgRadius ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseGrenade", "m_DmgRadius");
	}
	inline bool &bIsLive ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseGrenade", "m_bIsLive");
	}
	inline EHANDLE &hThrower ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BaseGrenade", "m_hThrower");
	}
	inline Vector &vecVelocity ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_BaseGrenade", "m_vecVelocity");
	}
	inline int &fFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseGrenade", "m_fFlags");
	}
};
struct DT_TFWeaponBaseMerasmusGrenade : public DT_BaseGrenade
{
	NETVAR_REFLECTION (DT_TFWeaponBaseMerasmusGrenade, DT_BaseGrenade);
};
struct DT_BaseCombatWeapon : public DT_EconEntity
{
	NETVAR_REFLECTION (DT_BaseCombatWeapon, DT_EconEntity);
	struct CLocalWeaponData
	{
		NETVAR_REFLECTION (CLocalWeaponData, DT_BaseCombatWeapon);
		inline int &iClip1 ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BaseCombatWeapon", "LocalWeaponData", "m_iClip1");
		}
		inline int &iClip2 ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BaseCombatWeapon", "LocalWeaponData", "m_iClip2");
		}
		inline int &iPrimaryAmmoType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BaseCombatWeapon", "LocalWeaponData", "m_iPrimaryAmmoType");
		}
		inline int &iSecondaryAmmoType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BaseCombatWeapon", "LocalWeaponData", "m_iSecondaryAmmoType");
		}
		inline int &nViewModelIndex ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BaseCombatWeapon", "LocalWeaponData", "m_nViewModelIndex");
		}
		inline bool &bFlipViewModel ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_BaseCombatWeapon", "LocalWeaponData", "m_bFlipViewModel");
		}
	};
	struct CLocalActiveWeaponData
	{
		NETVAR_REFLECTION (CLocalActiveWeaponData, DT_BaseCombatWeapon);
		inline float &flNextPrimaryAttack ()
		{
			NETVAR_RETURN_THIS (float &, "DT_BaseCombatWeapon", "LocalActiveWeaponData", "m_flNextPrimaryAttack");
		}
		inline float &flNextSecondaryAttack ()
		{
			NETVAR_RETURN_THIS (float &, "DT_BaseCombatWeapon", "LocalActiveWeaponData", "m_flNextSecondaryAttack");
		}
		inline int &nNextThinkTick ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BaseCombatWeapon", "LocalActiveWeaponData", "m_nNextThinkTick");
		}
		inline float &flTimeWeaponIdle ()
		{
			NETVAR_RETURN_THIS (float &, "DT_BaseCombatWeapon", "LocalActiveWeaponData", "m_flTimeWeaponIdle");
		}
	};
	inline CLocalWeaponData &LocalWeaponData ()
	{
		NETVAR_RETURN_THIS (CLocalWeaponData &, "DT_BaseCombatWeapon", "LocalWeaponData");
	}
	inline CLocalActiveWeaponData &LocalActiveWeaponData ()
	{
		NETVAR_RETURN_THIS (CLocalActiveWeaponData &, "DT_BaseCombatWeapon", "LocalActiveWeaponData");
	}
	inline int &iViewModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseCombatWeapon", "m_iViewModelIndex");
	}
	inline int &iWorldModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseCombatWeapon", "m_iWorldModelIndex");
	}
	inline int &iState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseCombatWeapon", "m_iState");
	}
	inline EHANDLE &hOwner ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BaseCombatWeapon", "m_hOwner");
	}
};
struct DT_TFWeaponBase : public DT_BaseCombatWeapon
{
	NETVAR_REFLECTION (DT_TFWeaponBase, DT_BaseCombatWeapon);
	struct CLocalTFWeaponData
	{
		NETVAR_REFLECTION (CLocalTFWeaponData, DT_TFWeaponBase);
		inline float &flLastCritCheckTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFWeaponBase", "LocalActiveTFWeaponData", "m_flLastCritCheckTime");
		}
		inline float &flReloadPriorNextFire ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFWeaponBase", "LocalActiveTFWeaponData", "m_flReloadPriorNextFire");
		}
		inline float &flLastFireTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFWeaponBase", "LocalActiveTFWeaponData", "m_flLastFireTime");
		}
		inline float &flEffectBarRegenTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFWeaponBase", "LocalActiveTFWeaponData", "m_flEffectBarRegenTime");
		}
		inline float &flObservedCritChance ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFWeaponBase", "LocalActiveTFWeaponData", "m_flObservedCritChance");
		}
	};
	struct CTFWeaponDataNonLocal
	{
		NETVAR_REFLECTION (CTFWeaponDataNonLocal, DT_TFWeaponBase);
	};
	inline bool &bLowered ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFWeaponBase", "m_bLowered");
	}
	inline int &iReloadMode ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFWeaponBase", "m_iReloadMode");
	}
	inline bool &bResetParity ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFWeaponBase", "m_bResetParity");
	}
	inline bool &bReloadedThroughAnimEvent ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFWeaponBase", "m_bReloadedThroughAnimEvent");
	}
	inline bool &bDisguiseWeapon ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFWeaponBase", "m_bDisguiseWeapon");
	}
	inline CLocalTFWeaponData &LocalActiveTFWeaponData ()
	{
		NETVAR_RETURN_THIS (CLocalTFWeaponData &, "DT_TFWeaponBase", "LocalActiveTFWeaponData");
	}
	inline CTFWeaponDataNonLocal &NonLocalTFWeaponData ()
	{
		NETVAR_RETURN_THIS (CTFWeaponDataNonLocal &, "DT_TFWeaponBase", "NonLocalTFWeaponData");
	}
	inline float &flEnergy ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFWeaponBase", "m_flEnergy");
	}
	inline EHANDLE &hExtraWearable ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFWeaponBase", "m_hExtraWearable");
	}
	inline EHANDLE &hExtraWearableViewModel ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFWeaponBase", "m_hExtraWearableViewModel");
	}
	inline bool &bBeingRepurposedForTaunt ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFWeaponBase", "m_bBeingRepurposedForTaunt");
	}
	inline int &nKillComboClass ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFWeaponBase", "m_nKillComboClass");
	}
	inline int &nKillComboCount ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFWeaponBase", "m_nKillComboCount");
	}
	inline float &flInspectAnimTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFWeaponBase", "m_flInspectAnimTime");
	}
	inline int &nInspectStage ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFWeaponBase", "m_nInspectStage");
	}
};
struct DT_TFWeaponBaseMelee : public DT_TFWeaponBase
{
	NETVAR_REFLECTION (DT_TFWeaponBaseMelee, DT_TFWeaponBase);
};
struct DT_TFWeaponBaseGun : public DT_TFWeaponBase
{
	NETVAR_REFLECTION (DT_TFWeaponBaseGun, DT_TFWeaponBase);
};
struct DT_TFWeaponBaseGrenadeProj : public DT_BaseGrenade
{
	NETVAR_REFLECTION (DT_TFWeaponBaseGrenadeProj, DT_BaseGrenade);
	inline Vector &vInitialVelocity ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TFWeaponBaseGrenadeProj", "m_vInitialVelocity");
	}
	inline bool &bCritical ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFWeaponBaseGrenadeProj", "m_bCritical");
	}
	inline int &iDeflected ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFWeaponBaseGrenadeProj", "m_iDeflected");
	}
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TFWeaponBaseGrenadeProj", "m_vecOrigin");
	}
	inline QAngle &angRotation ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_TFWeaponBaseGrenadeProj", "m_angRotation");
	}
	inline EHANDLE &hDeflectOwner ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFWeaponBaseGrenadeProj", "m_hDeflectOwner");
	}
};
struct DT_TFWearableRobotArm : public DT_TFWearable
{
	NETVAR_REFLECTION (DT_TFWearableRobotArm, DT_TFWearable);
};
struct DT_TFWeaponWrench : public DT_TFWeaponBaseMelee
{
	NETVAR_REFLECTION (DT_TFWeaponWrench, DT_TFWeaponBaseMelee);
};
struct DT_TFWeaponRobotArm : public DT_TFWeaponWrench
{
	NETVAR_REFLECTION (DT_TFWeaponRobotArm, DT_TFWeaponWrench);
	inline EHANDLE &hRobotArm ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFWeaponRobotArm", "m_hRobotArm");
	}
};
struct DT_TFProjectile_Pipebomb : public DT_TFWeaponBaseGrenadeProj
{
	NETVAR_REFLECTION (DT_TFProjectile_Pipebomb, DT_TFWeaponBaseGrenadeProj);
	inline bool &bTouched ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFProjectile_Pipebomb", "m_bTouched");
	}
	inline int &iType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFProjectile_Pipebomb", "m_iType");
	}
	inline EHANDLE &hLauncher ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFProjectile_Pipebomb", "m_hLauncher");
	}
	inline bool &bDefensiveBomb ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFProjectile_Pipebomb", "m_bDefensiveBomb");
	}
};
struct DT_TFProjectile_Jar : public DT_TFProjectile_Pipebomb
{
	NETVAR_REFLECTION (DT_TFProjectile_Jar, DT_TFProjectile_Pipebomb);
};
struct DT_TFProjectile_Throwable : public DT_TFProjectile_Jar
{
	NETVAR_REFLECTION (DT_TFProjectile_Throwable, DT_TFProjectile_Jar);
};
struct DT_TFProjectile_ThrowableBreadMonster : public DT_TFProjectile_Throwable
{
	NETVAR_REFLECTION (DT_TFProjectile_ThrowableBreadMonster, DT_TFProjectile_Throwable);
};
struct DT_TFProjectile_ThrowableBrick : public DT_TFProjectile_Throwable
{
	NETVAR_REFLECTION (DT_TFProjectile_ThrowableBrick, DT_TFProjectile_Throwable);
};
struct DT_TFProjectile_ThrowableRepel : public DT_TFProjectile_Throwable
{
	NETVAR_REFLECTION (DT_TFProjectile_ThrowableRepel, DT_TFProjectile_Throwable);
};
struct DT_TFWeaponJar : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_TFWeaponJar, DT_TFWeaponBaseGun);
};
struct DT_TFWeaponThrowable : public DT_TFWeaponJar
{
	NETVAR_REFLECTION (DT_TFWeaponThrowable, DT_TFWeaponJar);
	inline float &flChargeBeginTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFWeaponThrowable", "m_flChargeBeginTime");
	}
};
struct DT_WeaponSyringeGun : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_WeaponSyringeGun, DT_TFWeaponBaseGun);
};
struct DT_TFWeaponKatana : public DT_TFWeaponBaseMelee
{
	NETVAR_REFLECTION (DT_TFWeaponKatana, DT_TFWeaponBaseMelee);
	inline bool &bIsBloody ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFWeaponKatana", "m_bIsBloody");
	}
};
struct DT_TFWeaponSword : public DT_TFWeaponBaseMelee
{
	NETVAR_REFLECTION (DT_TFWeaponSword, DT_TFWeaponBaseMelee);
};
struct DT_SniperDot : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_SniperDot, DT_BaseEntity);
	inline float &flChargeStartTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SniperDot", "m_flChargeStartTime");
	}
};
struct DT_TFSniperRifle : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_TFSniperRifle, DT_TFWeaponBaseGun);
	struct CSniperRifleLocalData
	{
		NETVAR_REFLECTION (CSniperRifleLocalData, DT_TFSniperRifle);
		inline float &flChargedDamage ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFSniperRifle", "SniperRifleLocalData", "m_flChargedDamage");
		}
	};
	inline CSniperRifleLocalData &SniperRifleLocalData ()
	{
		NETVAR_RETURN_THIS (CSniperRifleLocalData &, "DT_TFSniperRifle", "SniperRifleLocalData");
	}
};
struct DT_TFSniperRifleClassic : public DT_TFSniperRifle
{
	NETVAR_REFLECTION (DT_TFSniperRifleClassic, DT_TFSniperRifle);
	inline bool &bCharging ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFSniperRifleClassic", "m_bCharging");
	}
};
struct DT_TFSniperRifleDecap : public DT_TFSniperRifle
{
	NETVAR_REFLECTION (DT_TFSniperRifleDecap, DT_TFSniperRifle);
};
struct DT_TFSMG : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_TFSMG, DT_TFWeaponBaseGun);
};
struct DT_WeaponChargedSMG : public DT_TFSMG
{
	NETVAR_REFLECTION (DT_WeaponChargedSMG, DT_TFSMG);
	inline float &flMinicritCharge ()
	{
		NETVAR_RETURN_THIS (float &, "DT_WeaponChargedSMG", "m_flMinicritCharge");
	}
};
struct DT_TFWeaponShovel : public DT_TFWeaponBaseMelee
{
	NETVAR_REFLECTION (DT_TFWeaponShovel, DT_TFWeaponBaseMelee);
};
struct DT_TFShotgun : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_TFShotgun, DT_TFWeaponBaseGun);
};
struct DT_TFShotgunBuildingRescue : public DT_TFShotgun
{
	NETVAR_REFLECTION (DT_TFShotgunBuildingRescue, DT_TFShotgun);
};
struct DT_TFScatterGun : public DT_TFShotgun
{
	NETVAR_REFLECTION (DT_TFScatterGun, DT_TFShotgun);
};
struct DT_TFPEPBrawlerBlaster : public DT_TFScatterGun
{
	NETVAR_REFLECTION (DT_TFPEPBrawlerBlaster, DT_TFScatterGun);
};
struct DT_TFSodaPopper : public DT_TFScatterGun
{
	NETVAR_REFLECTION (DT_TFSodaPopper, DT_TFScatterGun);
};
struct DT_TFShotgun_Revenge : public DT_TFShotgun
{
	NETVAR_REFLECTION (DT_TFShotgun_Revenge, DT_TFShotgun);
};
struct DT_TFShotgun_Pyro : public DT_TFShotgun
{
	NETVAR_REFLECTION (DT_TFShotgun_Pyro, DT_TFShotgun);
};
struct DT_TFShotgun_HWG : public DT_TFShotgun
{
	NETVAR_REFLECTION (DT_TFShotgun_HWG, DT_TFShotgun);
};
struct DT_TFShotgun_Soldier : public DT_TFShotgun
{
	NETVAR_REFLECTION (DT_TFShotgun_Soldier, DT_TFShotgun);
};
struct DT_WeaponRocketLauncher : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_WeaponRocketLauncher, DT_TFWeaponBaseGun);
};
struct DT_Crossbow : public DT_WeaponRocketLauncher
{
	NETVAR_REFLECTION (DT_Crossbow, DT_WeaponRocketLauncher);
	inline float &flRegenerateDuration ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Crossbow", "m_flRegenerateDuration");
	}
	inline float &flLastUsedTimestamp ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Crossbow", "m_flLastUsedTimestamp");
	}
};
struct DT_WeaponRocketLauncher_Mortar : public DT_WeaponRocketLauncher
{
	NETVAR_REFLECTION (DT_WeaponRocketLauncher_Mortar, DT_WeaponRocketLauncher);
};
struct DT_WeaponRocketLauncher_AirStrike : public DT_WeaponRocketLauncher
{
	NETVAR_REFLECTION (DT_WeaponRocketLauncher_AirStrike, DT_WeaponRocketLauncher);
};
struct DT_WeaponRocketLauncher_DirectHit : public DT_WeaponRocketLauncher
{
	NETVAR_REFLECTION (DT_WeaponRocketLauncher_DirectHit, DT_WeaponRocketLauncher);
};
struct DT_WeaponRevolver : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_WeaponRevolver, DT_TFWeaponBaseGun);
};
struct DT_WeaponRaygun : public DT_WeaponRocketLauncher
{
	NETVAR_REFLECTION (DT_WeaponRaygun, DT_WeaponRocketLauncher);
	inline bool &bUseNewProjectileCode ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_WeaponRaygun", "m_bUseNewProjectileCode");
	}
};
struct DT_WeaponDRGPomson : public DT_WeaponRaygun
{
	NETVAR_REFLECTION (DT_WeaponDRGPomson, DT_WeaponRaygun);
};
struct DT_WeaponPistol : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_WeaponPistol, DT_TFWeaponBaseGun);
};
struct DT_WeaponPistol_Scout : public DT_WeaponPistol
{
	NETVAR_REFLECTION (DT_WeaponPistol_Scout, DT_WeaponPistol);
};
struct DT_WeaponPistol_ScoutSecondary : public DT_WeaponPistol_Scout
{
	NETVAR_REFLECTION (DT_WeaponPistol_ScoutSecondary, DT_WeaponPistol_Scout);
};
struct DT_WeaponPistol_ScoutPrimary : public DT_WeaponPistol_Scout
{
	NETVAR_REFLECTION (DT_WeaponPistol_ScoutPrimary, DT_WeaponPistol_Scout);
};
struct DT_WeaponPipebombLauncher : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_WeaponPipebombLauncher, DT_TFWeaponBaseGun);
	struct CPipebombLauncherLocalData
	{
		NETVAR_REFLECTION (CPipebombLauncherLocalData, DT_WeaponPipebombLauncher);
		inline int &iPipebombCount ()
		{
			NETVAR_RETURN_THIS (int &, "DT_WeaponPipebombLauncher", "PipebombLauncherLocalData", "m_iPipebombCount");
		}
		inline float &flChargeBeginTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_WeaponPipebombLauncher", "PipebombLauncherLocalData", "m_flChargeBeginTime");
		}
	};
	inline CPipebombLauncherLocalData &PipebombLauncherLocalData ()
	{
		NETVAR_RETURN_THIS (CPipebombLauncherLocalData &, "DT_WeaponPipebombLauncher", "PipebombLauncherLocalData");
	}
};
struct DT_TFWeaponPDA : public DT_TFWeaponBase
{
	NETVAR_REFLECTION (DT_TFWeaponPDA, DT_TFWeaponBase);
};
struct DT_TFWeaponPDA_Spy : public DT_TFWeaponPDA
{
	NETVAR_REFLECTION (DT_TFWeaponPDA_Spy, DT_TFWeaponPDA);
};
struct DT_TFWeaponPDA_Engineer_Destroy : public DT_TFWeaponPDA
{
	NETVAR_REFLECTION (DT_TFWeaponPDA_Engineer_Destroy, DT_TFWeaponPDA);
};
struct DT_TFWeaponPDA_Engineer_Build : public DT_TFWeaponPDA
{
	NETVAR_REFLECTION (DT_TFWeaponPDA_Engineer_Build, DT_TFWeaponPDA);
};
struct DT_TFWeaponPDAExpansion_Teleporter : public DT_TFWearable
{
	NETVAR_REFLECTION (DT_TFWeaponPDAExpansion_Teleporter, DT_TFWearable);
};
struct DT_TFWeaponPDAExpansion_Dispenser : public DT_TFWearable
{
	NETVAR_REFLECTION (DT_TFWeaponPDAExpansion_Dispenser, DT_TFWearable);
};
struct DT_ParticleCannon : public DT_WeaponRocketLauncher
{
	NETVAR_REFLECTION (DT_ParticleCannon, DT_WeaponRocketLauncher);
	inline float &flChargeBeginTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_ParticleCannon", "m_flChargeBeginTime");
	}
	inline int &iChargeEffect ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ParticleCannon", "m_iChargeEffect");
	}
};
struct DT_TFWeaponBuffItem : public DT_TFWeaponBaseMelee
{
	NETVAR_REFLECTION (DT_TFWeaponBuffItem, DT_TFWeaponBaseMelee);
};
struct DT_TFParachute : public DT_TFWeaponBuffItem
{
	NETVAR_REFLECTION (DT_TFParachute, DT_TFWeaponBuffItem);
};
struct DT_TFParachute_Secondary : public DT_TFParachute
{
	NETVAR_REFLECTION (DT_TFParachute_Secondary, DT_TFParachute);
};
struct DT_TFParachute_Primary : public DT_TFParachute
{
	NETVAR_REFLECTION (DT_TFParachute_Primary, DT_TFParachute);
};
struct DT_WeaponMinigun : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_WeaponMinigun, DT_TFWeaponBaseGun);
	inline int &iWeaponState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_WeaponMinigun", "m_iWeaponState");
	}
	inline bool &bCritShot ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_WeaponMinigun", "m_bCritShot");
	}
};
struct DT_TFMedigunShield : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_TFMedigunShield, DT_BaseAnimating);
};
struct DT_WeaponMedigun : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_WeaponMedigun, DT_TFWeaponBaseGun);
	struct CLocalTFWeaponMedigunData
	{
		NETVAR_REFLECTION (CLocalTFWeaponMedigunData, DT_WeaponMedigun);
		inline float &flChargeLevel ()
		{
			NETVAR_RETURN_THIS (float &, "DT_WeaponMedigun", "LocalTFWeaponMedigunData", "m_flChargeLevel");
		}
	};
	struct CTFWeaponMedigunDataNonLocal
	{
		NETVAR_REFLECTION (CTFWeaponMedigunDataNonLocal, DT_WeaponMedigun);
		inline float &flChargeLevel ()
		{
			NETVAR_RETURN_THIS (float &, "DT_WeaponMedigun", "NonLocalTFWeaponMedigunData", "m_flChargeLevel");
		}
	};
	inline EHANDLE &hHealingTarget ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_WeaponMedigun", "m_hHealingTarget");
	}
	inline bool &bHealing ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_WeaponMedigun", "m_bHealing");
	}
	inline bool &bAttacking ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_WeaponMedigun", "m_bAttacking");
	}
	inline bool &bChargeRelease ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_WeaponMedigun", "m_bChargeRelease");
	}
	inline bool &bHolstered ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_WeaponMedigun", "m_bHolstered");
	}
	inline int &nChargeResistType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_WeaponMedigun", "m_nChargeResistType");
	}
	inline CLocalTFWeaponMedigunData &LocalTFWeaponMedigunData ()
	{
		NETVAR_RETURN_THIS (CLocalTFWeaponMedigunData &, "DT_WeaponMedigun", "LocalTFWeaponMedigunData");
	}
	inline CTFWeaponMedigunDataNonLocal &NonLocalTFWeaponMedigunData ()
	{
		NETVAR_RETURN_THIS (CTFWeaponMedigunDataNonLocal &, "DT_WeaponMedigun", "NonLocalTFWeaponMedigunData");
	}
};
struct DT_TFMechanicalArm : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_TFMechanicalArm, DT_TFWeaponBaseGun);
};
struct DT_WeaponLunchBox : public DT_TFWeaponBase
{
	NETVAR_REFLECTION (DT_WeaponLunchBox, DT_TFWeaponBase);
};
struct DT_TFLunchBox_Drink : public DT_WeaponLunchBox
{
	NETVAR_REFLECTION (DT_TFLunchBox_Drink, DT_WeaponLunchBox);
};
struct DT_LaserDot : public DT_SniperDot
{
	NETVAR_REFLECTION (DT_LaserDot, DT_SniperDot);
};
struct DT_TFLaserPointer : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_TFLaserPointer, DT_TFWeaponBaseGun);
};
struct DT_TFWeaponKnife : public DT_TFWeaponBaseMelee
{
	NETVAR_REFLECTION (DT_TFWeaponKnife, DT_TFWeaponBaseMelee);
	inline bool &bReadyToBackstab ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFWeaponKnife", "m_bReadyToBackstab");
	}
	inline bool &bKnifeExists ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFWeaponKnife", "m_bKnifeExists");
	}
	inline float &flKnifeRegenerateDuration ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFWeaponKnife", "m_flKnifeRegenerateDuration");
	}
	inline float &flKnifeMeltTimestamp ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFWeaponKnife", "m_flKnifeMeltTimestamp");
	}
};
struct DT_TFProjectile_Cleaver : public DT_TFProjectile_Jar
{
	NETVAR_REFLECTION (DT_TFProjectile_Cleaver, DT_TFProjectile_Jar);
};
struct DT_TFProjectile_JarMilk : public DT_TFProjectile_Jar
{
	NETVAR_REFLECTION (DT_TFProjectile_JarMilk, DT_TFProjectile_Jar);
};
struct DT_TFWeaponCleaver : public DT_TFWeaponJar
{
	NETVAR_REFLECTION (DT_TFWeaponCleaver, DT_TFWeaponJar);
};
struct DT_TFWeaponJarMilk : public DT_TFWeaponJar
{
	NETVAR_REFLECTION (DT_TFWeaponJarMilk, DT_TFWeaponJar);
};
struct DT_TFWeaponInvis : public DT_TFWeaponBase
{
	NETVAR_REFLECTION (DT_TFWeaponInvis, DT_TFWeaponBase);
};
struct DT_WeaponGrenadeLauncher : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_WeaponGrenadeLauncher, DT_TFWeaponBaseGun);
	inline float &flDetonateTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_WeaponGrenadeLauncher", "m_flDetonateTime");
	}
	inline int &iCurrentTube ()
	{
		NETVAR_RETURN_THIS (int &, "DT_WeaponGrenadeLauncher", "m_iCurrentTube");
	}
	inline int &iGoalTube ()
	{
		NETVAR_RETURN_THIS (int &, "DT_WeaponGrenadeLauncher", "m_iGoalTube");
	}
};
struct DT_TFCannon : public DT_WeaponGrenadeLauncher
{
	NETVAR_REFLECTION (DT_TFCannon, DT_WeaponGrenadeLauncher);
};
struct DT_GrapplingHook : public DT_WeaponRocketLauncher
{
	NETVAR_REFLECTION (DT_GrapplingHook, DT_WeaponRocketLauncher);
	inline EHANDLE &hProjectile ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_GrapplingHook", "m_hProjectile");
	}
};
struct DT_WeaponFlareGun : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_WeaponFlareGun, DT_TFWeaponBaseGun);
	inline float &flChargeBeginTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_WeaponFlareGun", "m_flChargeBeginTime");
	}
};
struct DT_WeaponFlareGun_Revenge : public DT_WeaponFlareGun
{
	NETVAR_REFLECTION (DT_WeaponFlareGun_Revenge, DT_WeaponFlareGun);
	inline int &fLastExtinguishTime ()
	{
		NETVAR_RETURN_THIS (int &, "DT_WeaponFlareGun_Revenge", "m_fLastExtinguishTime");
	}
};
struct DT_TFFlameRocket : public DT_TFBaseRocket
{
	NETVAR_REFLECTION (DT_TFFlameRocket, DT_TFBaseRocket);
};
struct DT_WeaponFlameThrower : public DT_TFWeaponBaseGun
{
	NETVAR_REFLECTION (DT_WeaponFlameThrower, DT_TFWeaponBaseGun);
	struct CLocalFlameThrower
	{
		NETVAR_REFLECTION (CLocalFlameThrower, DT_WeaponFlameThrower);
		inline int &iActiveFlames ()
		{
			NETVAR_RETURN_THIS (int &, "DT_WeaponFlameThrower", "LocalFlameThrowerData", "m_iActiveFlames");
		}
		inline int &iDamagingFlames ()
		{
			NETVAR_RETURN_THIS (int &, "DT_WeaponFlameThrower", "LocalFlameThrowerData", "m_iDamagingFlames");
		}
		inline bool &bHasHalloweenSpell ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_WeaponFlameThrower", "LocalFlameThrowerData", "m_bHasHalloweenSpell");
		}
	};
	inline int &iWeaponState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_WeaponFlameThrower", "m_iWeaponState");
	}
	inline bool &bCritFire ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_WeaponFlameThrower", "m_bCritFire");
	}
	inline bool &bHitTarget ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_WeaponFlameThrower", "m_bHitTarget");
	}
	inline float &flChargeBeginTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_WeaponFlameThrower", "m_flChargeBeginTime");
	}
	inline CLocalFlameThrower &LocalFlameThrowerData ()
	{
		NETVAR_RETURN_THIS (CLocalFlameThrower &, "DT_WeaponFlameThrower", "LocalFlameThrowerData");
	}
};
struct DT_TFWeaponFists : public DT_TFWeaponBaseMelee
{
	NETVAR_REFLECTION (DT_TFWeaponFists, DT_TFWeaponBaseMelee);
};
struct DT_TFWeaponFireAxe : public DT_TFWeaponBaseMelee
{
	NETVAR_REFLECTION (DT_TFWeaponFireAxe, DT_TFWeaponBaseMelee);
};
struct DT_WeaponCompoundBow : public DT_WeaponPipebombLauncher
{
	NETVAR_REFLECTION (DT_WeaponCompoundBow, DT_WeaponPipebombLauncher);
	inline bool &bArrowAlight ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_WeaponCompoundBow", "m_bArrowAlight");
	}
	inline bool &bNoFire ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_WeaponCompoundBow", "m_bNoFire");
	}
};
struct DT_TFWeaponClub : public DT_TFWeaponBaseMelee
{
	NETVAR_REFLECTION (DT_TFWeaponClub, DT_TFWeaponBaseMelee);
};
struct DT_TFWeaponBottle : public DT_TFWeaponBaseMelee
{
	NETVAR_REFLECTION (DT_TFWeaponBottle, DT_TFWeaponBaseMelee);
	inline bool &bBroken ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFWeaponBottle", "m_bBroken");
	}
};
struct DT_TFWeaponStickBomb : public DT_TFWeaponBottle
{
	NETVAR_REFLECTION (DT_TFWeaponStickBomb, DT_TFWeaponBottle);
	inline int &iDetonated ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFWeaponStickBomb", "m_iDetonated");
	}
};
struct DT_TFWeaponBonesaw : public DT_TFWeaponBaseMelee
{
	NETVAR_REFLECTION (DT_TFWeaponBonesaw, DT_TFWeaponBaseMelee);
};
struct DT_TFProjectile_StunBall : public DT_TFProjectile_Pipebomb
{
	NETVAR_REFLECTION (DT_TFProjectile_StunBall, DT_TFProjectile_Pipebomb);
};
struct DT_TFProjectileBall_Ornament : public DT_TFProjectile_StunBall
{
	NETVAR_REFLECTION (DT_TFProjectileBall_Ornament, DT_TFProjectile_StunBall);
};
struct DT_TFWeaponBat : public DT_TFWeaponBaseMelee
{
	NETVAR_REFLECTION (DT_TFWeaponBat, DT_TFWeaponBaseMelee);
};
struct DT_TFWeaponBat_Wood : public DT_TFWeaponBat
{
	NETVAR_REFLECTION (DT_TFWeaponBat_Wood, DT_TFWeaponBat);
};
struct DT_TFWeaponBat_Giftwrap : public DT_TFWeaponBat_Wood
{
	NETVAR_REFLECTION (DT_TFWeaponBat_Giftwrap, DT_TFWeaponBat_Wood);
};
struct DT_TFWeaponBat_Fish : public DT_TFWeaponBat
{
	NETVAR_REFLECTION (DT_TFWeaponBat_Fish, DT_TFWeaponBat);
};
struct DT_TFBaseProjectile : public DT_BaseProjectile
{
	NETVAR_REFLECTION (DT_TFBaseProjectile, DT_BaseProjectile);
	inline Vector &vInitialVelocity ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TFBaseProjectile", "m_vInitialVelocity");
	}
	inline EHANDLE &hLauncher ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFBaseProjectile", "m_hLauncher");
	}
};
struct DT_TFProjectile_EnergyRing : public DT_TFBaseProjectile
{
	NETVAR_REFLECTION (DT_TFProjectile_EnergyRing, DT_TFBaseProjectile);
};
struct DT_TFDroppedWeapon : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_TFDroppedWeapon, DT_BaseAnimating);
	struct CScriptCreatedItem
	{
		NETVAR_REFLECTION (CScriptCreatedItem, DT_TFDroppedWeapon);
		struct CAttributeList
		{
			NETVAR_REFLECTION (CAttributeList, CScriptCreatedItem);
		}; // Fail count = 1
		inline int &iItemDefinitionIndex ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFDroppedWeapon", "m_Item", "m_iItemDefinitionIndex");
		}
		inline int &iEntityLevel ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFDroppedWeapon", "m_Item", "m_iEntityLevel");
		}
		inline int &iItemIDHigh ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFDroppedWeapon", "m_Item", "m_iItemIDHigh");
		}
		inline int &iItemIDLow ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFDroppedWeapon", "m_Item", "m_iItemIDLow");
		}
		inline int &iAccountID ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFDroppedWeapon", "m_Item", "m_iAccountID");
		}
		inline int &iEntityQuality ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFDroppedWeapon", "m_Item", "m_iEntityQuality");
		}
		inline bool &bInitialized ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFDroppedWeapon", "m_Item", "m_bInitialized");
		}
		inline bool &bOnlyIterateItemViewAttributes ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFDroppedWeapon", "m_Item", "m_bOnlyIterateItemViewAttributes");
		}
		inline CAttributeList &AttributeList ()
		{
			NETVAR_RETURN_THIS (CAttributeList &, "DT_TFDroppedWeapon", "m_Item", "m_AttributeList");
		}
		inline int &iTeamNumber ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFDroppedWeapon", "m_Item", "m_iTeamNumber");
		}
		inline CAttributeList &NetworkedDynamicAttributesForDemos ()
		{
			NETVAR_RETURN_THIS (CAttributeList &, "DT_TFDroppedWeapon", "m_Item", "m_NetworkedDynamicAttributesForDemos");
		}
	};
	inline CScriptCreatedItem &Item ()
	{
		NETVAR_RETURN_THIS (CScriptCreatedItem &, "DT_TFDroppedWeapon", "m_Item");
	}
	inline float &flChargeLevel ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFDroppedWeapon", "m_flChargeLevel");
	}
};
struct DT_TFWeaponBuilder : public DT_TFWeaponBase
{
	NETVAR_REFLECTION (DT_TFWeaponBuilder, DT_TFWeaponBase);
	struct CBuilderLocalData
	{
		NETVAR_REFLECTION (CBuilderLocalData, DT_TFWeaponBuilder);
		inline int &iObjectType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFWeaponBuilder", "BuilderLocalData", "m_iObjectType");
		}
		inline EHANDLE &hObjectBeingBuilt ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_TFWeaponBuilder", "BuilderLocalData", "m_hObjectBeingBuilt");
		}
	}; // Fail count = 1
	inline int &iBuildState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFWeaponBuilder", "m_iBuildState");
	}
	inline CBuilderLocalData &BuilderLocalData ()
	{
		NETVAR_RETURN_THIS (CBuilderLocalData &, "DT_TFWeaponBuilder", "BuilderLocalData");
	}
	inline int &iObjectMode ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFWeaponBuilder", "m_iObjectMode");
	}
	inline float &flWheatleyTalkingUntil ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFWeaponBuilder", "m_flWheatleyTalkingUntil");
	}
};
struct DT_TFWeaponSapper : public DT_TFWeaponBuilder
{
	NETVAR_REFLECTION (DT_TFWeaponSapper, DT_TFWeaponBuilder);
	inline float &flChargeBeginTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFWeaponSapper", "m_flChargeBeginTime");
	}
};
struct DT_TFProjectile_Rocket : public DT_TFBaseRocket
{
	NETVAR_REFLECTION (DT_TFProjectile_Rocket, DT_TFBaseRocket);
	inline bool &bCritical ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFProjectile_Rocket", "m_bCritical");
	}
};
struct DT_TFProjectile_Flare : public DT_TFBaseRocket
{
	NETVAR_REFLECTION (DT_TFProjectile_Flare, DT_TFBaseRocket);
	inline bool &bCritical ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFProjectile_Flare", "m_bCritical");
	}
};
struct DT_TFProjectile_EnergyBall : public DT_TFBaseRocket
{
	NETVAR_REFLECTION (DT_TFProjectile_EnergyBall, DT_TFBaseRocket);
	inline bool &bChargedShot ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFProjectile_EnergyBall", "m_bChargedShot");
	}
	inline Vector &vColor1 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TFProjectile_EnergyBall", "m_vColor1");
	}
	inline Vector &vColor2 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TFProjectile_EnergyBall", "m_vColor2");
	}
};
struct DT_TFProjectile_Arrow : public DT_TFBaseRocket
{
	NETVAR_REFLECTION (DT_TFProjectile_Arrow, DT_TFBaseRocket);
	inline bool &bArrowAlight ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFProjectile_Arrow", "m_bArrowAlight");
	}
	inline bool &bCritical ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFProjectile_Arrow", "m_bCritical");
	}
	inline int &iProjectileType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFProjectile_Arrow", "m_iProjectileType");
	}
};
struct DT_TFProjectile_GrapplingHook : public DT_TFProjectile_Arrow
{
	NETVAR_REFLECTION (DT_TFProjectile_GrapplingHook, DT_TFProjectile_Arrow);
};
struct DT_TFProjectile_HealingBolt : public DT_TFProjectile_Arrow
{
	NETVAR_REFLECTION (DT_TFProjectile_HealingBolt, DT_TFProjectile_Arrow);
};
struct DT_MannVsMachineStats : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_MannVsMachineStats, DT_BaseEntity);
	struct CCMannVsMachineWaveStats
	{
		NETVAR_REFLECTION (CCMannVsMachineWaveStats, DT_MannVsMachineStats);
		inline int &nCreditsDropped ()
		{
			NETVAR_RETURN_THIS (int &, "DT_MannVsMachineStats", "m_currentWaveStats", "nCreditsDropped");
		}
		inline int &nCreditsAcquired ()
		{
			NETVAR_RETURN_THIS (int &, "DT_MannVsMachineStats", "m_currentWaveStats", "nCreditsAcquired");
		}
		inline int &nCreditsBonus ()
		{
			NETVAR_RETURN_THIS (int &, "DT_MannVsMachineStats", "m_currentWaveStats", "nCreditsBonus");
		}
		inline int &nPlayerDeaths ()
		{
			NETVAR_RETURN_THIS (int &, "DT_MannVsMachineStats", "m_currentWaveStats", "nPlayerDeaths");
		}
		inline int &nBuyBacks ()
		{
			NETVAR_RETURN_THIS (int &, "DT_MannVsMachineStats", "m_currentWaveStats", "nBuyBacks");
		}
	};
	inline int &iCurrentWaveIdx ()
	{
		NETVAR_RETURN_THIS (int &, "DT_MannVsMachineStats", "m_iCurrentWaveIdx");
	}
	inline int &iServerWaveID ()
	{
		NETVAR_RETURN_THIS (int &, "DT_MannVsMachineStats", "m_iServerWaveID");
	}
	inline CCMannVsMachineWaveStats &runningTotalWaveStats ()
	{
		NETVAR_RETURN_THIS (CCMannVsMachineWaveStats &, "DT_MannVsMachineStats", "m_runningTotalWaveStats");
	}
	inline CCMannVsMachineWaveStats &previousWaveStats ()
	{
		NETVAR_RETURN_THIS (CCMannVsMachineWaveStats &, "DT_MannVsMachineStats", "m_previousWaveStats");
	}
	inline CCMannVsMachineWaveStats &currentWaveStats ()
	{
		NETVAR_RETURN_THIS (CCMannVsMachineWaveStats &, "DT_MannVsMachineStats", "m_currentWaveStats");
	}
	inline int &iCurrencyCollectedForRespec ()
	{
		NETVAR_RETURN_THIS (int &, "DT_MannVsMachineStats", "m_iCurrencyCollectedForRespec");
	}
	inline int &nRespecsAwardedInWave ()
	{
		NETVAR_RETURN_THIS (int &, "DT_MannVsMachineStats", "m_nRespecsAwardedInWave");
	}
};
struct DT_BaseAnimatingOverlay : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_BaseAnimatingOverlay, DT_BaseAnimating);
	struct COverlayVars
	{
		NETVAR_REFLECTION (COverlayVars, DT_BaseAnimatingOverlay);
	}; // Fail count = 1
	inline COverlayVars &overlay_vars ()
	{
		NETVAR_RETURN_THIS (COverlayVars &, "DT_BaseAnimatingOverlay", "overlay_vars");
	}
};
struct DT_BaseFlex : public DT_BaseAnimatingOverlay
{
	NETVAR_REFLECTION (DT_BaseFlex, DT_BaseAnimatingOverlay);
	inline float *flexWeight ()
	{
		NETVAR_RETURN_ARRAY_THIS (float *, "DT_BaseFlex", "m_flexWeight");
	} // Array size = 96
	inline bool &blinktoggle ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseFlex", "m_blinktoggle");
	}
	inline Vector &viewtarget ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_BaseFlex", "m_viewtarget");
	}
};
struct DT_BaseCombatCharacter : public DT_BaseFlex
{
	NETVAR_REFLECTION (DT_BaseCombatCharacter, DT_BaseFlex);
	struct CBCCLocalPlayerExclusive
	{
		NETVAR_REFLECTION (CBCCLocalPlayerExclusive, DT_BaseCombatCharacter);
		inline float &flNextAttack ()
		{
			NETVAR_RETURN_THIS (float &, "DT_BaseCombatCharacter", "bcc_localdata", "m_flNextAttack");
		}
	};
	inline CBCCLocalPlayerExclusive &bcc_localdata ()
	{
		NETVAR_RETURN_THIS (CBCCLocalPlayerExclusive &, "DT_BaseCombatCharacter", "bcc_localdata");
	}
	inline EHANDLE &hActiveWeapon ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BaseCombatCharacter", "m_hActiveWeapon");
	}
	inline EHANDLE *hMyWeapons ()
	{
		NETVAR_RETURN_ARRAY_THIS (EHANDLE *, "DT_BaseCombatCharacter", "m_hMyWeapons");
	} // Array size = 48
	inline bool &bGlowEnabled ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseCombatCharacter", "m_bGlowEnabled");
	}
};
struct DT_NextBot : public DT_BaseCombatCharacter
{
	NETVAR_REFLECTION (DT_NextBot, DT_BaseCombatCharacter);
};
struct DT_TFBaseBoss : public DT_NextBot
{
	NETVAR_REFLECTION (DT_TFBaseBoss, DT_NextBot);
	inline float &lastHealthPercentage ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFBaseBoss", "m_lastHealthPercentage");
	}
};
struct DT_TFTankBoss : public DT_TFBaseBoss
{
	NETVAR_REFLECTION (DT_TFTankBoss, DT_TFBaseBoss);
};
struct DT_BossAlpha : public DT_NextBot
{
	NETVAR_REFLECTION (DT_BossAlpha, DT_NextBot);
	inline int &isNuking ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BossAlpha", "m_isNuking");
	}
};
struct DT_TFProjectile_SpellBats : public DT_TFProjectile_Jar
{
	NETVAR_REFLECTION (DT_TFProjectile_SpellBats, DT_TFProjectile_Jar);
};
struct DT_TFProjectile_SpellKartBats : public DT_TFProjectile_SpellBats
{
	NETVAR_REFLECTION (DT_TFProjectile_SpellKartBats, DT_TFProjectile_SpellBats);
};
struct DT_TFProjectile_SpellFireball : public DT_TFProjectile_Rocket
{
	NETVAR_REFLECTION (DT_TFProjectile_SpellFireball, DT_TFProjectile_Rocket);
};
struct DT_TFProjectile_SpellKartOrb : public DT_TFProjectile_SpellFireball
{
	NETVAR_REFLECTION (DT_TFProjectile_SpellKartOrb, DT_TFProjectile_SpellFireball);
};
struct DT_TFHellZap : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_TFHellZap, DT_BaseEntity);
};
struct DT_TFProjectile_SpellLightningOrb : public DT_TFProjectile_SpellFireball
{
	NETVAR_REFLECTION (DT_TFProjectile_SpellLightningOrb, DT_TFProjectile_SpellFireball);
};
struct SpellTransposeTeleport : public DT_TFProjectile_SpellBats
{
	NETVAR_REFLECTION (SpellTransposeTeleport, DT_TFProjectile_SpellBats);
};
struct DT_TFProjectile_SpellMeteorShower : public DT_TFProjectile_SpellBats
{
	NETVAR_REFLECTION (DT_TFProjectile_SpellMeteorShower, DT_TFProjectile_SpellBats);
};
struct DT_TFProjectile_SpellSpawnBoss : public DT_TFProjectile_SpellBats
{
	NETVAR_REFLECTION (DT_TFProjectile_SpellSpawnBoss, DT_TFProjectile_SpellBats);
};
struct DT_TFProjectile_SpellMirv : public DT_TFProjectile_SpellBats
{
	NETVAR_REFLECTION (DT_TFProjectile_SpellMirv, DT_TFProjectile_SpellBats);
};
struct DT_TFProjectile_SpellPumpkin : public DT_TFProjectile_SpellBats
{
	NETVAR_REFLECTION (DT_TFProjectile_SpellPumpkin, DT_TFProjectile_SpellBats);
};
struct DT_TFProjectile_SpellSpawnHorde : public DT_TFProjectile_SpellBats
{
	NETVAR_REFLECTION (DT_TFProjectile_SpellSpawnHorde, DT_TFProjectile_SpellBats);
};
struct DT_TFProjectile_SpellSpawnZombie : public DT_TFProjectile_SpellBats
{
	NETVAR_REFLECTION (DT_TFProjectile_SpellSpawnZombie, DT_TFProjectile_SpellBats);
};
struct DT_TFWeaponSpellBook : public DT_TFWeaponThrowable
{
	NETVAR_REFLECTION (DT_TFWeaponSpellBook, DT_TFWeaponThrowable);
	inline int &iSelectedSpellIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFWeaponSpellBook", "m_iSelectedSpellIndex");
	}
	inline int &iSpellCharges ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFWeaponSpellBook", "m_iSpellCharges");
	}
	inline float &flTimeNextSpell ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFWeaponSpellBook", "m_flTimeNextSpell");
	}
	inline bool &bFiredAttack ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFWeaponSpellBook", "m_bFiredAttack");
	}
};
struct DT_TeleportVortex : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_TeleportVortex, DT_BaseAnimating);
	inline int &iState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TeleportVortex", "m_iState");
	}
};
struct DT_Hightower_TeleportVortex : public DT_TeleportVortex
{
	NETVAR_REFLECTION (DT_Hightower_TeleportVortex, DT_TeleportVortex);
	inline int &iState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Hightower_TeleportVortex", "m_iState");
	}
};
struct DT_Zombie : public DT_NextBot
{
	NETVAR_REFLECTION (DT_Zombie, DT_NextBot);
	inline float &flHeadScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Zombie", "m_flHeadScale");
	}
};
struct DT_MerasmusDancer : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_MerasmusDancer, DT_BaseAnimating);
};
struct DT_Merasmus : public DT_NextBot
{
	NETVAR_REFLECTION (DT_Merasmus, DT_NextBot);
	inline bool &bRevealed ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_Merasmus", "m_bRevealed");
	}
	inline bool &bIsDoingAOEAttack ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_Merasmus", "m_bIsDoingAOEAttack");
	}
	inline bool &bStunned ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_Merasmus", "m_bStunned");
	}
};
struct DT_HeadlessHatman : public DT_NextBot
{
	NETVAR_REFLECTION (DT_HeadlessHatman, DT_NextBot);
};
struct DT_EyeballBoss : public DT_NextBot
{
	NETVAR_REFLECTION (DT_EyeballBoss, DT_NextBot);
	inline Vector &lookAtSpot ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_EyeballBoss", "m_lookAtSpot");
	}
	inline int &attitude ()
	{
		NETVAR_RETURN_THIS (int &, "DT_EyeballBoss", "m_attitude");
	}
};
struct DT_TFBotHintEngineerNest : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_TFBotHintEngineerNest, DT_BaseEntity);
	inline bool &bHasActiveTeleporter ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFBotHintEngineerNest", "m_bHasActiveTeleporter");
	}
};
struct DT_BotNPCMinion : public DT_NextBot
{
	NETVAR_REFLECTION (DT_BotNPCMinion, DT_NextBot);
	inline int &stunTarget ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BotNPCMinion", "m_stunTarget");
	}
};
struct DT_BotNPC : public DT_NextBot
{
	NETVAR_REFLECTION (DT_BotNPC, DT_NextBot);
	inline int &laserTarget ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BotNPC", "m_laserTarget");
	}
	inline int &isNuking ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BotNPC", "m_isNuking");
	}
};
struct DT_PasstimeGun : public DT_TFWeaponBase
{
	NETVAR_REFLECTION (DT_PasstimeGun, DT_TFWeaponBase);
	inline int &eThrowState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PasstimeGun", "m_eThrowState");
	}
	inline int &fChargeBeginTime ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PasstimeGun", "m_fChargeBeginTime");
	}
};
struct DT_BaseViewModel
{
	NETVAR_REFLECTION_NOBASE (DT_BaseViewModel);
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseViewModel", "m_nModelIndex");
	}
	inline int &nSkin ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseViewModel", "m_nSkin");
	}
	inline int &nBody ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseViewModel", "m_nBody");
	}
	inline int &nSequence ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseViewModel", "m_nSequence");
	}
	inline int &nViewModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseViewModel", "m_nViewModelIndex");
	}
	inline float &flPlaybackRate ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseViewModel", "m_flPlaybackRate");
	}
	inline int &fEffects ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseViewModel", "m_fEffects");
	}
	inline int &nAnimationParity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseViewModel", "m_nAnimationParity");
	}
	inline EHANDLE &hWeapon ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BaseViewModel", "m_hWeapon");
	}
	inline EHANDLE &hOwner ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BaseViewModel", "m_hOwner");
	}
	inline int &nNewSequenceParity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseViewModel", "m_nNewSequenceParity");
	}
	inline int &nResetEventsParity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseViewModel", "m_nResetEventsParity");
	}
	inline int &nMuzzleFlashParity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseViewModel", "m_nMuzzleFlashParity");
	}
	inline float &flPoseParameter0 ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseViewModel", "m_flPoseParameter[0]");
	}
	inline float *flPoseParameter ()
	{
		NETVAR_RETURN_ARRAY_THIS (float *, "DT_BaseViewModel", "m_flPoseParameter");
	} // Array size = 24
};
struct DT_TFViewModel : public DT_BaseViewModel
{
	NETVAR_REFLECTION (DT_TFViewModel, DT_BaseViewModel);
};
struct DT_BaseObject : public DT_BaseCombatCharacter
{
	NETVAR_REFLECTION (DT_BaseObject, DT_BaseCombatCharacter);
	inline int &iHealth ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseObject", "m_iHealth");
	}
	inline int &iMaxHealth ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseObject", "m_iMaxHealth");
	}
	inline bool &bHasSapper ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseObject", "m_bHasSapper");
	}
	inline int &iObjectType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseObject", "m_iObjectType");
	}
	inline bool &bBuilding ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseObject", "m_bBuilding");
	}
	inline bool &bPlacing ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseObject", "m_bPlacing");
	}
	inline bool &bCarried ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseObject", "m_bCarried");
	}
	inline bool &bCarryDeploy ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseObject", "m_bCarryDeploy");
	}
	inline bool &bMiniBuilding ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseObject", "m_bMiniBuilding");
	}
	inline float &flPercentageConstructed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseObject", "m_flPercentageConstructed");
	}
	inline int &fObjectFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseObject", "m_fObjectFlags");
	}
	inline EHANDLE &hBuiltOnEntity ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BaseObject", "m_hBuiltOnEntity");
	}
	inline bool &bDisabled ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseObject", "m_bDisabled");
	}
	inline EHANDLE &hBuilder ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BaseObject", "m_hBuilder");
	}
	inline Vector &vecBuildMaxs ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_BaseObject", "m_vecBuildMaxs");
	}
	inline Vector &vecBuildMins ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_BaseObject", "m_vecBuildMins");
	}
	inline int &iDesiredBuildRotations ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseObject", "m_iDesiredBuildRotations");
	}
	inline bool &bServerOverridePlacement ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseObject", "m_bServerOverridePlacement");
	}
	inline int &iUpgradeLevel ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseObject", "m_iUpgradeLevel");
	}
	inline int &iUpgradeMetal ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseObject", "m_iUpgradeMetal");
	}
	inline int &iUpgradeMetalRequired ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseObject", "m_iUpgradeMetalRequired");
	}
	inline int &iHighestUpgradeLevel ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseObject", "m_iHighestUpgradeLevel");
	}
	inline int &iObjectMode ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseObject", "m_iObjectMode");
	}
	inline bool &bDisposableBuilding ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseObject", "m_bDisposableBuilding");
	}
	inline bool &bWasMapPlaced ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseObject", "m_bWasMapPlaced");
	}
	inline bool &bPlasmaDisable ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseObject", "m_bPlasmaDisable");
	}
};
struct DT_ObjectDispenser : public DT_BaseObject
{
	NETVAR_REFLECTION (DT_ObjectDispenser, DT_BaseObject);
	inline int &iState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ObjectDispenser", "m_iState");
	}
	inline int &iAmmoMetal ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ObjectDispenser", "m_iAmmoMetal");
	}
	inline int &iMiniBombCounter ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ObjectDispenser", "m_iMiniBombCounter");
	}
}; // Fail count = 2
struct DT_RobotDispenser : public DT_ObjectDispenser
{
	NETVAR_REFLECTION (DT_RobotDispenser, DT_ObjectDispenser);
};
struct DT_TFRobotDestruction_Robot : public DT_BaseCombatCharacter
{
	NETVAR_REFLECTION (DT_TFRobotDestruction_Robot, DT_BaseCombatCharacter);
	inline int &iHealth ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRobotDestruction_Robot", "m_iHealth");
	}
	inline int &iMaxHealth ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRobotDestruction_Robot", "m_iMaxHealth");
	}
	inline int &eType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRobotDestruction_Robot", "m_eType");
	}
};
struct DT_TFReviveMarker : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_TFReviveMarker, DT_BaseAnimating);
	inline EHANDLE &hOwner ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFReviveMarker", "m_hOwner");
	}
	inline int &iHealth ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFReviveMarker", "m_iHealth");
	}
	inline int &iMaxHealth ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFReviveMarker", "m_iMaxHealth");
	}
	inline int &nRevives ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFReviveMarker", "m_nRevives");
	}
};
struct DT_TFPumpkinBomb : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_TFPumpkinBomb, DT_BaseAnimating);
};
struct DT_BaseObjectUpgrade : public DT_BaseObject
{
	NETVAR_REFLECTION (DT_BaseObjectUpgrade, DT_BaseObject);
};
struct DT_TFRobotDestructionLogic
{
	NETVAR_REFLECTION_NOBASE (DT_TFRobotDestructionLogic);
	inline int &nMaxPoints ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRobotDestructionLogic", "m_nMaxPoints");
	}
	inline int &nBlueScore ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRobotDestructionLogic", "m_nBlueScore");
	}
	inline int &nRedScore ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRobotDestructionLogic", "m_nRedScore");
	}
	inline int &nBlueTargetPoints ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRobotDestructionLogic", "m_nBlueTargetPoints");
	}
	inline int &nRedTargetPoints ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRobotDestructionLogic", "m_nRedTargetPoints");
	}
	inline float &flBlueTeamRespawnScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFRobotDestructionLogic", "m_flBlueTeamRespawnScale");
	}
	inline float &flRedTeamRespawnScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFRobotDestructionLogic", "m_flRedTeamRespawnScale");
	}
	inline float &flBlueFinaleEndTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFRobotDestructionLogic", "m_flBlueFinaleEndTime");
	}
	inline float &flRedFinaleEndTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFRobotDestructionLogic", "m_flRedFinaleEndTime");
	}
	inline float &flFinaleLength ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFRobotDestructionLogic", "m_flFinaleLength");
	}
	inline char *&szResFile ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_TFRobotDestructionLogic", "m_szResFile");
	}
	inline float &flCountdownEndTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFRobotDestructionLogic", "m_flCountdownEndTime");
	}
}; // Fail count = 1
struct DT_TFRobotDestruction_RobotGroup
{
	NETVAR_REFLECTION_NOBASE (DT_TFRobotDestruction_RobotGroup);
	inline char *&pszHudIcon ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_TFRobotDestruction_RobotGroup", "m_pszHudIcon");
	}
	inline int &iTeamNum ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRobotDestruction_RobotGroup", "m_iTeamNum");
	}
	inline int &nGroupNumber ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRobotDestruction_RobotGroup", "m_nGroupNumber");
	}
	inline int &nState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRobotDestruction_RobotGroup", "m_nState");
	}
	inline float &flRespawnStartTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFRobotDestruction_RobotGroup", "m_flRespawnStartTime");
	}
	inline float &flRespawnEndTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFRobotDestruction_RobotGroup", "m_flRespawnEndTime");
	}
	inline float &flLastAttackedTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFRobotDestruction_RobotGroup", "m_flLastAttackedTime");
	}
};
struct DT_TFRobotDestructionRobotSpawn
{
	NETVAR_REFLECTION_NOBASE (DT_TFRobotDestructionRobotSpawn);
};
struct DT_TFPlayerDestructionLogic : public DT_TFRobotDestructionLogic
{
	NETVAR_REFLECTION (DT_TFPlayerDestructionLogic, DT_TFRobotDestructionLogic);
	inline EHANDLE &hRedTeamLeader ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayerDestructionLogic", "m_hRedTeamLeader");
	}
	inline EHANDLE &hBlueTeamLeader ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayerDestructionLogic", "m_hBlueTeamLeader");
	}
	inline int &iszCountdownImage ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayerDestructionLogic", "m_iszCountdownImage");
	}
	inline bool &bUsingCountdownImage ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPlayerDestructionLogic", "m_bUsingCountdownImage");
	}
};
struct DT_PlayerDestructionDispenser : public DT_ObjectDispenser
{
	NETVAR_REFLECTION (DT_PlayerDestructionDispenser, DT_ObjectDispenser);
};
struct DT_TFMinigameLogic
{
	NETVAR_REFLECTION_NOBASE (DT_TFMinigameLogic);
	inline EHANDLE &hActiveMinigame ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFMinigameLogic", "m_hActiveMinigame");
	}
};
struct DT_TFMinigame
{
	NETVAR_REFLECTION_NOBASE (DT_TFMinigame);
	inline int *nMinigameTeamScore ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFMinigame", "m_nMinigameTeamScore");
	} // Array size = 4
	inline int &nMaxScoreForMiniGame ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFMinigame", "m_nMaxScoreForMiniGame");
	}
	inline char *&pszHudResFile ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_TFMinigame", "m_pszHudResFile");
	}
	inline int &eScoringType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFMinigame", "m_eScoringType");
	}
};
struct DT_TFHalloweenMinigame : public DT_TFMinigame
{
	NETVAR_REFLECTION (DT_TFHalloweenMinigame, DT_TFMinigame);
};
struct DT_TFHalloweenMinigame_FallingPlatforms : public DT_TFHalloweenMinigame
{
	NETVAR_REFLECTION (DT_TFHalloweenMinigame_FallingPlatforms, DT_TFHalloweenMinigame);
};
struct DT_TFPowerupBottle : public DT_TFWearable
{
	NETVAR_REFLECTION (DT_TFPowerupBottle, DT_TFWearable);
	inline bool &bActive ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPowerupBottle", "m_bActive");
	}
	inline int &usNumCharges ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPowerupBottle", "m_usNumCharges");
	}
};
struct DT_BreakableProp : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_BreakableProp, DT_BaseAnimating);
};
struct DT_DynamicProp : public DT_BreakableProp
{
	NETVAR_REFLECTION (DT_DynamicProp, DT_BreakableProp);
	inline bool &bUseHitboxesForRenderBox ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_DynamicProp", "m_bUseHitboxesForRenderBox");
	}
};
struct DT_TFItem : public DT_DynamicProp
{
	NETVAR_REFLECTION (DT_TFItem, DT_DynamicProp);
};
struct DT_HalloweenSoulPack : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_HalloweenSoulPack, DT_BaseEntity);
	inline EHANDLE &hTarget ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_HalloweenSoulPack", "m_hTarget");
	}
	inline Vector &vecPreCurvePos ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_HalloweenSoulPack", "m_vecPreCurvePos");
	}
	inline Vector &vecStartCurvePos ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_HalloweenSoulPack", "m_vecStartCurvePos");
	}
	inline float &flDuration ()
	{
		NETVAR_RETURN_THIS (float &, "DT_HalloweenSoulPack", "m_flDuration");
	}
};
struct DT_TFGenericBomb : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_TFGenericBomb, DT_BaseAnimating);
};
struct DT_BonusRoundLogic
{
	NETVAR_REFLECTION_NOBASE (DT_BonusRoundLogic);
	struct CScriptCreatedItem
	{
		NETVAR_REFLECTION (CScriptCreatedItem, DT_BonusRoundLogic);
		struct CAttributeList
		{
			NETVAR_REFLECTION (CAttributeList, CScriptCreatedItem);
		}; // Fail count = 1
		inline int &iItemDefinitionIndex ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BonusRoundLogic", "m_Item", "m_iItemDefinitionIndex");
		}
		inline int &iEntityLevel ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BonusRoundLogic", "m_Item", "m_iEntityLevel");
		}
		inline int &iItemIDHigh ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BonusRoundLogic", "m_Item", "m_iItemIDHigh");
		}
		inline int &iItemIDLow ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BonusRoundLogic", "m_Item", "m_iItemIDLow");
		}
		inline int &iAccountID ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BonusRoundLogic", "m_Item", "m_iAccountID");
		}
		inline int &iEntityQuality ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BonusRoundLogic", "m_Item", "m_iEntityQuality");
		}
		inline bool &bInitialized ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_BonusRoundLogic", "m_Item", "m_bInitialized");
		}
		inline bool &bOnlyIterateItemViewAttributes ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_BonusRoundLogic", "m_Item", "m_bOnlyIterateItemViewAttributes");
		}
		inline CAttributeList &AttributeList ()
		{
			NETVAR_RETURN_THIS (CAttributeList &, "DT_BonusRoundLogic", "m_Item", "m_AttributeList");
		}
		inline int &iTeamNumber ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BonusRoundLogic", "m_Item", "m_iTeamNumber");
		}
		inline CAttributeList &NetworkedDynamicAttributesForDemos ()
		{
			NETVAR_RETURN_THIS (CAttributeList &, "DT_BonusRoundLogic", "m_Item", "m_NetworkedDynamicAttributesForDemos");
		}
	};
	inline EHANDLE &hBonusWinner ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BonusRoundLogic", "m_hBonusWinner");
	}
	inline CScriptCreatedItem &Item ()
	{
		NETVAR_RETURN_THIS (CScriptCreatedItem &, "DT_BonusRoundLogic", "m_Item");
	}
}; // Fail count = 1
struct DT_GameRulesProxy
{
	NETVAR_REFLECTION_NOBASE (DT_GameRulesProxy);
};
struct DT_TeamplayRoundBasedRulesProxy : public DT_GameRulesProxy
{
	NETVAR_REFLECTION (DT_TeamplayRoundBasedRulesProxy, DT_GameRulesProxy);
	struct CTeamplayRoundBasedRules
	{
		NETVAR_REFLECTION (CTeamplayRoundBasedRules, DT_TeamplayRoundBasedRulesProxy);
		inline int &iRoundState ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_iRoundState");
		}
		inline bool &bInWaitingForPlayers ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_bInWaitingForPlayers");
		}
		inline int &iWinningTeam ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_iWinningTeam");
		}
		inline bool &bInOvertime ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_bInOvertime");
		}
		inline bool &bInSetup ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_bInSetup");
		}
		inline bool &bSwitchedTeamsThisRound ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_bSwitchedTeamsThisRound");
		}
		inline bool &bAwaitingReadyRestart ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_bAwaitingReadyRestart");
		}
		inline float &flRestartRoundTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_flRestartRoundTime");
		}
		inline float &flMapResetTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_flMapResetTime");
		}
		inline int &nRoundsPlayed ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_nRoundsPlayed");
		}
		inline float *flNextRespawnWave ()
		{
			NETVAR_RETURN_ARRAY_THIS (float *, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_flNextRespawnWave");
		} // Array size = 32
		inline bool *bTeamReady ()
		{
			NETVAR_RETURN_ARRAY_THIS (bool *, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_bTeamReady");
		} // Array size = 32
		inline bool &bStopWatch ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_bStopWatch");
		}
		inline bool &bMultipleTrains ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_bMultipleTrains");
		}
		inline bool *bPlayerReady ()
		{
			NETVAR_RETURN_ARRAY_THIS (bool *, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_bPlayerReady");
		} // Array size = 33
		inline bool &bCheatsEnabledDuringLevel ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_bCheatsEnabledDuringLevel");
		}
		inline float &flCountdownTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_flCountdownTime");
		}
		inline float &flStateTransitionTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data", "m_flStateTransitionTime");
		}
	}; // Fail count = 1
	inline CTeamplayRoundBasedRules &teamplayroundbased_gamerules_data ()
	{
		NETVAR_RETURN_THIS (CTeamplayRoundBasedRules &, "DT_TeamplayRoundBasedRulesProxy", "teamplayroundbased_gamerules_data");
	}
};
struct DT_TFGameRulesProxy : public DT_TeamplayRoundBasedRulesProxy
{
	NETVAR_REFLECTION (DT_TFGameRulesProxy, DT_TeamplayRoundBasedRulesProxy);
	struct CTFGameRules
	{
		NETVAR_REFLECTION (CTFGameRules, DT_TFGameRulesProxy);
		inline int &nGameType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_nGameType");
		}
		inline int &nStopWatchState ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_nStopWatchState");
		}
		inline char *&pszTeamGoalStringRed ()
		{
			NETVAR_RETURN_THIS (char *&, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_pszTeamGoalStringRed");
		}
		inline char *&pszTeamGoalStringBlue ()
		{
			NETVAR_RETURN_THIS (char *&, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_pszTeamGoalStringBlue");
		}
		inline float &flCapturePointEnableTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_flCapturePointEnableTime");
		}
		inline int &nHudType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_nHudType");
		}
		inline bool &bIsInTraining ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bIsInTraining");
		}
		inline bool &bAllowTrainingAchievements ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bAllowTrainingAchievements");
		}
		inline bool &bIsWaitingForTrainingContinue ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bIsWaitingForTrainingContinue");
		}
		inline bool &bIsTrainingHUDVisible ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bIsTrainingHUDVisible");
		}
		inline bool &bIsInItemTestingMode ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bIsInItemTestingMode");
		}
		inline EHANDLE &hBonusLogic ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_hBonusLogic");
		}
		inline bool &bPlayingKoth ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bPlayingKoth");
		}
		inline bool &bPlayingMedieval ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bPlayingMedieval");
		}
		inline bool &bPlayingHybrid_CTF_CP ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bPlayingHybrid_CTF_CP");
		}
		inline bool &bPlayingSpecialDeliveryMode ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bPlayingSpecialDeliveryMode");
		}
		inline bool &bPlayingRobotDestructionMode ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bPlayingRobotDestructionMode");
		}
		inline EHANDLE &hRedKothTimer ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_hRedKothTimer");
		}
		inline EHANDLE &hBlueKothTimer ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_hBlueKothTimer");
		}
		inline int &nMapHolidayType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_nMapHolidayType");
		}
		inline int &itHandle ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_itHandle");
		}
		inline bool &bPlayingMannVsMachine ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bPlayingMannVsMachine");
		}
		inline EHANDLE &hBirthdayPlayer ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_hBirthdayPlayer");
		}
		inline int &nBossHealth ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_nBossHealth");
		}
		inline int &nMaxBossHealth ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_nMaxBossHealth");
		}
		inline int &fBossNormalizedTravelDistance ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_fBossNormalizedTravelDistance");
		}
		inline bool &bMannVsMachineAlarmStatus ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bMannVsMachineAlarmStatus");
		}
		inline bool &bHaveMinPlayersToEnableReady ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bHaveMinPlayersToEnableReady");
		}
		inline bool &bBountyModeEnabled ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bBountyModeEnabled");
		}
		inline int &nHalloweenEffect ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_nHalloweenEffect");
		}
		inline int &fHalloweenEffectStartTime ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_fHalloweenEffectStartTime");
		}
		inline int &fHalloweenEffectDuration ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_fHalloweenEffectDuration");
		}
		inline EHANDLE &halloweenScenario ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_halloweenScenario");
		}
		inline bool &bHelltowerPlayersInHell ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bHelltowerPlayersInHell");
		}
		inline bool &bIsUsingSpells ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bIsUsingSpells");
		}
		inline bool &bCompetitiveMode ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bCompetitiveMode");
		}
		inline int &nMatchGroupType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_nMatchGroupType");
		}
		inline bool &bMatchEnded ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bMatchEnded");
		}
		inline bool &bPowerupMode ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bPowerupMode");
		}
		inline char *&pszCustomUpgradesFile ()
		{
			NETVAR_RETURN_THIS (char *&, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_pszCustomUpgradesFile");
		}
		inline bool &bTruceActive ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bTruceActive");
		}
		inline bool &bShowMatchSummary ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bShowMatchSummary");
		}
		inline bool &bTeamsSwitched ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bTeamsSwitched");
		}
		inline bool &bMapHasMatchSummaryStage ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bMapHasMatchSummaryStage");
		}
		inline bool &bPlayersAreOnMatchSummaryStage ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bPlayersAreOnMatchSummaryStage");
		}
		inline bool &bStopWatchWinner ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_bStopWatchWinner");
		}
		inline int &eRematchState ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_eRematchState");
		}
		inline int *nNextMapVoteOptions ()
		{
			NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFGameRulesProxy", "tf_gamerules_data", "m_nNextMapVoteOptions");
		} // Array size = 3
	};    // Fail count = 2
	inline CTFGameRules &tf_gamerules_data ()
	{
		NETVAR_RETURN_THIS (CTFGameRules &, "DT_TFGameRulesProxy", "tf_gamerules_data");
	}
};
struct DT_BaseTempEntity
{
	NETVAR_REFLECTION_NOBASE (DT_BaseTempEntity);
};
struct DT_TETFParticleEffect : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TETFParticleEffect, DT_BaseTempEntity);
	inline Vector &vecOrigin0 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFParticleEffect", "m_vecOrigin[0]");
	}
	inline Vector &vecOrigin1 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFParticleEffect", "m_vecOrigin[1]");
	}
	inline Vector &vecOrigin2 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFParticleEffect", "m_vecOrigin[2]");
	}
	inline Vector &vecStart0 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFParticleEffect", "m_vecStart[0]");
	}
	inline Vector &vecStart1 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFParticleEffect", "m_vecStart[1]");
	}
	inline Vector &vecStart2 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFParticleEffect", "m_vecStart[2]");
	}
	inline Vector &vecAngles ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFParticleEffect", "m_vecAngles");
	}
	inline int &iParticleSystemIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TETFParticleEffect", "m_iParticleSystemIndex");
	}
	inline int &entindex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TETFParticleEffect", "entindex");
	}
	inline int &iAttachType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TETFParticleEffect", "m_iAttachType");
	}
	inline int &iAttachmentPointIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TETFParticleEffect", "m_iAttachmentPointIndex");
	}
	inline bool &bResetParticles ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TETFParticleEffect", "m_bResetParticles");
	}
	inline bool &bCustomColors ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TETFParticleEffect", "m_bCustomColors");
	}
	inline Vector &CustomColors_m_vecColor1 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFParticleEffect", "m_CustomColors.m_vecColor1");
	}
	inline Vector &CustomColors_m_vecColor2 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFParticleEffect", "m_CustomColors.m_vecColor2");
	}
	inline bool &bControlPoint1 ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TETFParticleEffect", "m_bControlPoint1");
	}
	inline int &ControlPoint1_m_eParticleAttachment ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TETFParticleEffect", "m_ControlPoint1.m_eParticleAttachment");
	}
	inline float &ControlPoint1_m_vecOffset0 ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TETFParticleEffect", "m_ControlPoint1.m_vecOffset[0]");
	}
	inline float &ControlPoint1_m_vecOffset1 ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TETFParticleEffect", "m_ControlPoint1.m_vecOffset[1]");
	}
	inline float &ControlPoint1_m_vecOffset2 ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TETFParticleEffect", "m_ControlPoint1.m_vecOffset[2]");
	}
};
struct DT_TETFExplosion : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TETFExplosion, DT_BaseTempEntity);
	inline Vector &vecOrigin0 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFExplosion", "m_vecOrigin[0]");
	}
	inline Vector &vecOrigin1 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFExplosion", "m_vecOrigin[1]");
	}
	inline Vector &vecOrigin2 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFExplosion", "m_vecOrigin[2]");
	}
	inline Vector &vecNormal ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFExplosion", "m_vecNormal");
	}
	inline int &iWeaponID ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TETFExplosion", "m_iWeaponID");
	}
	inline int &entindex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TETFExplosion", "entindex");
	}
	inline int &nDefID ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TETFExplosion", "m_nDefID");
	}
	inline int &nSound ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TETFExplosion", "m_nSound");
	}
	inline int &iCustomParticleIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TETFExplosion", "m_iCustomParticleIndex");
	}
};
struct DT_TETFBlood : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TETFBlood, DT_BaseTempEntity);
	inline Vector &vecOrigin0 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFBlood", "m_vecOrigin[0]");
	}
	inline Vector &vecOrigin1 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFBlood", "m_vecOrigin[1]");
	}
	inline Vector &vecOrigin2 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFBlood", "m_vecOrigin[2]");
	}
	inline Vector &vecNormal ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TETFBlood", "m_vecNormal");
	}
	inline int &entindex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TETFBlood", "entindex");
	}
};
struct DT_CHalloweenPickup : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_CHalloweenPickup, DT_BaseAnimating);
};
struct DT_CHalloweenGiftPickup : public DT_CHalloweenPickup
{
	NETVAR_REFLECTION (DT_CHalloweenGiftPickup, DT_CHalloweenPickup);
	inline EHANDLE &hTargetPlayer ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_CHalloweenGiftPickup", "m_hTargetPlayer");
	}
};
struct DT_CBonusDuckPickup : public DT_CHalloweenPickup
{
	NETVAR_REFLECTION (DT_CBonusDuckPickup, DT_CHalloweenPickup);
	inline bool &bSpecial ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_CBonusDuckPickup", "m_bSpecial");
	}
};
struct DT_CaptureFlagReturnIcon : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_CaptureFlagReturnIcon, DT_BaseEntity);
};
struct DT_CaptureFlag : public DT_TFItem
{
	NETVAR_REFLECTION (DT_CaptureFlag, DT_TFItem);
	inline bool &bDisabled ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_CaptureFlag", "m_bDisabled");
	}
	inline bool &bVisibleWhenDisabled ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_CaptureFlag", "m_bVisibleWhenDisabled");
	}
	inline int &nType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_CaptureFlag", "m_nType");
	}
	inline int &nFlagStatus ()
	{
		NETVAR_RETURN_THIS (int &, "DT_CaptureFlag", "m_nFlagStatus");
	}
	inline float &flResetTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_CaptureFlag", "m_flResetTime");
	}
	inline float &flNeutralTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_CaptureFlag", "m_flNeutralTime");
	}
	inline float &flMaxResetTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_CaptureFlag", "m_flMaxResetTime");
	}
	inline EHANDLE &hPrevOwner ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_CaptureFlag", "m_hPrevOwner");
	}
	inline char *&szModel ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_CaptureFlag", "m_szModel");
	}
	inline char *&szHudIcon ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_CaptureFlag", "m_szHudIcon");
	}
	inline char *&szPaperEffect ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_CaptureFlag", "m_szPaperEffect");
	}
	inline char *&szTrailEffect ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_CaptureFlag", "m_szTrailEffect");
	}
	inline int &nUseTrailEffect ()
	{
		NETVAR_RETURN_THIS (int &, "DT_CaptureFlag", "m_nUseTrailEffect");
	}
	inline int &nPointValue ()
	{
		NETVAR_RETURN_THIS (int &, "DT_CaptureFlag", "m_nPointValue");
	}
	inline float &flAutoCapTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_CaptureFlag", "m_flAutoCapTime");
	}
	inline bool &bGlowEnabled ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_CaptureFlag", "m_bGlowEnabled");
	}
	inline float &flTimeToSetPoisonous ()
	{
		NETVAR_RETURN_THIS (float &, "DT_CaptureFlag", "m_flTimeToSetPoisonous");
	}
};
struct DT_CBonusPack : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_CBonusPack, DT_BaseAnimating);
};
struct DT_Team
{
	NETVAR_REFLECTION_NOBASE (DT_Team);
	inline int &iTeamNum ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Team", "m_iTeamNum");
	}
	inline int &iScore ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Team", "m_iScore");
	}
	inline int &iRoundsWon ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Team", "m_iRoundsWon");
	}
	inline char *&szTeamname ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_Team", "m_szTeamname");
	}
}; // Fail count = 2
struct DT_TFTeam : public DT_Team
{
	NETVAR_REFLECTION (DT_TFTeam, DT_Team);
	inline int &nFlagCaptures ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFTeam", "m_nFlagCaptures");
	}
	inline int &iRole ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFTeam", "m_iRole");
	}
	inline EHANDLE &hLeader ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFTeam", "m_hLeader");
	}
}; // Fail count = 2
struct DT_TFTauntProp : public DT_BaseCombatCharacter
{
	NETVAR_REFLECTION (DT_TFTauntProp, DT_BaseCombatCharacter);
};
struct DT_PlayerResource
{
	NETVAR_REFLECTION_NOBASE (DT_PlayerResource);
	inline int *iPing ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_PlayerResource", "m_iPing");
	} // Array size = 34
	inline int *iScore ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_PlayerResource", "m_iScore");
	} // Array size = 34
	inline int *iDeaths ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_PlayerResource", "m_iDeaths");
	} // Array size = 34
	inline bool *bConnected ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_PlayerResource", "m_bConnected");
	} // Array size = 34
	inline int *iTeam ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_PlayerResource", "m_iTeam");
	} // Array size = 34
	inline bool *bAlive ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_PlayerResource", "m_bAlive");
	} // Array size = 34
	inline int *iHealth ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_PlayerResource", "m_iHealth");
	} // Array size = 34
	inline int *iAccountID ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_PlayerResource", "m_iAccountID");
	} // Array size = 34
	inline bool *bValid ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_PlayerResource", "m_bValid");
	} // Array size = 34
};
struct DT_TFPlayerResource : public DT_PlayerResource
{
	NETVAR_REFLECTION (DT_TFPlayerResource, DT_PlayerResource);
	inline int *iTotalScore ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iTotalScore");
	} // Array size = 34
	inline int *iMaxHealth ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iMaxHealth");
	} // Array size = 34
	inline int *iMaxBuffedHealth ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iMaxBuffedHealth");
	} // Array size = 34
	inline int *iPlayerClass ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iPlayerClass");
	} // Array size = 34
	inline bool *bArenaSpectator ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_TFPlayerResource", "m_bArenaSpectator");
	} // Array size = 34
	inline int *iActiveDominations ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iActiveDominations");
	} // Array size = 34
	inline float *flNextRespawnTime ()
	{
		NETVAR_RETURN_ARRAY_THIS (float *, "DT_TFPlayerResource", "m_flNextRespawnTime");
	} // Array size = 34
	inline int *iChargeLevel ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iChargeLevel");
	} // Array size = 34
	inline int *iDamage ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iDamage");
	} // Array size = 34
	inline int *iDamageAssist ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iDamageAssist");
	} // Array size = 34
	inline int *iDamageBoss ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iDamageBoss");
	} // Array size = 34
	inline int *iHealing ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iHealing");
	} // Array size = 34
	inline int *iHealingAssist ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iHealingAssist");
	} // Array size = 34
	inline int *iDamageBlocked ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iDamageBlocked");
	} // Array size = 34
	inline int *iCurrencyCollected ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iCurrencyCollected");
	} // Array size = 34
	inline int *iBonusPoints ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iBonusPoints");
	} // Array size = 34
	inline int *iPlayerLevel ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iPlayerLevel");
	} // Array size = 34
	inline int *iStreaks ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iStreaks");
	} // Array size = 136
	inline int *iUpgradeRefundCredits ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iUpgradeRefundCredits");
	} // Array size = 34
	inline int *iBuybackCredits ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iBuybackCredits");
	} // Array size = 34
	inline int &iPartyLeaderRedTeamIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayerResource", "m_iPartyLeaderRedTeamIndex");
	}
	inline int &iPartyLeaderBlueTeamIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayerResource", "m_iPartyLeaderBlueTeamIndex");
	}
	inline int &iEventTeamStatus ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayerResource", "m_iEventTeamStatus");
	}
	inline int *iPlayerClassWhenKilled ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iPlayerClassWhenKilled");
	} // Array size = 34
	inline int *iConnectionState ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayerResource", "m_iConnectionState");
	} // Array size = 34
};
struct DT_BasePlayer : public DT_BaseCombatCharacter
{
	NETVAR_REFLECTION (DT_BasePlayer, DT_BaseCombatCharacter);
	struct CLocalPlayerExclusive
	{
		NETVAR_REFLECTION (CLocalPlayerExclusive, DT_BasePlayer);
		struct CLocal
		{
			NETVAR_REFLECTION (CLocal, CLocalPlayerExclusive);
			inline char *chAreaBits ()
			{
				NETVAR_RETURN_ARRAY_THIS (char *, "DT_BasePlayer", "localdata", "m_Local", "m_chAreaBits");
			} // Array size = 32
			inline char *chAreaPortalBits ()
			{
				NETVAR_RETURN_ARRAY_THIS (char *, "DT_BasePlayer", "localdata", "m_Local", "m_chAreaPortalBits");
			} // Array size = 24
			inline int &iHideHUD ()
			{
				NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_Local", "m_iHideHUD");
			}
			inline float &flFOVRate ()
			{
				NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_Local", "m_flFOVRate");
			}
			inline bool &bDucked ()
			{
				NETVAR_RETURN_THIS (bool &, "DT_BasePlayer", "localdata", "m_Local", "m_bDucked");
			}
			inline bool &bDucking ()
			{
				NETVAR_RETURN_THIS (bool &, "DT_BasePlayer", "localdata", "m_Local", "m_bDucking");
			}
			inline bool &bInDuckJump ()
			{
				NETVAR_RETURN_THIS (bool &, "DT_BasePlayer", "localdata", "m_Local", "m_bInDuckJump");
			}
			inline float &flDucktime ()
			{
				NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_Local", "m_flDucktime");
			}
			inline float &flDuckJumpTime ()
			{
				NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_Local", "m_flDuckJumpTime");
			}
			inline float &flJumpTime ()
			{
				NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_Local", "m_flJumpTime");
			}
			inline float &flFallVelocity ()
			{
				NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_Local", "m_flFallVelocity");
			}
			inline Vector &vecPunchAngle ()
			{
				NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_Local", "m_vecPunchAngle");
			}
			inline Vector &vecPunchAngleVel ()
			{
				NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_Local", "m_vecPunchAngleVel");
			}
			inline bool &bDrawViewmodel ()
			{
				NETVAR_RETURN_THIS (bool &, "DT_BasePlayer", "localdata", "m_Local", "m_bDrawViewmodel");
			}
			inline bool &bWearingSuit ()
			{
				NETVAR_RETURN_THIS (bool &, "DT_BasePlayer", "localdata", "m_Local", "m_bWearingSuit");
			}
			inline bool &bPoisoned ()
			{
				NETVAR_RETURN_THIS (bool &, "DT_BasePlayer", "localdata", "m_Local", "m_bPoisoned");
			}
			inline float &flStepSize ()
			{
				NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_Local", "m_flStepSize");
			}
			inline bool &bAllowAutoMovement ()
			{
				NETVAR_RETURN_THIS (bool &, "DT_BasePlayer", "localdata", "m_Local", "m_bAllowAutoMovement");
			}
			inline int &skybox3d_scale ()
			{
				NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_Local", "m_skybox3d.scale");
			}
			inline Vector &skybox3d_origin ()
			{
				NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_Local", "m_skybox3d.origin");
			}
			inline int &skybox3d_area ()
			{
				NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_Local", "m_skybox3d.area");
			}
			inline int &skybox3d_fog_enable ()
			{
				NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_Local", "m_skybox3d.fog.enable");
			}
			inline int &skybox3d_fog_blend ()
			{
				NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_Local", "m_skybox3d.fog.blend");
			}
			inline Vector &skybox3d_fog_dirPrimary ()
			{
				NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_Local", "m_skybox3d.fog.dirPrimary");
			}
			inline int &skybox3d_fog_colorPrimary ()
			{
				NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_Local", "m_skybox3d.fog.colorPrimary");
			}
			inline int &skybox3d_fog_colorSecondary ()
			{
				NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_Local", "m_skybox3d.fog.colorSecondary");
			}
			inline float &skybox3d_fog_start ()
			{
				NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_Local", "m_skybox3d.fog.start");
			}
			inline float &skybox3d_fog_end ()
			{
				NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_Local", "m_skybox3d.fog.end");
			}
			inline float &skybox3d_fog_maxdensity ()
			{
				NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_Local", "m_skybox3d.fog.maxdensity");
			}
			inline int &PlayerFog_m_hCtrl ()
			{
				NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_Local", "m_PlayerFog.m_hCtrl");
			}
			inline Vector &audio_localSound0 ()
			{
				NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_Local", "m_audio.localSound[0]");
			}
			inline Vector &audio_localSound1 ()
			{
				NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_Local", "m_audio.localSound[1]");
			}
			inline Vector &audio_localSound2 ()
			{
				NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_Local", "m_audio.localSound[2]");
			}
			inline Vector &audio_localSound3 ()
			{
				NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_Local", "m_audio.localSound[3]");
			}
			inline Vector &audio_localSound4 ()
			{
				NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_Local", "m_audio.localSound[4]");
			}
			inline Vector &audio_localSound5 ()
			{
				NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_Local", "m_audio.localSound[5]");
			}
			inline Vector &audio_localSound6 ()
			{
				NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_Local", "m_audio.localSound[6]");
			}
			inline Vector &audio_localSound7 ()
			{
				NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_Local", "m_audio.localSound[7]");
			}
			inline int &audio_soundscapeIndex ()
			{
				NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_Local", "m_audio.soundscapeIndex");
			}
			inline int &audio_localBits ()
			{
				NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_Local", "m_audio.localBits");
			}
			inline int &audio_ent ()
			{
				NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_Local", "m_audio.ent");
			}
		};
		inline CLocal &Local ()
		{
			NETVAR_RETURN_THIS (CLocal &, "DT_BasePlayer", "localdata", "m_Local");
		}
		inline Vector &vecViewOffset0 ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_vecViewOffset[0]");
		}
		inline Vector &vecViewOffset1 ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_vecViewOffset[1]");
		}
		inline Vector &vecViewOffset2 ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_vecViewOffset[2]");
		}
		inline float &flFriction ()
		{
			NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_flFriction");
		}
		inline int *iAmmo ()
		{
			NETVAR_RETURN_ARRAY_THIS (int *, "DT_BasePlayer", "localdata", "m_iAmmo");
		} // Array size = 32
		inline int &fOnTarget ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_fOnTarget");
		}
		inline int &nTickBase ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_nTickBase");
		}
		inline int &nNextThinkTick ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_nNextThinkTick");
		}
		inline EHANDLE &hLastWeapon ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_BasePlayer", "localdata", "m_hLastWeapon");
		}
		inline EHANDLE &hGroundEntity ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_BasePlayer", "localdata", "m_hGroundEntity");
		}
		inline Vector &vecVelocity0 ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_vecVelocity[0]");
		}
		inline Vector &vecVelocity1 ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_vecVelocity[1]");
		}
		inline Vector &vecVelocity2 ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_vecVelocity[2]");
		}
		inline Vector &vecBaseVelocity ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_vecBaseVelocity");
		}
		inline EHANDLE &hConstraintEntity ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_BasePlayer", "localdata", "m_hConstraintEntity");
		}
		inline Vector &vecConstraintCenter ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_BasePlayer", "localdata", "m_vecConstraintCenter");
		}
		inline float &flConstraintRadius ()
		{
			NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_flConstraintRadius");
		}
		inline float &flConstraintWidth ()
		{
			NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_flConstraintWidth");
		}
		inline float &flConstraintSpeedFactor ()
		{
			NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_flConstraintSpeedFactor");
		}
		inline float &flDeathTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_flDeathTime");
		}
		inline int &nWaterLevel ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "localdata", "m_nWaterLevel");
		}
		inline float &flLaggedMovementValue ()
		{
			NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "localdata", "m_flLaggedMovementValue");
		}
	};
	struct CAttributeList
	{
		NETVAR_REFLECTION (CAttributeList, DT_BasePlayer);
	}; // Fail count = 1
	struct CPlayerState
	{
		NETVAR_REFLECTION (CPlayerState, DT_BasePlayer);
		inline int &deadflag ()
		{
			NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "pl", "deadflag");
		}
	};
	inline CLocalPlayerExclusive &localdata ()
	{
		NETVAR_RETURN_THIS (CLocalPlayerExclusive &, "DT_BasePlayer", "localdata");
	}
	inline CAttributeList &AttributeList ()
	{
		NETVAR_RETURN_THIS (CAttributeList &, "DT_BasePlayer", "m_AttributeList");
	}
	inline CPlayerState &pl ()
	{
		NETVAR_RETURN_THIS (CPlayerState &, "DT_BasePlayer", "pl");
	}
	inline int &iFOV ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "m_iFOV");
	}
	inline int &iFOVStart ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "m_iFOVStart");
	}
	inline float &flFOVTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "m_flFOVTime");
	}
	inline int &iDefaultFOV ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "m_iDefaultFOV");
	}
	inline EHANDLE &hZoomOwner ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BasePlayer", "m_hZoomOwner");
	}
	inline EHANDLE &hVehicle ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BasePlayer", "m_hVehicle");
	}
	inline EHANDLE &hUseEntity ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BasePlayer", "m_hUseEntity");
	}
	inline int &iHealth ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "m_iHealth");
	}
	inline int &lifeState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "m_lifeState");
	}
	inline int &iBonusProgress ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "m_iBonusProgress");
	}
	inline int &iBonusChallenge ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "m_iBonusChallenge");
	}
	inline float &flMaxspeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BasePlayer", "m_flMaxspeed");
	}
	inline int &fFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "m_fFlags");
	}
	inline int &iObserverMode ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BasePlayer", "m_iObserverMode");
	}
	inline EHANDLE &hObserverTarget ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BasePlayer", "m_hObserverTarget");
	}
	inline EHANDLE &hViewModel0 ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_BasePlayer", "m_hViewModel[0]");
	}
	inline EHANDLE *hViewModel ()
	{
		NETVAR_RETURN_ARRAY_THIS (EHANDLE *, "DT_BasePlayer", "m_hViewModel");
	} // Array size = 2
	inline char *&szLastPlaceName ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_BasePlayer", "m_szLastPlaceName");
	}
	inline EHANDLE *hMyWearables ()
	{
		NETVAR_RETURN_ARRAY_THIS (EHANDLE *, "DT_BasePlayer", "m_hMyWearables");
	} // Array size = 9
};
struct DT_TFPlayer : public DT_BasePlayer
{
	NETVAR_REFLECTION (DT_TFPlayer, DT_BasePlayer);
	struct CTFPlayerClassShared
	{
		NETVAR_REFLECTION (CTFPlayerClassShared, DT_TFPlayer);
		inline int &iClass ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_PlayerClass", "m_iClass");
		}
		inline int &iszClassIcon ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_PlayerClass", "m_iszClassIcon");
		}
		inline int &iszCustomModel ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_PlayerClass", "m_iszCustomModel");
		}
		inline Vector &vecCustomModelOffset ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_TFPlayer", "m_PlayerClass", "m_vecCustomModelOffset");
		}
		inline QAngle &angCustomModelRotation ()
		{
			NETVAR_RETURN_THIS (QAngle &, "DT_TFPlayer", "m_PlayerClass", "m_angCustomModelRotation");
		}
		inline bool &bCustomModelRotates ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_PlayerClass", "m_bCustomModelRotates");
		}
		inline bool &bCustomModelRotationSet ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_PlayerClass", "m_bCustomModelRotationSet");
		}
		inline bool &bCustomModelVisibleToSelf ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_PlayerClass", "m_bCustomModelVisibleToSelf");
		}
		inline bool &bUseClassAnimations ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_PlayerClass", "m_bUseClassAnimations");
		}
		inline int &iClassModelParity ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_PlayerClass", "m_iClassModelParity");
		}
	};
	struct CTFPlayerShared
	{
		NETVAR_REFLECTION (CTFPlayerShared, DT_TFPlayer);
		struct CTFPlayerSharedLocal
		{
			NETVAR_REFLECTION (CTFPlayerSharedLocal, CTFPlayerShared);
			struct CTFPlayerScoringDataExclusive
			{
				NETVAR_REFLECTION (CTFPlayerScoringDataExclusive, CTFPlayerSharedLocal);
				inline int &iCaptures ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iCaptures");
				}
				inline int &iDefenses ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iDefenses");
				}
				inline int &iKills ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iKills");
				}
				inline int &iDeaths ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iDeaths");
				}
				inline int &iSuicides ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iSuicides");
				}
				inline int &iDominations ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iDominations");
				}
				inline int &iRevenge ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iRevenge");
				}
				inline int &iBuildingsBuilt ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iBuildingsBuilt");
				}
				inline int &iBuildingsDestroyed ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iBuildingsDestroyed");
				}
				inline int &iHeadshots ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iHeadshots");
				}
				inline int &iBackstabs ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iBackstabs");
				}
				inline int &iHealPoints ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iHealPoints");
				}
				inline int &iInvulns ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iInvulns");
				}
				inline int &iTeleports ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iTeleports");
				}
				inline int &iResupplyPoints ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iResupplyPoints");
				}
				inline int &iKillAssists ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iKillAssists");
				}
				inline int &iPoints ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iPoints");
				}
				inline int &iBonusPoints ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iBonusPoints");
				}
				inline int &iDamageDone ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iDamageDone");
				}
				inline int &iCrits ()
				{
					NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData", "m_iCrits");
				}
			};
			inline int &nDesiredDisguiseTeam ()
			{
				NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_nDesiredDisguiseTeam");
			}
			inline int &nDesiredDisguiseClass ()
			{
				NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_nDesiredDisguiseClass");
			}
			inline float &flStealthNoAttackExpire ()
			{
				NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_flStealthNoAttackExpire");
			}
			inline float &flStealthNextChangeTime ()
			{
				NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_flStealthNextChangeTime");
			}
			inline bool &bLastDisguisedAsOwnTeam ()
			{
				NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_bLastDisguisedAsOwnTeam");
			}
			inline float &flRageMeter ()
			{
				NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_flRageMeter");
			}
			inline bool &bRageDraining ()
			{
				NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_bRageDraining");
			}
			inline float &flNextRageEarnTime ()
			{
				NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_flNextRageEarnTime");
			}
			inline bool &bInUpgradeZone ()
			{
				NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_bInUpgradeZone");
			}
			inline bool *bPlayerDominated ()
			{
				NETVAR_RETURN_ARRAY_THIS (bool *, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_bPlayerDominated");
			} // Array size = 34
			inline bool *bPlayerDominatingMe ()
			{
				NETVAR_RETURN_ARRAY_THIS (bool *, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_bPlayerDominatingMe");
			} // Array size = 34
			inline CTFPlayerScoringDataExclusive &ScoreData ()
			{
				NETVAR_RETURN_THIS (CTFPlayerScoringDataExclusive &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_ScoreData");
			}
			inline CTFPlayerScoringDataExclusive &RoundScoreData ()
			{
				NETVAR_RETURN_THIS (CTFPlayerScoringDataExclusive &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata", "m_RoundScoreData");
			}
		};
		struct CTFPlayerConditionListExclusive
		{
			NETVAR_REFLECTION (CTFPlayerConditionListExclusive, CTFPlayerShared);
			inline int &_condition_bits ()
			{
				NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_ConditionList", "_condition_bits");
			}
		};
		inline int &nPlayerCond ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nPlayerCond");
		}
		inline bool &bJumping ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_Shared", "m_bJumping");
		}
		inline int &nNumHealers ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nNumHealers");
		}
		inline int &iCritMult ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iCritMult");
		}
		inline int &iAirDash ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iAirDash");
		}
		inline int &nAirDucked ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nAirDucked");
		}
		inline float &flDuckTimer ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "m_flDuckTimer");
		}
		inline int &nPlayerState ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nPlayerState");
		}
		inline int &iDesiredPlayerClass ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iDesiredPlayerClass");
		}
		inline float &flMovementStunTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "m_flMovementStunTime");
		}
		inline int &iMovementStunAmount ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iMovementStunAmount");
		}
		inline int &iMovementStunParity ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iMovementStunParity");
		}
		inline EHANDLE &hStunner ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayer", "m_Shared", "m_hStunner");
		}
		inline int &iStunFlags ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iStunFlags");
		}
		inline int &nArenaNumChanges ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nArenaNumChanges");
		}
		inline bool &bArenaFirstBloodBoost ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_Shared", "m_bArenaFirstBloodBoost");
		}
		inline int &iWeaponKnockbackID ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iWeaponKnockbackID");
		}
		inline bool &bLoadoutUnavailable ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_Shared", "m_bLoadoutUnavailable");
		}
		inline int &iItemFindBonus ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iItemFindBonus");
		}
		inline bool &bShieldEquipped ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_Shared", "m_bShieldEquipped");
		}
		inline bool &bParachuteEquipped ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_Shared", "m_bParachuteEquipped");
		}
		inline int &iNextMeleeCrit ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iNextMeleeCrit");
		}
		inline int &iDecapitations ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iDecapitations");
		}
		inline int &iRevengeCrits ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iRevengeCrits");
		}
		inline int &iDisguiseBody ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iDisguiseBody");
		}
		inline EHANDLE &hCarriedObject ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayer", "m_Shared", "m_hCarriedObject");
		}
		inline bool &bCarryingObject ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_Shared", "m_bCarryingObject");
		}
		inline float &flNextNoiseMakerTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "m_flNextNoiseMakerTime");
		}
		inline int &iSpawnRoomTouchCount ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iSpawnRoomTouchCount");
		}
		inline int &iKillCountSinceLastDeploy ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iKillCountSinceLastDeploy");
		}
		inline float &flFirstPrimaryAttack ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "m_flFirstPrimaryAttack");
		}
		inline float &flEnergyDrinkMeter ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "m_flEnergyDrinkMeter");
		}
		inline float &flHypeMeter ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "m_flHypeMeter");
		}
		inline float &flChargeMeter ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "m_flChargeMeter");
		}
		inline float &flInvisChangeCompleteTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "m_flInvisChangeCompleteTime");
		}
		inline int &nDisguiseTeam ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nDisguiseTeam");
		}
		inline int &nDisguiseClass ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nDisguiseClass");
		}
		inline int &nDisguiseSkinOverride ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nDisguiseSkinOverride");
		}
		inline int &nMaskClass ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nMaskClass");
		}
		inline int &iDisguiseTargetIndex ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iDisguiseTargetIndex");
		}
		inline int &iDisguiseHealth ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iDisguiseHealth");
		}
		inline bool &bFeignDeathReady ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_Shared", "m_bFeignDeathReady");
		}
		inline EHANDLE &hDisguiseWeapon ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayer", "m_Shared", "m_hDisguiseWeapon");
		}
		inline int &nTeamTeleporterUsed ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nTeamTeleporterUsed");
		}
		inline float &flCloakMeter ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "m_flCloakMeter");
		}
		inline float &flSpyTranqBuffDuration ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "m_flSpyTranqBuffDuration");
		}
		inline CTFPlayerSharedLocal &tfsharedlocaldata ()
		{
			NETVAR_RETURN_THIS (CTFPlayerSharedLocal &, "DT_TFPlayer", "m_Shared", "tfsharedlocaldata");
		}
		inline CTFPlayerConditionListExclusive &ConditionList ()
		{
			NETVAR_RETURN_THIS (CTFPlayerConditionListExclusive &, "DT_TFPlayer", "m_Shared", "m_ConditionList");
		}
		inline int &iTauntIndex ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iTauntIndex");
		}
		inline int &iTauntConcept ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iTauntConcept");
		}
		inline int &nPlayerCondEx ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nPlayerCondEx");
		}
		inline int &iStunIndex ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_iStunIndex");
		}
		inline int &nHalloweenBombHeadStage ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nHalloweenBombHeadStage");
		}
		inline int &nPlayerCondEx2 ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nPlayerCondEx2");
		}
		inline int &nPlayerCondEx3 ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_nPlayerCondEx3");
		}
		inline int *nStreaks ()
		{
			NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFPlayer", "m_Shared", "m_nStreaks");
		} // Array size = 4
		inline int &unTauntSourceItemID_Low ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_unTauntSourceItemID_Low");
		}
		inline int &unTauntSourceItemID_High ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_Shared", "m_unTauntSourceItemID_High");
		}
		inline float &flRuneCharge ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "m_flRuneCharge");
		}
		inline bool &bHasPasstimeBall ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_Shared", "m_bHasPasstimeBall");
		}
		inline bool &bIsTargetedForPasstimePass ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_Shared", "m_bIsTargetedForPasstimePass");
		}
		inline EHANDLE &hPasstimePassTarget ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayer", "m_Shared", "m_hPasstimePassTarget");
		}
		inline float &askForBallTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_Shared", "m_askForBallTime");
		}
		inline bool &bKingRuneBuffActive ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_Shared", "m_bKingRuneBuffActive");
		}
	}; // Fail count = 1
	struct CTFLocalPlayerExclusive
	{
		NETVAR_REFLECTION (CTFLocalPlayerExclusive, DT_TFPlayer);
		inline Vector &vecOrigin ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_TFPlayer", "tflocaldata", "m_vecOrigin");
		}
		inline Vector &vecOrigin2 ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_TFPlayer", "tflocaldata", "m_vecOrigin[2]");
		}
		inline QAngle &angEyeAngles0 ()
		{
			NETVAR_RETURN_THIS (QAngle &, "DT_TFPlayer", "tflocaldata", "m_angEyeAngles[0]");
		}
		inline bool &bIsCoaching ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "tflocaldata", "m_bIsCoaching");
		}
		inline EHANDLE &hCoach ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayer", "tflocaldata", "m_hCoach");
		}
		inline EHANDLE &hStudent ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayer", "tflocaldata", "m_hStudent");
		}
		inline int &nCurrency ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "tflocaldata", "m_nCurrency");
		}
		inline int &nExperienceLevel ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "tflocaldata", "m_nExperienceLevel");
		}
		inline int &nExperienceLevelProgress ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "tflocaldata", "m_nExperienceLevelProgress");
		}
		inline bool &bMatchSafeToLeave ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "tflocaldata", "m_bMatchSafeToLeave");
		}
	}; // Fail count = 2
	struct CTFNonLocalPlayerExclusive
	{
		NETVAR_REFLECTION (CTFNonLocalPlayerExclusive, DT_TFPlayer);
		inline Vector &vecOrigin ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_TFPlayer", "tfnonlocaldata", "m_vecOrigin");
		}
		inline Vector &vecOrigin2 ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_TFPlayer", "tfnonlocaldata", "m_vecOrigin[2]");
		}
		inline QAngle &angEyeAngles0 ()
		{
			NETVAR_RETURN_THIS (QAngle &, "DT_TFPlayer", "tfnonlocaldata", "m_angEyeAngles[0]");
		}
		inline QAngle &angEyeAngles1 ()
		{
			NETVAR_RETURN_THIS (QAngle &, "DT_TFPlayer", "tfnonlocaldata", "m_angEyeAngles[1]");
		}
	};
	struct CAttributeManager
	{
		NETVAR_REFLECTION (CAttributeManager, DT_TFPlayer);
		inline EHANDLE &hOuter ()
		{
			NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayer", "m_AttributeManager", "m_hOuter");
		}
		inline int &ProviderType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_AttributeManager", "m_ProviderType");
		}
		inline int &iReapplyProvisionParity ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_AttributeManager", "m_iReapplyProvisionParity");
		}
	};
	struct CTFSendHealersDataTable
	{
		NETVAR_REFLECTION (CTFSendHealersDataTable, DT_TFPlayer);
		inline int &nActiveWpnClip ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "TFSendHealersDataTable", "m_nActiveWpnClip");
		}
	};
	inline bool &bSaveMeParity ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_bSaveMeParity");
	}
	inline bool &bIsMiniBoss ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_bIsMiniBoss");
	}
	inline bool &bIsABot ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_bIsABot");
	}
	inline int &nBotSkill ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_nBotSkill");
	}
	inline int &nWaterLevel ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_nWaterLevel");
	}
	inline EHANDLE &hRagdoll ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayer", "m_hRagdoll");
	}
	inline CTFPlayerClassShared &PlayerClass ()
	{
		NETVAR_RETURN_THIS (CTFPlayerClassShared &, "DT_TFPlayer", "m_PlayerClass");
	}
	inline CTFPlayerShared &Shared ()
	{
		NETVAR_RETURN_THIS (CTFPlayerShared &, "DT_TFPlayer", "m_Shared");
	}
	inline EHANDLE &hItem ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayer", "m_hItem");
	}
	inline CTFLocalPlayerExclusive &tflocaldata ()
	{
		NETVAR_RETURN_THIS (CTFLocalPlayerExclusive &, "DT_TFPlayer", "tflocaldata");
	}
	inline CTFNonLocalPlayerExclusive &tfnonlocaldata ()
	{
		NETVAR_RETURN_THIS (CTFNonLocalPlayerExclusive &, "DT_TFPlayer", "tfnonlocaldata");
	}
	inline bool &bAllowMoveDuringTaunt ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_bAllowMoveDuringTaunt");
	}
	inline bool &bIsReadyToHighFive ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_bIsReadyToHighFive");
	}
	inline EHANDLE &hHighFivePartner ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayer", "m_hHighFivePartner");
	}
	inline int &nForceTauntCam ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_nForceTauntCam");
	}
	inline float &flTauntYaw ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_flTauntYaw");
	}
	inline int &nActiveTauntSlot ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_nActiveTauntSlot");
	}
	inline int &iTauntItemDefIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_iTauntItemDefIndex");
	}
	inline float &flCurrentTauntMoveSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_flCurrentTauntMoveSpeed");
	}
	inline float &flVehicleReverseTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_flVehicleReverseTime");
	}
	inline float &flLastDamageTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_flLastDamageTime");
	}
	inline bool &bInPowerPlay ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_bInPowerPlay");
	}
	inline int &iSpawnCounter ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_iSpawnCounter");
	}
	inline bool &bArenaSpectator ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_bArenaSpectator");
	}
	inline CAttributeManager &AttributeManager ()
	{
		NETVAR_RETURN_THIS (CAttributeManager &, "DT_TFPlayer", "m_AttributeManager");
	}
	inline float &flHeadScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_flHeadScale");
	}
	inline float &flTorsoScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_flTorsoScale");
	}
	inline float &flHandScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_flHandScale");
	}
	inline bool &bUseBossHealthBar ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_bUseBossHealthBar");
	}
	inline bool &bUsingVRHeadset ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_bUsingVRHeadset");
	}
	inline bool &bForcedSkin ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_bForcedSkin");
	}
	inline int &nForcedSkin ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_nForcedSkin");
	}
	inline bool &bGlowEnabled ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_bGlowEnabled");
	}
	inline CTFSendHealersDataTable &TFSendHealersDataTable ()
	{
		NETVAR_RETURN_THIS (CTFSendHealersDataTable &, "DT_TFPlayer", "TFSendHealersDataTable");
	}
	inline float &flKartNextAvailableBoost ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_flKartNextAvailableBoost");
	}
	inline int &iKartHealth ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_iKartHealth");
	}
	inline int &iKartState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_iKartState");
	}
	inline EHANDLE &hGrapplingHookTarget ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayer", "m_hGrapplingHookTarget");
	}
	inline EHANDLE &hSecondaryLastWeapon ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPlayer", "m_hSecondaryLastWeapon");
	}
	inline bool &bUsingActionSlot ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFPlayer", "m_bUsingActionSlot");
	}
	inline float &flInspectTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFPlayer", "m_flInspectTime");
	}
	inline int &iCampaignMedals ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_iCampaignMedals");
	}
	inline int &iPlayerSkinOverride ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPlayer", "m_iPlayerSkinOverride");
	}
};
struct DT_TFRagdoll
{
	NETVAR_REFLECTION_NOBASE (DT_TFRagdoll);
	inline Vector &vecRagdollOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TFRagdoll", "m_vecRagdollOrigin");
	}
	inline int &iPlayerIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRagdoll", "m_iPlayerIndex");
	}
	inline Vector &vecForce ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TFRagdoll", "m_vecForce");
	}
	inline Vector &vecRagdollVelocity ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TFRagdoll", "m_vecRagdollVelocity");
	}
	inline int &nForceBone ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRagdoll", "m_nForceBone");
	}
	inline bool &bGib ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFRagdoll", "m_bGib");
	}
	inline bool &bBurning ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFRagdoll", "m_bBurning");
	}
	inline bool &bElectrocuted ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFRagdoll", "m_bElectrocuted");
	}
	inline bool &bFeignDeath ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFRagdoll", "m_bFeignDeath");
	}
	inline bool &bWasDisguised ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFRagdoll", "m_bWasDisguised");
	}
	inline bool &bOnGround ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFRagdoll", "m_bOnGround");
	}
	inline bool &bCloaked ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFRagdoll", "m_bCloaked");
	}
	inline bool &bBecomeAsh ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFRagdoll", "m_bBecomeAsh");
	}
	inline int &iDamageCustom ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRagdoll", "m_iDamageCustom");
	}
	inline int &iTeam ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRagdoll", "m_iTeam");
	}
	inline int &iClass ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFRagdoll", "m_iClass");
	}
	inline EHANDLE *hRagWearables ()
	{
		NETVAR_RETURN_ARRAY_THIS (EHANDLE *, "DT_TFRagdoll", "m_hRagWearables");
	} // Array size = 9
	inline bool &bGoldRagdoll ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFRagdoll", "m_bGoldRagdoll");
	}
	inline bool &bIceRagdoll ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFRagdoll", "m_bIceRagdoll");
	}
	inline bool &bCritOnHardHit ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFRagdoll", "m_bCritOnHardHit");
	}
	inline float &flHeadScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFRagdoll", "m_flHeadScale");
	}
	inline float &flTorsoScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFRagdoll", "m_flTorsoScale");
	}
	inline float &flHandScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFRagdoll", "m_flHandScale");
	}
};
struct DT_TEPlayerAnimEvent
{
	NETVAR_REFLECTION_NOBASE (DT_TEPlayerAnimEvent);
	inline int &iPlayerIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEPlayerAnimEvent", "m_iPlayerIndex");
	}
	inline int &iEvent ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEPlayerAnimEvent", "m_iEvent");
	}
	inline int &nData ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEPlayerAnimEvent", "m_nData");
	}
};
struct DT_TFPasstimeLogic : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_TFPasstimeLogic, DT_BaseEntity);
	inline EHANDLE &hBall ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFPasstimeLogic", "m_hBall");
	}
	inline Vector &trackPoints0 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TFPasstimeLogic", "m_trackPoints[0]");
	}
	inline int &iNumSections ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPasstimeLogic", "m_iNumSections");
	}
	inline int &iCurrentSection ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPasstimeLogic", "m_iCurrentSection");
	}
	inline float &flMaxPassRange ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFPasstimeLogic", "m_flMaxPassRange");
	}
	inline int &iBallPower ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFPasstimeLogic", "m_iBallPower");
	}
	inline float &flPackSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFPasstimeLogic", "m_flPackSpeed");
	}
	inline bool *bPlayerIsPackMember ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_TFPasstimeLogic", "m_bPlayerIsPackMember");
	} // Array size = 34
};    // Fail count = 1
struct DT_PasstimeBall : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_PasstimeBall, DT_BaseAnimating);
	inline int &iCollisionCount ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PasstimeBall", "m_iCollisionCount");
	}
	inline EHANDLE &hHomingTarget ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_PasstimeBall", "m_hHomingTarget");
	}
	inline EHANDLE &hCarrier ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_PasstimeBall", "m_hCarrier");
	}
	inline EHANDLE &hPrevCarrier ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_PasstimeBall", "m_hPrevCarrier");
	}
};
struct DT_BaseTeamObjectiveResource
{
	NETVAR_REFLECTION_NOBASE (DT_BaseTeamObjectiveResource);
	inline int &iTimerToShowInHUD ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseTeamObjectiveResource", "m_iTimerToShowInHUD");
	}
	inline int &iStopWatchTimer ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseTeamObjectiveResource", "m_iStopWatchTimer");
	}
	inline int &iNumControlPoints ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseTeamObjectiveResource", "m_iNumControlPoints");
	}
	inline bool &bPlayingMiniRounds ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseTeamObjectiveResource", "m_bPlayingMiniRounds");
	}
	inline bool &bControlPointsReset ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BaseTeamObjectiveResource", "m_bControlPointsReset");
	}
	inline int &iUpdateCapHudParity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseTeamObjectiveResource", "m_iUpdateCapHudParity");
	}
	inline Vector &vCPPositions0 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_BaseTeamObjectiveResource", "m_vCPPositions[0]");
	}
	inline bool *bCPIsVisible ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_BaseTeamObjectiveResource", "m_bCPIsVisible");
	} // Array size = 8
	inline float *flLazyCapPerc ()
	{
		NETVAR_RETURN_ARRAY_THIS (float *, "DT_BaseTeamObjectiveResource", "m_flLazyCapPerc");
	} // Array size = 8
	inline int *iTeamIcons ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_iTeamIcons");
	} // Array size = 64
	inline int *iTeamOverlays ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_iTeamOverlays");
	} // Array size = 64
	inline int *iTeamReqCappers ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_iTeamReqCappers");
	} // Array size = 64
	inline float *flTeamCapTime ()
	{
		NETVAR_RETURN_ARRAY_THIS (float *, "DT_BaseTeamObjectiveResource", "m_flTeamCapTime");
	} // Array size = 64
	inline int *iPreviousPoints ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_iPreviousPoints");
	} // Array size = 192
	inline bool *bTeamCanCap ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_BaseTeamObjectiveResource", "m_bTeamCanCap");
	} // Array size = 64
	inline int *iTeamBaseIcons ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_iTeamBaseIcons");
	} // Array size = 32
	inline int *iBaseControlPoints ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_iBaseControlPoints");
	} // Array size = 32
	inline bool *bInMiniRound ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_BaseTeamObjectiveResource", "m_bInMiniRound");
	} // Array size = 8
	inline int *iWarnOnCap ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_iWarnOnCap");
	} // Array size = 8
	inline int &iszWarnSound0 ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseTeamObjectiveResource", "m_iszWarnSound[0]");
	}
	inline int *iszWarnSound ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_iszWarnSound");
	} // Array size = 8
	inline float *flPathDistance ()
	{
		NETVAR_RETURN_ARRAY_THIS (float *, "DT_BaseTeamObjectiveResource", "m_flPathDistance");
	} // Array size = 8
	inline int *iCPGroup ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_iCPGroup");
	} // Array size = 8
	inline bool *bCPLocked ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_BaseTeamObjectiveResource", "m_bCPLocked");
	} // Array size = 8
	inline int *nNumNodeHillData ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_nNumNodeHillData");
	} // Array size = 4
	inline float *flNodeHillData ()
	{
		NETVAR_RETURN_ARRAY_THIS (float *, "DT_BaseTeamObjectiveResource", "m_flNodeHillData");
	} // Array size = 40
	inline bool *bTrackAlarm ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_BaseTeamObjectiveResource", "m_bTrackAlarm");
	} // Array size = 4
	inline float *flUnlockTimes ()
	{
		NETVAR_RETURN_ARRAY_THIS (float *, "DT_BaseTeamObjectiveResource", "m_flUnlockTimes");
	} // Array size = 8
	inline bool *bHillIsDownhill ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_BaseTeamObjectiveResource", "m_bHillIsDownhill");
	} // Array size = 20
	inline float *flCPTimerTimes ()
	{
		NETVAR_RETURN_ARRAY_THIS (float *, "DT_BaseTeamObjectiveResource", "m_flCPTimerTimes");
	} // Array size = 8
	inline int *iNumTeamMembers ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_iNumTeamMembers");
	} // Array size = 64
	inline int *iCappingTeam ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_iCappingTeam");
	} // Array size = 8
	inline int *iTeamInZone ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_iTeamInZone");
	} // Array size = 8
	inline bool *bBlocked ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_BaseTeamObjectiveResource", "m_bBlocked");
	} // Array size = 8
	inline int *iOwner ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_BaseTeamObjectiveResource", "m_iOwner");
	} // Array size = 8
	inline bool *bCPCapRateScalesWithPlayers ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_BaseTeamObjectiveResource", "m_bCPCapRateScalesWithPlayers");
	} // Array size = 8
	inline char *&pszCapLayoutInHUD ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_BaseTeamObjectiveResource", "m_pszCapLayoutInHUD");
	}
	inline float &flCustomPositionX ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseTeamObjectiveResource", "m_flCustomPositionX");
	}
	inline float &flCustomPositionY ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseTeamObjectiveResource", "m_flCustomPositionY");
	}
}; // Fail count = 1
struct DT_TFObjectiveResource : public DT_BaseTeamObjectiveResource
{
	NETVAR_REFLECTION (DT_TFObjectiveResource, DT_BaseTeamObjectiveResource);
	inline int &nMannVsMachineMaxWaveCount ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFObjectiveResource", "m_nMannVsMachineMaxWaveCount");
	}
	inline int &nMannVsMachineWaveCount ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFObjectiveResource", "m_nMannVsMachineWaveCount");
	}
	inline int &nMannVsMachineWaveEnemyCount ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFObjectiveResource", "m_nMannVsMachineWaveEnemyCount");
	}
	inline int &nMvMWorldMoney ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFObjectiveResource", "m_nMvMWorldMoney");
	}
	inline float &flMannVsMachineNextWaveTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFObjectiveResource", "m_flMannVsMachineNextWaveTime");
	}
	inline bool &bMannVsMachineBetweenWaves ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFObjectiveResource", "m_bMannVsMachineBetweenWaves");
	}
	inline int &nFlagCarrierUpgradeLevel ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFObjectiveResource", "m_nFlagCarrierUpgradeLevel");
	}
	inline float &flMvMBaseBombUpgradeTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFObjectiveResource", "m_flMvMBaseBombUpgradeTime");
	}
	inline float &flMvMNextBombUpgradeTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TFObjectiveResource", "m_flMvMNextBombUpgradeTime");
	}
	inline int &iszMvMPopfileName ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFObjectiveResource", "m_iszMvMPopfileName");
	}
	inline int &iChallengeIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFObjectiveResource", "m_iChallengeIndex");
	}
	inline int &nMvMEventPopfileType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFObjectiveResource", "m_nMvMEventPopfileType");
	}
	inline int *nMannVsMachineWaveClassCounts ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFObjectiveResource", "m_nMannVsMachineWaveClassCounts");
	} // Array size = 12
	inline int &iszMannVsMachineWaveClassNames0 ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFObjectiveResource", "m_iszMannVsMachineWaveClassNames[0]");
	}
	inline int *iszMannVsMachineWaveClassNames ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFObjectiveResource", "m_iszMannVsMachineWaveClassNames");
	} // Array size = 12
	inline int *nMannVsMachineWaveClassFlags ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFObjectiveResource", "m_nMannVsMachineWaveClassFlags");
	} // Array size = 12
	inline int *nMannVsMachineWaveClassCounts2 ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFObjectiveResource", "m_nMannVsMachineWaveClassCounts2");
	} // Array size = 12
	inline int &iszMannVsMachineWaveClassNames20 ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFObjectiveResource", "m_iszMannVsMachineWaveClassNames2[0]");
	}
	inline int *iszMannVsMachineWaveClassNames2 ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFObjectiveResource", "m_iszMannVsMachineWaveClassNames2");
	} // Array size = 12
	inline int *nMannVsMachineWaveClassFlags2 ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_TFObjectiveResource", "m_nMannVsMachineWaveClassFlags2");
	} // Array size = 12
	inline bool *bMannVsMachineWaveClassActive ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_TFObjectiveResource", "m_bMannVsMachineWaveClassActive");
	} // Array size = 12
	inline bool *bMannVsMachineWaveClassActive2 ()
	{
		NETVAR_RETURN_ARRAY_THIS (bool *, "DT_TFObjectiveResource", "m_bMannVsMachineWaveClassActive2");
	} // Array size = 12
};
struct DT_TFGlow : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_TFGlow, DT_BaseEntity);
	inline int &iMode ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFGlow", "m_iMode");
	}
	inline int &glowColor ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TFGlow", "m_glowColor");
	}
	inline bool &bDisabled ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TFGlow", "m_bDisabled");
	}
	inline EHANDLE &hTarget ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TFGlow", "m_hTarget");
	}
};
struct DT_TEFireBullets
{
	NETVAR_REFLECTION_NOBASE (DT_TEFireBullets);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEFireBullets", "m_vecOrigin");
	}
	inline Vector &vecAngles0 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEFireBullets", "m_vecAngles[0]");
	}
	inline Vector &vecAngles1 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEFireBullets", "m_vecAngles[1]");
	}
	inline int &iWeaponID ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEFireBullets", "m_iWeaponID");
	}
	inline int &iMode ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEFireBullets", "m_iMode");
	}
	inline int &iSeed ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEFireBullets", "m_iSeed");
	}
	inline int &iPlayer ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEFireBullets", "m_iPlayer");
	}
	inline float &flSpread ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TEFireBullets", "m_flSpread");
	}
	inline bool &bCritical ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TEFireBullets", "m_bCritical");
	}
};
struct DT_TFBuffBanner : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_TFBuffBanner, DT_BaseAnimating);
};
struct DT_AmmoPack : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_AmmoPack, DT_BaseAnimating);
	inline Vector &vecInitialVelocity ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_AmmoPack", "m_vecInitialVelocity");
	}
	inline QAngle &angRotation0 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_AmmoPack", "m_angRotation[0]");
	}
	inline QAngle &angRotation1 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_AmmoPack", "m_angRotation[1]");
	}
	inline QAngle &angRotation2 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_AmmoPack", "m_angRotation[2]");
	}
};
struct DT_ObjectTeleporter : public DT_BaseObject
{
	NETVAR_REFLECTION (DT_ObjectTeleporter, DT_BaseObject);
	inline int &iState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ObjectTeleporter", "m_iState");
	}
	inline float &flRechargeTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_ObjectTeleporter", "m_flRechargeTime");
	}
	inline float &flCurrentRechargeDuration ()
	{
		NETVAR_RETURN_THIS (float &, "DT_ObjectTeleporter", "m_flCurrentRechargeDuration");
	}
	inline int &iTimesUsed ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ObjectTeleporter", "m_iTimesUsed");
	}
	inline float &flYawToExit ()
	{
		NETVAR_RETURN_THIS (float &, "DT_ObjectTeleporter", "m_flYawToExit");
	}
	inline bool &bMatchBuilding ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_ObjectTeleporter", "m_bMatchBuilding");
	}
};
struct DT_ObjectSentrygun : public DT_BaseObject
{
	NETVAR_REFLECTION (DT_ObjectSentrygun, DT_BaseObject);
	struct CSentrygunLocalData
	{
		NETVAR_REFLECTION (CSentrygunLocalData, DT_ObjectSentrygun);
		inline int &iKills ()
		{
			NETVAR_RETURN_THIS (int &, "DT_ObjectSentrygun", "SentrygunLocalData", "m_iKills");
		}
		inline int &iAssists ()
		{
			NETVAR_RETURN_THIS (int &, "DT_ObjectSentrygun", "SentrygunLocalData", "m_iAssists");
		}
	};
	inline int &iAmmoShells ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ObjectSentrygun", "m_iAmmoShells");
	}
	inline int &iAmmoRockets ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ObjectSentrygun", "m_iAmmoRockets");
	}
	inline int &iState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ObjectSentrygun", "m_iState");
	}
	inline bool &bPlayerControlled ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_ObjectSentrygun", "m_bPlayerControlled");
	}
	inline int &nShieldLevel ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ObjectSentrygun", "m_nShieldLevel");
	}
	inline bool &bShielded ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_ObjectSentrygun", "m_bShielded");
	}
	inline EHANDLE &hEnemy ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_ObjectSentrygun", "m_hEnemy");
	}
	inline EHANDLE &hAutoAimTarget ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_ObjectSentrygun", "m_hAutoAimTarget");
	}
	inline CSentrygunLocalData &SentrygunLocalData ()
	{
		NETVAR_RETURN_THIS (CSentrygunLocalData &, "DT_ObjectSentrygun", "SentrygunLocalData");
	}
};
struct DT_TFProjectile_SentryRocket : public DT_TFProjectile_Rocket
{
	NETVAR_REFLECTION (DT_TFProjectile_SentryRocket, DT_TFProjectile_Rocket);
};
struct DT_ObjectSapper : public DT_BaseObjectUpgrade
{
	NETVAR_REFLECTION (DT_ObjectSapper, DT_BaseObjectUpgrade);
};
struct DT_ObjectCartDispenser : public DT_ObjectDispenser
{
	NETVAR_REFLECTION (DT_ObjectCartDispenser, DT_ObjectDispenser);
};
struct DT_MonsterResource
{
	NETVAR_REFLECTION_NOBASE (DT_MonsterResource);
	inline int &iBossHealthPercentageByte ()
	{
		NETVAR_RETURN_THIS (int &, "DT_MonsterResource", "m_iBossHealthPercentageByte");
	}
	inline int &iBossStunPercentageByte ()
	{
		NETVAR_RETURN_THIS (int &, "DT_MonsterResource", "m_iBossStunPercentageByte");
	}
	inline int &iSkillShotCompleteCount ()
	{
		NETVAR_RETURN_THIS (int &, "DT_MonsterResource", "m_iSkillShotCompleteCount");
	}
	inline int &fSkillShotComboEndTime ()
	{
		NETVAR_RETURN_THIS (int &, "DT_MonsterResource", "m_fSkillShotComboEndTime");
	}
	inline int &iBossState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_MonsterResource", "m_iBossState");
	}
};
struct DT_FuncRespawnRoomVisualizer : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_FuncRespawnRoomVisualizer, DT_BaseEntity);
};
struct DT_FuncRespawnRoom : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_FuncRespawnRoom, DT_BaseEntity);
};
struct DT_FuncPasstimeGoal : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_FuncPasstimeGoal, DT_BaseEntity);
	inline bool &bTriggerDisabled ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_FuncPasstimeGoal", "m_bTriggerDisabled");
	}
	inline int &iGoalType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FuncPasstimeGoal", "m_iGoalType");
	}
};
struct DT_FuncForceField : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_FuncForceField, DT_BaseEntity);
};
struct DT_CaptureZone : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_CaptureZone, DT_BaseEntity);
	inline bool &bDisabled ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_CaptureZone", "m_bDisabled");
	}
};
struct DT_CurrencyPack : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_CurrencyPack, DT_BaseAnimating);
	inline bool &bDistributed ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_CurrencyPack", "m_bDistributed");
	}
};
struct DT_TestTraceline
{
	NETVAR_REFLECTION_NOBASE (DT_TestTraceline);
	inline int &clrRender ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TestTraceline", "m_clrRender");
	}
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TestTraceline", "m_vecOrigin");
	}
	inline QAngle &angRotation0 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_TestTraceline", "m_angRotation[0]");
	}
	inline QAngle &angRotation1 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_TestTraceline", "m_angRotation[1]");
	}
	inline QAngle &angRotation2 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_TestTraceline", "m_angRotation[2]");
	}
	inline int &moveparent ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TestTraceline", "moveparent");
	}
};
struct DT_TEWorldDecal : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEWorldDecal, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEWorldDecal", "m_vecOrigin");
	}
	inline int &nIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEWorldDecal", "m_nIndex");
	}
};
struct DT_TESpriteSpray : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TESpriteSpray, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TESpriteSpray", "m_vecOrigin");
	}
	inline Vector &vecDirection ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TESpriteSpray", "m_vecDirection");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TESpriteSpray", "m_nModelIndex");
	}
	inline int &fNoise ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TESpriteSpray", "m_fNoise");
	}
	inline int &nCount ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TESpriteSpray", "m_nCount");
	}
	inline int &nSpeed ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TESpriteSpray", "m_nSpeed");
	}
};
struct DT_TESprite : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TESprite, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TESprite", "m_vecOrigin");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TESprite", "m_nModelIndex");
	}
	inline int &fScale ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TESprite", "m_fScale");
	}
	inline int &nBrightness ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TESprite", "m_nBrightness");
	}
};
struct DT_TEParticleSystem : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEParticleSystem, DT_BaseTempEntity);
	inline Vector &vecOrigin0 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEParticleSystem", "m_vecOrigin[0]");
	}
	inline Vector &vecOrigin1 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEParticleSystem", "m_vecOrigin[1]");
	}
	inline Vector &vecOrigin2 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEParticleSystem", "m_vecOrigin[2]");
	}
};
struct DT_TESparks : public DT_TEParticleSystem
{
	NETVAR_REFLECTION (DT_TESparks, DT_TEParticleSystem);
	inline int &nMagnitude ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TESparks", "m_nMagnitude");
	}
	inline int &nTrailLength ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TESparks", "m_nTrailLength");
	}
	inline Vector &vecDir ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TESparks", "m_vecDir");
	}
};
struct DT_TESmoke : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TESmoke, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TESmoke", "m_vecOrigin");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TESmoke", "m_nModelIndex");
	}
	inline int &fScale ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TESmoke", "m_fScale");
	}
	inline int &nFrameRate ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TESmoke", "m_nFrameRate");
	}
};
struct DT_TEShowLine : public DT_TEParticleSystem
{
	NETVAR_REFLECTION (DT_TEShowLine, DT_TEParticleSystem);
	inline Vector &vecEnd ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEShowLine", "m_vecEnd");
	}
};
struct DT_TEProjectedDecal : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEProjectedDecal, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEProjectedDecal", "m_vecOrigin");
	}
	inline QAngle &angRotation ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_TEProjectedDecal", "m_angRotation");
	}
	inline float &flDistance ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TEProjectedDecal", "m_flDistance");
	}
	inline int &nIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEProjectedDecal", "m_nIndex");
	}
};
struct DT_TEPlayerDecal : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEPlayerDecal, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEPlayerDecal", "m_vecOrigin");
	}
	inline int &nEntity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEPlayerDecal", "m_nEntity");
	}
	inline int &nPlayer ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEPlayerDecal", "m_nPlayer");
	}
};
struct DT_TEPhysicsProp : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEPhysicsProp, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEPhysicsProp", "m_vecOrigin");
	}
	inline QAngle &angRotation0 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_TEPhysicsProp", "m_angRotation[0]");
	}
	inline QAngle &angRotation1 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_TEPhysicsProp", "m_angRotation[1]");
	}
	inline QAngle &angRotation2 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_TEPhysicsProp", "m_angRotation[2]");
	}
	inline Vector &vecVelocity ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEPhysicsProp", "m_vecVelocity");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEPhysicsProp", "m_nModelIndex");
	}
	inline int &nFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEPhysicsProp", "m_nFlags");
	}
	inline int &nSkin ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEPhysicsProp", "m_nSkin");
	}
	inline int &nEffects ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEPhysicsProp", "m_nEffects");
	}
};
struct DT_TEMuzzleFlash : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEMuzzleFlash, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEMuzzleFlash", "m_vecOrigin");
	}
	inline Vector &vecAngles ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEMuzzleFlash", "m_vecAngles");
	}
	inline float &flScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TEMuzzleFlash", "m_flScale");
	}
	inline int &nType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEMuzzleFlash", "m_nType");
	}
};
struct DT_TELargeFunnel : public DT_TEParticleSystem
{
	NETVAR_REFLECTION (DT_TELargeFunnel, DT_TEParticleSystem);
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TELargeFunnel", "m_nModelIndex");
	}
	inline int &nReversed ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TELargeFunnel", "m_nReversed");
	}
};
struct DT_TEKillPlayerAttachments : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEKillPlayerAttachments, DT_BaseTempEntity);
	inline int &nPlayer ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEKillPlayerAttachments", "m_nPlayer");
	}
};
struct DT_TEImpact : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEImpact, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEImpact", "m_vecOrigin");
	}
	inline Vector &vecNormal ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEImpact", "m_vecNormal");
	}
	inline int &iType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEImpact", "m_iType");
	}
	inline int &ucFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEImpact", "m_ucFlags");
	}
};
struct DT_TEGlowSprite : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEGlowSprite, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEGlowSprite", "m_vecOrigin");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEGlowSprite", "m_nModelIndex");
	}
	inline int &fScale ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEGlowSprite", "m_fScale");
	}
	inline int &fLife ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEGlowSprite", "m_fLife");
	}
	inline int &nBrightness ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEGlowSprite", "m_nBrightness");
	}
};
struct DT_TEShatterSurface : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEShatterSurface, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEShatterSurface", "m_vecOrigin");
	}
	inline Vector &vecAngles ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEShatterSurface", "m_vecAngles");
	}
	inline Vector &vecForce ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEShatterSurface", "m_vecForce");
	}
	inline Vector &vecForcePos ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEShatterSurface", "m_vecForcePos");
	}
	inline float &flWidth ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TEShatterSurface", "m_flWidth");
	}
	inline float &flHeight ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TEShatterSurface", "m_flHeight");
	}
	inline float &flShardSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TEShatterSurface", "m_flShardSize");
	}
	inline int &nSurfaceType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEShatterSurface", "m_nSurfaceType");
	}
	inline uchar &uchFrontColor0 ()
	{
		NETVAR_RETURN_THIS (uchar &, "DT_TEShatterSurface", "m_uchFrontColor[0]");
	}
	inline uchar &uchFrontColor1 ()
	{
		NETVAR_RETURN_THIS (uchar &, "DT_TEShatterSurface", "m_uchFrontColor[1]");
	}
	inline uchar &uchFrontColor2 ()
	{
		NETVAR_RETURN_THIS (uchar &, "DT_TEShatterSurface", "m_uchFrontColor[2]");
	}
	inline uchar &uchBackColor0 ()
	{
		NETVAR_RETURN_THIS (uchar &, "DT_TEShatterSurface", "m_uchBackColor[0]");
	}
	inline uchar &uchBackColor1 ()
	{
		NETVAR_RETURN_THIS (uchar &, "DT_TEShatterSurface", "m_uchBackColor[1]");
	}
	inline uchar &uchBackColor2 ()
	{
		NETVAR_RETURN_THIS (uchar &, "DT_TEShatterSurface", "m_uchBackColor[2]");
	}
};
struct DT_TEFootprintDecal : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEFootprintDecal, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEFootprintDecal", "m_vecOrigin");
	}
	inline Vector &vecDirection ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEFootprintDecal", "m_vecDirection");
	}
	inline int &nEntity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEFootprintDecal", "m_nEntity");
	}
	inline int &nIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEFootprintDecal", "m_nIndex");
	}
	inline char &chMaterialType ()
	{
		NETVAR_RETURN_THIS (char &, "DT_TEFootprintDecal", "m_chMaterialType");
	}
};
struct DT_TEFizz : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEFizz, DT_BaseTempEntity);
	inline int &nEntity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEFizz", "m_nEntity");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEFizz", "m_nModelIndex");
	}
	inline int &nDensity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEFizz", "m_nDensity");
	}
	inline int &nCurrent ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEFizz", "m_nCurrent");
	}
};
struct DT_TEExplosion : public DT_TEParticleSystem
{
	NETVAR_REFLECTION (DT_TEExplosion, DT_TEParticleSystem);
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEExplosion", "m_nModelIndex");
	}
	inline int &fScale ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEExplosion", "m_fScale");
	}
	inline int &nFrameRate ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEExplosion", "m_nFrameRate");
	}
	inline int &nFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEExplosion", "m_nFlags");
	}
	inline Vector &vecNormal ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEExplosion", "m_vecNormal");
	}
	inline char &chMaterialType ()
	{
		NETVAR_RETURN_THIS (char &, "DT_TEExplosion", "m_chMaterialType");
	}
	inline int &nRadius ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEExplosion", "m_nRadius");
	}
	inline int &nMagnitude ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEExplosion", "m_nMagnitude");
	}
};
struct DT_TEEnergySplash
{
	NETVAR_REFLECTION_NOBASE (DT_TEEnergySplash);
	inline Vector &vecPos ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEEnergySplash", "m_vecPos");
	}
	inline Vector &vecDir ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEEnergySplash", "m_vecDir");
	}
	inline bool &bExplosive ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TEEnergySplash", "m_bExplosive");
	}
};
struct DT_TEEffectDispatch : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEEffectDispatch, DT_BaseTempEntity);
	struct CEffectData
	{
		NETVAR_REFLECTION (CEffectData, DT_TEEffectDispatch);
		inline float &vOrigin0 ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TEEffectDispatch", "m_EffectData", "m_vOrigin[0]");
		}
		inline float &vOrigin1 ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TEEffectDispatch", "m_EffectData", "m_vOrigin[1]");
		}
		inline float &vOrigin2 ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TEEffectDispatch", "m_EffectData", "m_vOrigin[2]");
		}
		inline float &vStart0 ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TEEffectDispatch", "m_EffectData", "m_vStart[0]");
		}
		inline float &vStart1 ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TEEffectDispatch", "m_EffectData", "m_vStart[1]");
		}
		inline float &vStart2 ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TEEffectDispatch", "m_EffectData", "m_vStart[2]");
		}
		inline Vector &vAngles ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_TEEffectDispatch", "m_EffectData", "m_vAngles");
		}
		inline Vector &vNormal ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_TEEffectDispatch", "m_EffectData", "m_vNormal");
		}
		inline int &fFlags ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TEEffectDispatch", "m_EffectData", "m_fFlags");
		}
		inline float &flMagnitude ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TEEffectDispatch", "m_EffectData", "m_flMagnitude");
		}
		inline float &flScale ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TEEffectDispatch", "m_EffectData", "m_flScale");
		}
		inline int &nAttachmentIndex ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TEEffectDispatch", "m_EffectData", "m_nAttachmentIndex");
		}
		inline int &nSurfaceProp ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TEEffectDispatch", "m_EffectData", "m_nSurfaceProp");
		}
		inline int &iEffectName ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TEEffectDispatch", "m_EffectData", "m_iEffectName");
		}
		inline int &nMaterial ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TEEffectDispatch", "m_EffectData", "m_nMaterial");
		}
		inline int &nDamageType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TEEffectDispatch", "m_EffectData", "m_nDamageType");
		}
		inline int &nHitBox ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TEEffectDispatch", "m_EffectData", "m_nHitBox");
		}
		inline int &entindex ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TEEffectDispatch", "m_EffectData", "entindex");
		}
		inline int &nColor ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TEEffectDispatch", "m_EffectData", "m_nColor");
		}
		inline float &flRadius ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TEEffectDispatch", "m_EffectData", "m_flRadius");
		}
		inline bool &bCustomColors ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TEEffectDispatch", "m_EffectData", "m_bCustomColors");
		}
		inline Vector &CustomColors_m_vecColor1 ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_TEEffectDispatch", "m_EffectData", "m_CustomColors.m_vecColor1");
		}
		inline Vector &CustomColors_m_vecColor2 ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_TEEffectDispatch", "m_EffectData", "m_CustomColors.m_vecColor2");
		}
		inline bool &bControlPoint1 ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_TEEffectDispatch", "m_EffectData", "m_bControlPoint1");
		}
		inline int &ControlPoint1_m_eParticleAttachment ()
		{
			NETVAR_RETURN_THIS (int &, "DT_TEEffectDispatch", "m_EffectData", "m_ControlPoint1.m_eParticleAttachment");
		}
		inline float &ControlPoint1_m_vecOffset0 ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TEEffectDispatch", "m_EffectData", "m_ControlPoint1.m_vecOffset[0]");
		}
		inline float &ControlPoint1_m_vecOffset1 ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TEEffectDispatch", "m_EffectData", "m_ControlPoint1.m_vecOffset[1]");
		}
		inline float &ControlPoint1_m_vecOffset2 ()
		{
			NETVAR_RETURN_THIS (float &, "DT_TEEffectDispatch", "m_EffectData", "m_ControlPoint1.m_vecOffset[2]");
		}
	};
	inline CEffectData &EffectData ()
	{
		NETVAR_RETURN_THIS (CEffectData &, "DT_TEEffectDispatch", "m_EffectData");
	}
};
struct DT_TEDynamicLight : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEDynamicLight, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEDynamicLight", "m_vecOrigin");
	}
	inline int &r ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEDynamicLight", "r");
	}
	inline int &g ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEDynamicLight", "g");
	}
	inline int &b ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEDynamicLight", "b");
	}
	inline int &exponent ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEDynamicLight", "exponent");
	}
	inline int &fRadius ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEDynamicLight", "m_fRadius");
	}
	inline int &fTime ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEDynamicLight", "m_fTime");
	}
	inline int &fDecay ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEDynamicLight", "m_fDecay");
	}
};
struct DT_TEDecal : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEDecal, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEDecal", "m_vecOrigin");
	}
	inline Vector &vecStart ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEDecal", "m_vecStart");
	}
	inline int &nEntity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEDecal", "m_nEntity");
	}
	inline int &nHitbox ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEDecal", "m_nHitbox");
	}
	inline int &nIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEDecal", "m_nIndex");
	}
};
struct DT_TEClientProjectile : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEClientProjectile, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEClientProjectile", "m_vecOrigin");
	}
	inline Vector &vecVelocity ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEClientProjectile", "m_vecVelocity");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEClientProjectile", "m_nModelIndex");
	}
	inline int &nLifeTime ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEClientProjectile", "m_nLifeTime");
	}
	inline EHANDLE &hOwner ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TEClientProjectile", "m_hOwner");
	}
};
struct DT_TEBubbleTrail : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEBubbleTrail, DT_BaseTempEntity);
	inline Vector &vecMins ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBubbleTrail", "m_vecMins");
	}
	inline Vector &vecMaxs ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBubbleTrail", "m_vecMaxs");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBubbleTrail", "m_nModelIndex");
	}
	inline float &flWaterZ ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TEBubbleTrail", "m_flWaterZ");
	}
	inline int &nCount ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBubbleTrail", "m_nCount");
	}
	inline int &fSpeed ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBubbleTrail", "m_fSpeed");
	}
};
struct DT_TEBubbles : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEBubbles, DT_BaseTempEntity);
	inline Vector &vecMins ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBubbles", "m_vecMins");
	}
	inline Vector &vecMaxs ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBubbles", "m_vecMaxs");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBubbles", "m_nModelIndex");
	}
	inline int &fHeight ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBubbles", "m_fHeight");
	}
	inline int &nCount ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBubbles", "m_nCount");
	}
	inline int &fSpeed ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBubbles", "m_fSpeed");
	}
};
struct DT_TEBSPDecal : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEBSPDecal, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBSPDecal", "m_vecOrigin");
	}
	inline int &nEntity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBSPDecal", "m_nEntity");
	}
	inline int &nIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBSPDecal", "m_nIndex");
	}
};
struct DT_TEBreakModel : public DT_BaseTempEntity
{
	NETVAR_REFLECTION (DT_TEBreakModel, DT_BaseTempEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBreakModel", "m_vecOrigin");
	}
	inline QAngle &angRotation0 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_TEBreakModel", "m_angRotation[0]");
	}
	inline QAngle &angRotation1 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_TEBreakModel", "m_angRotation[1]");
	}
	inline QAngle &angRotation2 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_TEBreakModel", "m_angRotation[2]");
	}
	inline Vector &vecSize ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBreakModel", "m_vecSize");
	}
	inline Vector &vecVelocity ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBreakModel", "m_vecVelocity");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBreakModel", "m_nModelIndex");
	}
	inline int &nRandomization ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBreakModel", "m_nRandomization");
	}
	inline int &nCount ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBreakModel", "m_nCount");
	}
	inline int &fTime ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBreakModel", "m_fTime");
	}
	inline int &nFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBreakModel", "m_nFlags");
	}
};
struct DT_TEBloodStream : public DT_TEParticleSystem
{
	NETVAR_REFLECTION (DT_TEBloodStream, DT_TEParticleSystem);
	inline Vector &vecDirection ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBloodStream", "m_vecDirection");
	}
	inline int &r ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBloodStream", "r");
	}
	inline int &g ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBloodStream", "g");
	}
	inline int &b ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBloodStream", "b");
	}
	inline int &a ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBloodStream", "a");
	}
	inline int &nAmount ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBloodStream", "m_nAmount");
	}
};
struct DT_TEBloodSprite
{
	NETVAR_REFLECTION_NOBASE (DT_TEBloodSprite);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBloodSprite", "m_vecOrigin");
	}
	inline Vector &vecDirection ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBloodSprite", "m_vecDirection");
	}
	inline int &r ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBloodSprite", "r");
	}
	inline int &g ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBloodSprite", "g");
	}
	inline int &b ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBloodSprite", "b");
	}
	inline int &a ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBloodSprite", "a");
	}
	inline int &nSprayModel ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBloodSprite", "m_nSprayModel");
	}
	inline int &nDropModel ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBloodSprite", "m_nDropModel");
	}
	inline int &nSize ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBloodSprite", "m_nSize");
	}
};
struct DT_TEBeamSpline
{
	NETVAR_REFLECTION_NOBASE (DT_TEBeamSpline);
	inline int &nPoints ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBeamSpline", "m_nPoints");
	}
	inline Vector &vecPoints0 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBeamSpline", "m_vecPoints[0]");
	}
	inline Vector *vecPoints ()
	{
		NETVAR_RETURN_ARRAY_THIS (Vector *, "DT_TEBeamSpline", "m_vecPoints");
	} // Array size = 16
};
struct DT_BaseBeam
{
	NETVAR_REFLECTION_NOBASE (DT_BaseBeam);
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "m_nModelIndex");
	}
	inline int &nHaloIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "m_nHaloIndex");
	}
	inline int &nStartFrame ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "m_nStartFrame");
	}
	inline int &nFrameRate ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "m_nFrameRate");
	}
	inline int &fLife ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "m_fLife");
	}
	inline int &fWidth ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "m_fWidth");
	}
	inline int &fEndWidth ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "m_fEndWidth");
	}
	inline int &nFadeLength ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "m_nFadeLength");
	}
	inline int &fAmplitude ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "m_fAmplitude");
	}
	inline int &nSpeed ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "m_nSpeed");
	}
	inline int &r ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "r");
	}
	inline int &g ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "g");
	}
	inline int &b ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "b");
	}
	inline int &a ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "a");
	}
	inline int &nFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BaseBeam", "m_nFlags");
	}
};
struct DT_TEBeamRingPoint : public DT_BaseBeam
{
	NETVAR_REFLECTION (DT_TEBeamRingPoint, DT_BaseBeam);
	inline Vector &vecCenter ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBeamRingPoint", "m_vecCenter");
	}
	inline float &flStartRadius ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TEBeamRingPoint", "m_flStartRadius");
	}
	inline float &flEndRadius ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TEBeamRingPoint", "m_flEndRadius");
	}
};
struct DT_TEBeamRing : public DT_BaseBeam
{
	NETVAR_REFLECTION (DT_TEBeamRing, DT_BaseBeam);
	inline int &nStartEntity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBeamRing", "m_nStartEntity");
	}
	inline int &nEndEntity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBeamRing", "m_nEndEntity");
	}
};
struct DT_TEBeamPoints : public DT_BaseBeam
{
	NETVAR_REFLECTION (DT_TEBeamPoints, DT_BaseBeam);
	inline Vector &vecStartPoint ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBeamPoints", "m_vecStartPoint");
	}
	inline Vector &vecEndPoint ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBeamPoints", "m_vecEndPoint");
	}
};
struct DT_TEBeamLaser : public DT_BaseBeam
{
	NETVAR_REFLECTION (DT_TEBeamLaser, DT_BaseBeam);
	inline int &nStartEntity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBeamLaser", "m_nStartEntity");
	}
	inline int &nEndEntity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBeamLaser", "m_nEndEntity");
	}
};
struct DT_TEBeamFollow : public DT_BaseBeam
{
	NETVAR_REFLECTION (DT_TEBeamFollow, DT_BaseBeam);
	inline int &iEntIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBeamFollow", "m_iEntIndex");
	}
};
struct DT_TEBeamEnts : public DT_BaseBeam
{
	NETVAR_REFLECTION (DT_TEBeamEnts, DT_BaseBeam);
	inline int &nStartEntity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBeamEnts", "m_nStartEntity");
	}
	inline int &nEndEntity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBeamEnts", "m_nEndEntity");
	}
};
struct DT_TEBeamEntPoint : public DT_BaseBeam
{
	NETVAR_REFLECTION (DT_TEBeamEntPoint, DT_BaseBeam);
	inline int &nStartEntity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBeamEntPoint", "m_nStartEntity");
	}
	inline int &nEndEntity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEBeamEntPoint", "m_nEndEntity");
	}
	inline Vector &vecStartPoint ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBeamEntPoint", "m_vecStartPoint");
	}
	inline Vector &vecEndPoint ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEBeamEntPoint", "m_vecEndPoint");
	}
};
struct DT_TEMetalSparks
{
	NETVAR_REFLECTION_NOBASE (DT_TEMetalSparks);
	inline Vector &vecPos ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEMetalSparks", "m_vecPos");
	}
	inline Vector &vecDir ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEMetalSparks", "m_vecDir");
	}
};
struct DT_TEArmorRicochet : public DT_TEMetalSparks
{
	NETVAR_REFLECTION (DT_TEArmorRicochet, DT_TEMetalSparks);
};
struct DT_BaseParticleEntity : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_BaseParticleEntity, DT_BaseEntity);
};
struct DT_SteamJet : public DT_BaseParticleEntity
{
	NETVAR_REFLECTION (DT_SteamJet, DT_BaseParticleEntity);
	inline float &SpreadSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SteamJet", "m_SpreadSpeed");
	}
	inline float &Speed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SteamJet", "m_Speed");
	}
	inline float &StartSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SteamJet", "m_StartSize");
	}
	inline float &EndSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SteamJet", "m_EndSize");
	}
	inline float &Rate ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SteamJet", "m_Rate");
	}
	inline float &JetLength ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SteamJet", "m_JetLength");
	}
	inline bool &bEmit ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_SteamJet", "m_bEmit");
	}
	inline bool &bFaceLeft ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_SteamJet", "m_bFaceLeft");
	}
	inline int &nType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_SteamJet", "m_nType");
	}
	inline int &spawnflags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_SteamJet", "m_spawnflags");
	}
	inline float &flRollSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SteamJet", "m_flRollSpeed");
	}
};
struct DT_SmokeStack : public DT_BaseParticleEntity
{
	NETVAR_REFLECTION (DT_SmokeStack, DT_BaseParticleEntity);
	inline float &SpreadSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeStack", "m_SpreadSpeed");
	}
	inline float &Speed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeStack", "m_Speed");
	}
	inline float &StartSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeStack", "m_StartSize");
	}
	inline float &EndSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeStack", "m_EndSize");
	}
	inline float &Rate ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeStack", "m_Rate");
	}
	inline float &JetLength ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeStack", "m_JetLength");
	}
	inline bool &bEmit ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_SmokeStack", "m_bEmit");
	}
	inline float &flBaseSpread ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeStack", "m_flBaseSpread");
	}
	inline float &flTwist ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeStack", "m_flTwist");
	}
	inline float &flRollSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeStack", "m_flRollSpeed");
	}
	inline int &iMaterialModel ()
	{
		NETVAR_RETURN_THIS (int &, "DT_SmokeStack", "m_iMaterialModel");
	}
	inline Vector &AmbientLight_m_vPos ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_SmokeStack", "m_AmbientLight.m_vPos");
	}
	inline Vector &AmbientLight_m_vColor ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_SmokeStack", "m_AmbientLight.m_vColor");
	}
	inline float &AmbientLight_m_flIntensity ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeStack", "m_AmbientLight.m_flIntensity");
	}
	inline Vector &DirLight_m_vPos ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_SmokeStack", "m_DirLight.m_vPos");
	}
	inline Vector &DirLight_m_vColor ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_SmokeStack", "m_DirLight.m_vColor");
	}
	inline float &DirLight_m_flIntensity ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeStack", "m_DirLight.m_flIntensity");
	}
	inline Vector &vWind ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_SmokeStack", "m_vWind");
	}
};
struct DT_DustTrail : public DT_BaseParticleEntity
{
	NETVAR_REFLECTION (DT_DustTrail, DT_BaseParticleEntity);
	inline float &SpawnRate ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DustTrail", "m_SpawnRate");
	}
	inline Vector &Color ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_DustTrail", "m_Color");
	}
	inline float &ParticleLifetime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DustTrail", "m_ParticleLifetime");
	}
	inline float &StopEmitTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DustTrail", "m_StopEmitTime");
	}
	inline float &MinSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DustTrail", "m_MinSpeed");
	}
	inline float &MaxSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DustTrail", "m_MaxSpeed");
	}
	inline float &MinDirectedSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DustTrail", "m_MinDirectedSpeed");
	}
	inline float &MaxDirectedSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DustTrail", "m_MaxDirectedSpeed");
	}
	inline float &StartSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DustTrail", "m_StartSize");
	}
	inline float &EndSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DustTrail", "m_EndSize");
	}
	inline float &SpawnRadius ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DustTrail", "m_SpawnRadius");
	}
	inline bool &bEmit ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_DustTrail", "m_bEmit");
	}
	inline float &Opacity ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DustTrail", "m_Opacity");
	}
};
struct DT_FireTrail : public DT_BaseParticleEntity
{
	NETVAR_REFLECTION (DT_FireTrail, DT_BaseParticleEntity);
	inline int &nAttachment ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FireTrail", "m_nAttachment");
	}
	inline float &flLifetime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FireTrail", "m_flLifetime");
	}
};
struct DT_SporeTrail : public DT_BaseParticleEntity
{
	NETVAR_REFLECTION (DT_SporeTrail, DT_BaseParticleEntity);
	inline float &flSpawnRate ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SporeTrail", "m_flSpawnRate");
	}
	inline Vector &vecEndColor ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_SporeTrail", "m_vecEndColor");
	}
	inline float &flParticleLifetime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SporeTrail", "m_flParticleLifetime");
	}
	inline float &flStartSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SporeTrail", "m_flStartSize");
	}
	inline float &flEndSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SporeTrail", "m_flEndSize");
	}
	inline float &flSpawnRadius ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SporeTrail", "m_flSpawnRadius");
	}
	inline bool &bEmit ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_SporeTrail", "m_bEmit");
	}
};
struct DT_SporeExplosion : public DT_BaseParticleEntity
{
	NETVAR_REFLECTION (DT_SporeExplosion, DT_BaseParticleEntity);
	inline float &flSpawnRate ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SporeExplosion", "m_flSpawnRate");
	}
	inline float &flParticleLifetime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SporeExplosion", "m_flParticleLifetime");
	}
	inline float &flStartSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SporeExplosion", "m_flStartSize");
	}
	inline float &flEndSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SporeExplosion", "m_flEndSize");
	}
	inline float &flSpawnRadius ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SporeExplosion", "m_flSpawnRadius");
	}
	inline bool &bEmit ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_SporeExplosion", "m_bEmit");
	}
	inline bool &bDontRemove ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_SporeExplosion", "m_bDontRemove");
	}
};
struct DT_RocketTrail : public DT_BaseParticleEntity
{
	NETVAR_REFLECTION (DT_RocketTrail, DT_BaseParticleEntity);
	inline float &SpawnRate ()
	{
		NETVAR_RETURN_THIS (float &, "DT_RocketTrail", "m_SpawnRate");
	}
	inline Vector &StartColor ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_RocketTrail", "m_StartColor");
	}
	inline Vector &EndColor ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_RocketTrail", "m_EndColor");
	}
	inline float &ParticleLifetime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_RocketTrail", "m_ParticleLifetime");
	}
	inline float &StopEmitTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_RocketTrail", "m_StopEmitTime");
	}
	inline float &MinSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_RocketTrail", "m_MinSpeed");
	}
	inline float &MaxSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_RocketTrail", "m_MaxSpeed");
	}
	inline float &StartSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_RocketTrail", "m_StartSize");
	}
	inline float &EndSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_RocketTrail", "m_EndSize");
	}
	inline float &SpawnRadius ()
	{
		NETVAR_RETURN_THIS (float &, "DT_RocketTrail", "m_SpawnRadius");
	}
	inline bool &bEmit ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_RocketTrail", "m_bEmit");
	}
	inline int &nAttachment ()
	{
		NETVAR_RETURN_THIS (int &, "DT_RocketTrail", "m_nAttachment");
	}
	inline float &Opacity ()
	{
		NETVAR_RETURN_THIS (float &, "DT_RocketTrail", "m_Opacity");
	}
	inline bool &bDamaged ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_RocketTrail", "m_bDamaged");
	}
	inline float &flFlareScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_RocketTrail", "m_flFlareScale");
	}
};
struct DT_SmokeTrail : public DT_BaseParticleEntity
{
	NETVAR_REFLECTION (DT_SmokeTrail, DT_BaseParticleEntity);
	inline float &SpawnRate ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeTrail", "m_SpawnRate");
	}
	inline Vector &StartColor ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_SmokeTrail", "m_StartColor");
	}
	inline Vector &EndColor ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_SmokeTrail", "m_EndColor");
	}
	inline float &ParticleLifetime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeTrail", "m_ParticleLifetime");
	}
	inline float &StopEmitTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeTrail", "m_StopEmitTime");
	}
	inline float &MinSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeTrail", "m_MinSpeed");
	}
	inline float &MaxSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeTrail", "m_MaxSpeed");
	}
	inline float &MinDirectedSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeTrail", "m_MinDirectedSpeed");
	}
	inline float &MaxDirectedSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeTrail", "m_MaxDirectedSpeed");
	}
	inline float &StartSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeTrail", "m_StartSize");
	}
	inline float &EndSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeTrail", "m_EndSize");
	}
	inline float &SpawnRadius ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeTrail", "m_SpawnRadius");
	}
	inline bool &bEmit ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_SmokeTrail", "m_bEmit");
	}
	inline int &nAttachment ()
	{
		NETVAR_RETURN_THIS (int &, "DT_SmokeTrail", "m_nAttachment");
	}
	inline float &Opacity ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SmokeTrail", "m_Opacity");
	}
};
struct DT_PropVehicleDriveable : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_PropVehicleDriveable, DT_BaseAnimating);
	inline EHANDLE &hPlayer ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_PropVehicleDriveable", "m_hPlayer");
	}
	inline int &nSpeed ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PropVehicleDriveable", "m_nSpeed");
	}
	inline int &nRPM ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PropVehicleDriveable", "m_nRPM");
	}
	inline float &flThrottle ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PropVehicleDriveable", "m_flThrottle");
	}
	inline int &nBoostTimeLeft ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PropVehicleDriveable", "m_nBoostTimeLeft");
	}
	inline int &nHasBoost ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PropVehicleDriveable", "m_nHasBoost");
	}
	inline int &nScannerDisabledWeapons ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PropVehicleDriveable", "m_nScannerDisabledWeapons");
	}
	inline int &nScannerDisabledVehicle ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PropVehicleDriveable", "m_nScannerDisabledVehicle");
	}
	inline bool &bEnterAnimOn ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PropVehicleDriveable", "m_bEnterAnimOn");
	}
	inline bool &bExitAnimOn ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PropVehicleDriveable", "m_bExitAnimOn");
	}
	inline bool &bUnableToFire ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PropVehicleDriveable", "m_bUnableToFire");
	}
	inline Vector &vecEyeExitEndpoint ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_PropVehicleDriveable", "m_vecEyeExitEndpoint");
	}
	inline bool &bHasGun ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PropVehicleDriveable", "m_bHasGun");
	}
	inline Vector &vecGunCrosshair ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_PropVehicleDriveable", "m_vecGunCrosshair");
	}
};
struct DT_ParticleSmokeGrenade : public DT_BaseParticleEntity
{
	NETVAR_REFLECTION (DT_ParticleSmokeGrenade, DT_BaseParticleEntity);
	inline float &flSpawnTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_ParticleSmokeGrenade", "m_flSpawnTime");
	}
	inline float &FadeStartTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_ParticleSmokeGrenade", "m_FadeStartTime");
	}
	inline float &FadeEndTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_ParticleSmokeGrenade", "m_FadeEndTime");
	}
	inline int &CurrentStage ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ParticleSmokeGrenade", "m_CurrentStage");
	}
};
struct DT_ParticleFire
{
	NETVAR_REFLECTION_NOBASE (DT_ParticleFire);
	inline Vector &vOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_ParticleFire", "m_vOrigin");
	}
	inline Vector &vDirection ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_ParticleFire", "m_vDirection");
	}
};
struct DT_MovieExplosion : public DT_BaseParticleEntity
{
	NETVAR_REFLECTION (DT_MovieExplosion, DT_BaseParticleEntity);
};
struct DT_TEGaussExplosion : public DT_TEParticleSystem
{
	NETVAR_REFLECTION (DT_TEGaussExplosion, DT_TEParticleSystem);
	inline int &nType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TEGaussExplosion", "m_nType");
	}
	inline Vector &vecDirection ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEGaussExplosion", "m_vecDirection");
	}
};
struct DT_QuadraticBeam : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_QuadraticBeam, DT_BaseEntity);
	inline Vector &targetPosition ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_QuadraticBeam", "m_targetPosition");
	}
	inline Vector &controlPosition ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_QuadraticBeam", "m_controlPosition");
	}
	inline float &scrollRate ()
	{
		NETVAR_RETURN_THIS (float &, "DT_QuadraticBeam", "m_scrollRate");
	}
	inline float &flWidth ()
	{
		NETVAR_RETURN_THIS (float &, "DT_QuadraticBeam", "m_flWidth");
	}
};
struct DT_Embers : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_Embers, DT_BaseEntity);
	inline int &nDensity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Embers", "m_nDensity");
	}
	inline int &nLifetime ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Embers", "m_nLifetime");
	}
	inline int &nSpeed ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Embers", "m_nSpeed");
	}
	inline bool &bEmit ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_Embers", "m_bEmit");
	}
};
struct DT_EnvWind : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_EnvWind, DT_BaseEntity);
	struct CEnvWindShared
	{
		NETVAR_REFLECTION (CEnvWindShared, DT_EnvWind);
		inline int &iMinWind ()
		{
			NETVAR_RETURN_THIS (int &, "DT_EnvWind", "m_EnvWindShared", "m_iMinWind");
		}
		inline int &iMaxWind ()
		{
			NETVAR_RETURN_THIS (int &, "DT_EnvWind", "m_EnvWindShared", "m_iMaxWind");
		}
		inline int &iMinGust ()
		{
			NETVAR_RETURN_THIS (int &, "DT_EnvWind", "m_EnvWindShared", "m_iMinGust");
		}
		inline int &iMaxGust ()
		{
			NETVAR_RETURN_THIS (int &, "DT_EnvWind", "m_EnvWindShared", "m_iMaxGust");
		}
		inline float &flMinGustDelay ()
		{
			NETVAR_RETURN_THIS (float &, "DT_EnvWind", "m_EnvWindShared", "m_flMinGustDelay");
		}
		inline float &flMaxGustDelay ()
		{
			NETVAR_RETURN_THIS (float &, "DT_EnvWind", "m_EnvWindShared", "m_flMaxGustDelay");
		}
		inline int &iGustDirChange ()
		{
			NETVAR_RETURN_THIS (int &, "DT_EnvWind", "m_EnvWindShared", "m_iGustDirChange");
		}
		inline int &iWindSeed ()
		{
			NETVAR_RETURN_THIS (int &, "DT_EnvWind", "m_EnvWindShared", "m_iWindSeed");
		}
		inline int &iInitialWindDir ()
		{
			NETVAR_RETURN_THIS (int &, "DT_EnvWind", "m_EnvWindShared", "m_iInitialWindDir");
		}
		inline float &flInitialWindSpeed ()
		{
			NETVAR_RETURN_THIS (float &, "DT_EnvWind", "m_EnvWindShared", "m_flInitialWindSpeed");
		}
		inline float &flStartTime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_EnvWind", "m_EnvWindShared", "m_flStartTime");
		}
		inline float &flGustDuration ()
		{
			NETVAR_RETURN_THIS (float &, "DT_EnvWind", "m_EnvWindShared", "m_flGustDuration");
		}
	};
	inline CEnvWindShared &EnvWindShared ()
	{
		NETVAR_RETURN_THIS (CEnvWindShared &, "DT_EnvWind", "m_EnvWindShared");
	}
};
struct DT_Precipitation : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_Precipitation, DT_BaseEntity);
	inline int &nPrecipType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Precipitation", "m_nPrecipType");
	}
};
struct DT_WeaponIFMBase : public DT_TFWeaponBase
{
	NETVAR_REFLECTION (DT_WeaponIFMBase, DT_TFWeaponBase);
};
struct DT_WeaponIFMBaseCamera : public DT_WeaponIFMBase
{
	NETVAR_REFLECTION (DT_WeaponIFMBaseCamera, DT_WeaponIFMBase);
	inline float &flRenderAspectRatio ()
	{
		NETVAR_RETURN_THIS (float &, "DT_WeaponIFMBaseCamera", "m_flRenderAspectRatio");
	}
	inline float &flRenderFOV ()
	{
		NETVAR_RETURN_THIS (float &, "DT_WeaponIFMBaseCamera", "m_flRenderFOV");
	}
	inline float &flRenderArmLength ()
	{
		NETVAR_RETURN_THIS (float &, "DT_WeaponIFMBaseCamera", "m_flRenderArmLength");
	}
	inline Vector &vecRenderPosition ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_WeaponIFMBaseCamera", "m_vecRenderPosition");
	}
	inline QAngle &angRenderAngles ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_WeaponIFMBaseCamera", "m_angRenderAngles");
	}
};
struct DT_WeaponIFMSteadyCam : public DT_WeaponIFMBaseCamera
{
	NETVAR_REFLECTION (DT_WeaponIFMSteadyCam, DT_WeaponIFMBaseCamera);
};
struct DT_TFWearableVM : public DT_TFWearable
{
	NETVAR_REFLECTION (DT_TFWearableVM, DT_TFWearable);
};
struct DT_TFWearableItem : public DT_WearableItem
{
	NETVAR_REFLECTION (DT_TFWearableItem, DT_WearableItem);
};
struct DT_BaseAttributableItem : public DT_EconEntity
{
	NETVAR_REFLECTION (DT_BaseAttributableItem, DT_EconEntity);
	inline CAttributeContainer &AttributeManager ()
	{
		NETVAR_RETURN_THIS (CAttributeContainer &, "DT_BaseAttributableItem", "m_AttributeManager");
	}
};
struct DT_HandleTest : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_HandleTest, DT_BaseEntity);
	inline int &Handle ()
	{
		NETVAR_RETURN_THIS (int &, "DT_HandleTest", "m_Handle");
	}
	inline bool &bSendHandle ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_HandleTest", "m_bSendHandle");
	}
};
struct DT_TeamRoundTimer
{
	NETVAR_REFLECTION_NOBASE (DT_TeamRoundTimer);
	inline bool &bTimerPaused ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TeamRoundTimer", "m_bTimerPaused");
	}
	inline float &flTimeRemaining ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TeamRoundTimer", "m_flTimeRemaining");
	}
	inline float &flTimerEndTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TeamRoundTimer", "m_flTimerEndTime");
	}
	inline int &nTimerMaxLength ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TeamRoundTimer", "m_nTimerMaxLength");
	}
	inline bool &bIsDisabled ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TeamRoundTimer", "m_bIsDisabled");
	}
	inline bool &bShowInHUD ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TeamRoundTimer", "m_bShowInHUD");
	}
	inline int &nTimerLength ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TeamRoundTimer", "m_nTimerLength");
	}
	inline int &nTimerInitialLength ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TeamRoundTimer", "m_nTimerInitialLength");
	}
	inline bool &bAutoCountdown ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TeamRoundTimer", "m_bAutoCountdown");
	}
	inline int &nSetupTimeLength ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TeamRoundTimer", "m_nSetupTimeLength");
	}
	inline int &nState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TeamRoundTimer", "m_nState");
	}
	inline bool &bStartPaused ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TeamRoundTimer", "m_bStartPaused");
	}
	inline bool &bShowTimeRemaining ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TeamRoundTimer", "m_bShowTimeRemaining");
	}
	inline bool &bInCaptureWatchState ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TeamRoundTimer", "m_bInCaptureWatchState");
	}
	inline bool &bStopWatchTimer ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_TeamRoundTimer", "m_bStopWatchTimer");
	}
	inline float &flTotalTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TeamRoundTimer", "m_flTotalTime");
	}
};
struct DT_Sprite : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_Sprite, DT_BaseEntity);
	inline EHANDLE &hAttachedToEntity ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_Sprite", "m_hAttachedToEntity");
	}
	inline int &nAttachment ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Sprite", "m_nAttachment");
	}
	inline float &flScaleTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Sprite", "m_flScaleTime");
	}
	inline float &flSpriteScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Sprite", "m_flSpriteScale");
	}
	inline float &flSpriteFramerate ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Sprite", "m_flSpriteFramerate");
	}
	inline float &flGlowProxySize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Sprite", "m_flGlowProxySize");
	}
	inline float &flHDRColorScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Sprite", "m_flHDRColorScale");
	}
	inline float &flFrame ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Sprite", "m_flFrame");
	}
	inline float &flBrightnessTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Sprite", "m_flBrightnessTime");
	}
	inline int &nBrightness ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Sprite", "m_nBrightness");
	}
	inline bool &bWorldSpaceScale ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_Sprite", "m_bWorldSpaceScale");
	}
};
struct DT_SpriteTrail : public DT_Sprite
{
	NETVAR_REFLECTION (DT_SpriteTrail, DT_Sprite);
	inline float &flLifeTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SpriteTrail", "m_flLifeTime");
	}
	inline float &flStartWidth ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SpriteTrail", "m_flStartWidth");
	}
	inline float &flEndWidth ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SpriteTrail", "m_flEndWidth");
	}
	inline float &flStartWidthVariance ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SpriteTrail", "m_flStartWidthVariance");
	}
	inline float &flTextureRes ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SpriteTrail", "m_flTextureRes");
	}
	inline float &flMinFadeLength ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SpriteTrail", "m_flMinFadeLength");
	}
	inline Vector &vecSkyboxOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_SpriteTrail", "m_vecSkyboxOrigin");
	}
	inline float &flSkyboxScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SpriteTrail", "m_flSkyboxScale");
	}
};
struct DT_SpriteOriented : public DT_Sprite
{
	NETVAR_REFLECTION (DT_SpriteOriented, DT_Sprite);
};
struct DT_Ragdoll : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_Ragdoll, DT_BaseAnimating);
	inline Vector &ragAngles0 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_Ragdoll", "m_ragAngles[0]");
	}
	inline Vector &ragPos0 ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_Ragdoll", "m_ragPos[0]");
	}
	inline EHANDLE &hUnragdoll ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_Ragdoll", "m_hUnragdoll");
	}
	inline float &flBlendWeight ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Ragdoll", "m_flBlendWeight");
	}
	inline int &nOverlaySequence ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Ragdoll", "m_nOverlaySequence");
	}
}; // Fail count = 2
struct DT_Ragdoll_Attached : public DT_Ragdoll
{
	NETVAR_REFLECTION (DT_Ragdoll_Attached, DT_Ragdoll);
	inline bool &boneIndexAttached ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_Ragdoll_Attached", "m_boneIndexAttached");
	}
	inline int &ragdollAttachedObjectIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Ragdoll_Attached", "m_ragdollAttachedObjectIndex");
	}
	inline Vector &attachmentPointBoneSpace ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_Ragdoll_Attached", "m_attachmentPointBoneSpace");
	}
	inline Vector &attachmentPointRagdollSpace ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_Ragdoll_Attached", "m_attachmentPointRagdollSpace");
	}
};
struct DT_PoseController : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_PoseController, DT_BaseEntity);
	inline EHANDLE *hProps ()
	{
		NETVAR_RETURN_ARRAY_THIS (EHANDLE *, "DT_PoseController", "m_hProps");
	} // Array size = 4
	inline char *chPoseIndex ()
	{
		NETVAR_RETURN_ARRAY_THIS (char *, "DT_PoseController", "m_chPoseIndex");
	} // Array size = 4
	inline bool &bPoseValueParity ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PoseController", "m_bPoseValueParity");
	}
	inline int &fPoseValue ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PoseController", "m_fPoseValue");
	}
	inline int &fInterpolationTime ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PoseController", "m_fInterpolationTime");
	}
	inline bool &bInterpolationWrap ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PoseController", "m_bInterpolationWrap");
	}
	inline int &fCycleFrequency ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PoseController", "m_fCycleFrequency");
	}
	inline int &nFModType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PoseController", "m_nFModType");
	}
	inline int &fFModTimeOffset ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PoseController", "m_fFModTimeOffset");
	}
	inline int &fFModRate ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PoseController", "m_fFModRate");
	}
	inline int &fFModAmplitude ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PoseController", "m_fFModAmplitude");
	}
};
struct DT_InfoLadderDismount : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_InfoLadderDismount, DT_BaseEntity);
};
struct DT_FuncLadder : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_FuncLadder, DT_BaseEntity);
	inline Vector &vecPlayerMountPositionTop ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_FuncLadder", "m_vecPlayerMountPositionTop");
	}
	inline Vector &vecPlayerMountPositionBottom ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_FuncLadder", "m_vecPlayerMountPositionBottom");
	}
	inline Vector &vecLadderDir ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_FuncLadder", "m_vecLadderDir");
	}
	inline bool &bFakeLadder ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_FuncLadder", "m_bFakeLadder");
	}
};
struct DT_DetailController
{
	NETVAR_REFLECTION_NOBASE (DT_DetailController);
	inline float &flFadeStartDist ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DetailController", "m_flFadeStartDist");
	}
	inline float &flFadeEndDist ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DetailController", "m_flFadeEndDist");
	}
};
struct DT_World : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_World, DT_BaseEntity);
	inline float &flWaveHeight ()
	{
		NETVAR_RETURN_THIS (float &, "DT_World", "m_flWaveHeight");
	}
	inline Vector &WorldMins ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_World", "m_WorldMins");
	}
	inline Vector &WorldMaxs ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_World", "m_WorldMaxs");
	}
	inline bool &bStartDark ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_World", "m_bStartDark");
	}
	inline float &flMaxOccludeeArea ()
	{
		NETVAR_RETURN_THIS (float &, "DT_World", "m_flMaxOccludeeArea");
	}
	inline float &flMinOccluderArea ()
	{
		NETVAR_RETURN_THIS (float &, "DT_World", "m_flMinOccluderArea");
	}
	inline float &flMaxPropScreenSpaceWidth ()
	{
		NETVAR_RETURN_THIS (float &, "DT_World", "m_flMaxPropScreenSpaceWidth");
	}
	inline float &flMinPropScreenSpaceWidth ()
	{
		NETVAR_RETURN_THIS (float &, "DT_World", "m_flMinPropScreenSpaceWidth");
	}
	inline int &iszDetailSpriteMaterial ()
	{
		NETVAR_RETURN_THIS (int &, "DT_World", "m_iszDetailSpriteMaterial");
	}
	inline bool &bColdWorld ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_World", "m_bColdWorld");
	}
};
struct DT_WaterLODControl : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_WaterLODControl, DT_BaseEntity);
	inline float &flCheapWaterStartDistance ()
	{
		NETVAR_RETURN_THIS (float &, "DT_WaterLODControl", "m_flCheapWaterStartDistance");
	}
	inline float &flCheapWaterEndDistance ()
	{
		NETVAR_RETURN_THIS (float &, "DT_WaterLODControl", "m_flCheapWaterEndDistance");
	}
};
struct DT_WaterBullet : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_WaterBullet, DT_BaseAnimating);
};
struct DT_VoteController : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_VoteController, DT_BaseEntity);
	inline int &iActiveIssueIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_VoteController", "m_iActiveIssueIndex");
	}
	inline int &iOnlyTeamToVote ()
	{
		NETVAR_RETURN_THIS (int &, "DT_VoteController", "m_iOnlyTeamToVote");
	}
	inline int *nVoteOptionCount ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_VoteController", "m_nVoteOptionCount");
	} // Array size = 5
	inline int &nPotentialVotes ()
	{
		NETVAR_RETURN_THIS (int &, "DT_VoteController", "m_nPotentialVotes");
	}
	inline bool &bIsYesNoVote ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_VoteController", "m_bIsYesNoVote");
	}
};
struct DT_VGuiScreen : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_VGuiScreen, DT_BaseEntity);
	inline float &flWidth ()
	{
		NETVAR_RETURN_THIS (float &, "DT_VGuiScreen", "m_flWidth");
	}
	inline float &flHeight ()
	{
		NETVAR_RETURN_THIS (float &, "DT_VGuiScreen", "m_flHeight");
	}
	inline int &fScreenFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_VGuiScreen", "m_fScreenFlags");
	}
	inline int &nPanelName ()
	{
		NETVAR_RETURN_THIS (int &, "DT_VGuiScreen", "m_nPanelName");
	}
	inline int &nAttachmentIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_VGuiScreen", "m_nAttachmentIndex");
	}
	inline int &nOverlayMaterial ()
	{
		NETVAR_RETURN_THIS (int &, "DT_VGuiScreen", "m_nOverlayMaterial");
	}
	inline EHANDLE &hPlayerOwner ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_VGuiScreen", "m_hPlayerOwner");
	}
};
struct DT_PropJeep : public DT_PropVehicleDriveable
{
	NETVAR_REFLECTION (DT_PropJeep, DT_PropVehicleDriveable);
	inline bool &bHeadlightIsOn ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PropJeep", "m_bHeadlightIsOn");
	}
};
struct DT_PropVehicleChoreoGeneric : public DT_DynamicProp
{
	NETVAR_REFLECTION (DT_PropVehicleChoreoGeneric, DT_DynamicProp);
	inline EHANDLE &hPlayer ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_PropVehicleChoreoGeneric", "m_hPlayer");
	}
	inline bool &bEnterAnimOn ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PropVehicleChoreoGeneric", "m_bEnterAnimOn");
	}
	inline bool &bExitAnimOn ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PropVehicleChoreoGeneric", "m_bExitAnimOn");
	}
	inline Vector &vecEyeExitEndpoint ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_PropVehicleChoreoGeneric", "m_vecEyeExitEndpoint");
	}
	inline int &vehicleView_bClampEyeAngles ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PropVehicleChoreoGeneric", "m_vehicleView.bClampEyeAngles");
	}
	inline float &vehicleView_flPitchCurveZero ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PropVehicleChoreoGeneric", "m_vehicleView.flPitchCurveZero");
	}
	inline float &vehicleView_flPitchCurveLinear ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PropVehicleChoreoGeneric", "m_vehicleView.flPitchCurveLinear");
	}
	inline float &vehicleView_flRollCurveZero ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PropVehicleChoreoGeneric", "m_vehicleView.flRollCurveZero");
	}
	inline float &vehicleView_flRollCurveLinear ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PropVehicleChoreoGeneric", "m_vehicleView.flRollCurveLinear");
	}
	inline float &vehicleView_flFOV ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PropVehicleChoreoGeneric", "m_vehicleView.flFOV");
	}
	inline float &vehicleView_flYawMin ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PropVehicleChoreoGeneric", "m_vehicleView.flYawMin");
	}
	inline float &vehicleView_flYawMax ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PropVehicleChoreoGeneric", "m_vehicleView.flYawMax");
	}
	inline float &vehicleView_flPitchMin ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PropVehicleChoreoGeneric", "m_vehicleView.flPitchMin");
	}
	inline float &vehicleView_flPitchMax ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PropVehicleChoreoGeneric", "m_vehicleView.flPitchMax");
	}
};
struct DT_ProxyToggle : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_ProxyToggle, DT_BaseEntity);
	struct CProxyToggle_ProxiedData
	{
		NETVAR_REFLECTION (CProxyToggle_ProxiedData, DT_ProxyToggle);
		inline int &WithProxy ()
		{
			NETVAR_RETURN_THIS (int &, "DT_ProxyToggle", "blah", "m_WithProxy");
		}
	};
	inline CProxyToggle_ProxiedData &blah ()
	{
		NETVAR_RETURN_THIS (CProxyToggle_ProxiedData &, "DT_ProxyToggle", "blah");
	}
};
struct DT_Tesla : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_Tesla, DT_BaseEntity);
	inline int &iszSpriteName ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Tesla", "m_iszSpriteName");
	}
}; // Fail count = 1
struct DT_TeamTrainWatcher : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_TeamTrainWatcher, DT_BaseEntity);
	inline float &flTotalProgress ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TeamTrainWatcher", "m_flTotalProgress");
	}
	inline int &iTrainSpeedLevel ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TeamTrainWatcher", "m_iTrainSpeedLevel");
	}
	inline float &flRecedeTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TeamTrainWatcher", "m_flRecedeTime");
	}
	inline int &nNumCappers ()
	{
		NETVAR_RETURN_THIS (int &, "DT_TeamTrainWatcher", "m_nNumCappers");
	}
	inline EHANDLE &hGlowEnt ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_TeamTrainWatcher", "m_hGlowEnt");
	}
};
struct DT_Sun
{
	NETVAR_REFLECTION_NOBASE (DT_Sun);
	inline int &clrRender ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Sun", "m_clrRender");
	}
	inline int &clrOverlay ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Sun", "m_clrOverlay");
	}
	inline Vector &vDirection ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_Sun", "m_vDirection");
	}
	inline bool &bOn ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_Sun", "m_bOn");
	}
	inline int &nSize ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Sun", "m_nSize");
	}
	inline int &nOverlaySize ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Sun", "m_nOverlaySize");
	}
	inline int &nMaterial ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Sun", "m_nMaterial");
	}
	inline int &nOverlayMaterial ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Sun", "m_nOverlayMaterial");
	}
	inline float &HDRColorScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Sun", "HDRColorScale");
	}
};
struct DT_ParticlePerformanceMonitor : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_ParticlePerformanceMonitor, DT_BaseEntity);
	inline bool &bMeasurePerf ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_ParticlePerformanceMonitor", "m_bMeasurePerf");
	}
	inline bool &bDisplayPerf ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_ParticlePerformanceMonitor", "m_bDisplayPerf");
	}
};
struct DT_SpotlightEnd : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_SpotlightEnd, DT_BaseEntity);
	inline float &flLightScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SpotlightEnd", "m_flLightScale");
	}
	inline float &Radius ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SpotlightEnd", "m_Radius");
	}
};
struct DT_SlideshowDisplay : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_SlideshowDisplay, DT_BaseEntity);
	inline bool &bEnabled ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_SlideshowDisplay", "m_bEnabled");
	}
	inline char *&szDisplayText ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_SlideshowDisplay", "m_szDisplayText");
	}
	inline char *&szSlideshowDirectory ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_SlideshowDisplay", "m_szSlideshowDirectory");
	}
	inline char *chCurrentSlideLists ()
	{
		NETVAR_RETURN_ARRAY_THIS (char *, "DT_SlideshowDisplay", "m_chCurrentSlideLists");
	} // Array size = 16
	inline int &fMinSlideTime ()
	{
		NETVAR_RETURN_THIS (int &, "DT_SlideshowDisplay", "m_fMinSlideTime");
	}
	inline int &fMaxSlideTime ()
	{
		NETVAR_RETURN_THIS (int &, "DT_SlideshowDisplay", "m_fMaxSlideTime");
	}
	inline int &iCycleType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_SlideshowDisplay", "m_iCycleType");
	}
	inline bool &bNoListRepeats ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_SlideshowDisplay", "m_bNoListRepeats");
	}
};
struct DT_ShadowControl : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_ShadowControl, DT_BaseEntity);
	inline Vector &shadowDirection ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_ShadowControl", "m_shadowDirection");
	}
	inline int &shadowColor ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ShadowControl", "m_shadowColor");
	}
	inline float &flShadowMaxDist ()
	{
		NETVAR_RETURN_THIS (float &, "DT_ShadowControl", "m_flShadowMaxDist");
	}
	inline bool &bDisableShadows ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_ShadowControl", "m_bDisableShadows");
	}
};
struct DT_SceneEntity : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_SceneEntity, DT_BaseEntity);
	inline int &nSceneStringIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_SceneEntity", "m_nSceneStringIndex");
	}
	inline bool &bIsPlayingBack ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_SceneEntity", "m_bIsPlayingBack");
	}
	inline bool &bPaused ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_SceneEntity", "m_bPaused");
	}
	inline bool &bMultiplayer ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_SceneEntity", "m_bMultiplayer");
	}
	inline float &flForceClientTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_SceneEntity", "m_flForceClientTime");
	}
	inline EHANDLE *hActorList ()
	{
		NETVAR_RETURN_ARRAY_THIS (EHANDLE *, "DT_SceneEntity", "m_hActorList");
	} // Array size = 17
};
struct DT_RopeKeyframe
{
	NETVAR_REFLECTION_NOBASE (DT_RopeKeyframe);
	inline int &iRopeMaterialModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_RopeKeyframe", "m_iRopeMaterialModelIndex");
	}
	inline EHANDLE &hStartPoint ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_RopeKeyframe", "m_hStartPoint");
	}
	inline EHANDLE &hEndPoint ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_RopeKeyframe", "m_hEndPoint");
	}
	inline int &iStartAttachment ()
	{
		NETVAR_RETURN_THIS (int &, "DT_RopeKeyframe", "m_iStartAttachment");
	}
	inline int &iEndAttachment ()
	{
		NETVAR_RETURN_THIS (int &, "DT_RopeKeyframe", "m_iEndAttachment");
	}
	inline int &fLockedPoints ()
	{
		NETVAR_RETURN_THIS (int &, "DT_RopeKeyframe", "m_fLockedPoints");
	}
	inline int &Slack ()
	{
		NETVAR_RETURN_THIS (int &, "DT_RopeKeyframe", "m_Slack");
	}
	inline int &RopeLength ()
	{
		NETVAR_RETURN_THIS (int &, "DT_RopeKeyframe", "m_RopeLength");
	}
	inline int &RopeFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_RopeKeyframe", "m_RopeFlags");
	}
	inline float &TextureScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_RopeKeyframe", "m_TextureScale");
	}
	inline int &nSegments ()
	{
		NETVAR_RETURN_THIS (int &, "DT_RopeKeyframe", "m_nSegments");
	}
	inline bool &bConstrainBetweenEndpoints ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_RopeKeyframe", "m_bConstrainBetweenEndpoints");
	}
	inline int &Subdiv ()
	{
		NETVAR_RETURN_THIS (int &, "DT_RopeKeyframe", "m_Subdiv");
	}
	inline float &Width ()
	{
		NETVAR_RETURN_THIS (float &, "DT_RopeKeyframe", "m_Width");
	}
	inline float &flScrollSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_RopeKeyframe", "m_flScrollSpeed");
	}
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_RopeKeyframe", "m_vecOrigin");
	}
	inline int &moveparent ()
	{
		NETVAR_RETURN_THIS (int &, "DT_RopeKeyframe", "moveparent");
	}
	inline int &iParentAttachment ()
	{
		NETVAR_RETURN_THIS (int &, "DT_RopeKeyframe", "m_iParentAttachment");
	}
};
struct DT_RagdollManager
{
	NETVAR_REFLECTION_NOBASE (DT_RagdollManager);
	inline int &iCurrentMaxRagdollCount ()
	{
		NETVAR_RETURN_THIS (int &, "DT_RagdollManager", "m_iCurrentMaxRagdollCount");
	}
};
struct DT_PhysicsProp : public DT_BreakableProp
{
	NETVAR_REFLECTION (DT_PhysicsProp, DT_BreakableProp);
	inline bool &bAwake ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PhysicsProp", "m_bAwake");
	}
};
struct DT_PhysicsPropMultiplayer : public DT_PhysicsProp
{
	NETVAR_REFLECTION (DT_PhysicsPropMultiplayer, DT_PhysicsProp);
	inline int &iPhysicsMode ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PhysicsPropMultiplayer", "m_iPhysicsMode");
	}
	inline int &fMass ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PhysicsPropMultiplayer", "m_fMass");
	}
	inline Vector &collisionMins ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_PhysicsPropMultiplayer", "m_collisionMins");
	}
	inline Vector &collisionMaxs ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_PhysicsPropMultiplayer", "m_collisionMaxs");
	}
};
struct DT_PhysBox : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_PhysBox, DT_BaseEntity);
	inline float &mass ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PhysBox", "m_mass");
	}
};
struct DT_PhysBoxMultiplayer : public DT_PhysBox
{
	NETVAR_REFLECTION (DT_PhysBoxMultiplayer, DT_PhysBox);
	inline int &iPhysicsMode ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PhysBoxMultiplayer", "m_iPhysicsMode");
	}
	inline int &fMass ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PhysBoxMultiplayer", "m_fMass");
	}
};
struct DT_BasePropDoor : public DT_DynamicProp
{
	NETVAR_REFLECTION (DT_BasePropDoor, DT_DynamicProp);
};
struct DT_PointCommentaryNode : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_PointCommentaryNode, DT_BaseAnimating);
	inline bool &bActive ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PointCommentaryNode", "m_bActive");
	}
	inline float &flStartTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PointCommentaryNode", "m_flStartTime");
	}
	inline int &iszCommentaryFile ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PointCommentaryNode", "m_iszCommentaryFile");
	}
	inline int &iszCommentaryFileNoHDR ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PointCommentaryNode", "m_iszCommentaryFileNoHDR");
	}
	inline int &iszSpeakers ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PointCommentaryNode", "m_iszSpeakers");
	}
	inline int &iNodeNumber ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PointCommentaryNode", "m_iNodeNumber");
	}
	inline int &iNodeNumberMax ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PointCommentaryNode", "m_iNodeNumberMax");
	}
	inline EHANDLE &hViewPosition ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_PointCommentaryNode", "m_hViewPosition");
	}
};
struct DT_PointCamera : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_PointCamera, DT_BaseEntity);
	inline float &FOV ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PointCamera", "m_FOV");
	}
	inline float &Resolution ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PointCamera", "m_Resolution");
	}
	inline bool &bFogEnable ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PointCamera", "m_bFogEnable");
	}
	inline int &FogColor ()
	{
		NETVAR_RETURN_THIS (int &, "DT_PointCamera", "m_FogColor");
	}
	inline float &flFogStart ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PointCamera", "m_flFogStart");
	}
	inline float &flFogEnd ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PointCamera", "m_flFogEnd");
	}
	inline float &flFogMaxDensity ()
	{
		NETVAR_RETURN_THIS (float &, "DT_PointCamera", "m_flFogMaxDensity");
	}
	inline bool &bActive ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PointCamera", "m_bActive");
	}
	inline bool &bUseScreenAspectRatio ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_PointCamera", "m_bUseScreenAspectRatio");
	}
};
struct DT_Plasma : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_Plasma, DT_BaseEntity);
	inline float &flStartScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Plasma", "m_flStartScale");
	}
	inline float &flScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Plasma", "m_flScale");
	}
	inline float &flScaleTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Plasma", "m_flScaleTime");
	}
	inline int &nFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Plasma", "m_nFlags");
	}
	inline int &nPlasmaModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Plasma", "m_nPlasmaModelIndex");
	}
	inline int &nPlasmaModelIndex2 ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Plasma", "m_nPlasmaModelIndex2");
	}
	inline int &nGlowModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Plasma", "m_nGlowModelIndex");
	}
};
struct DT_PhysMagnet : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_PhysMagnet, DT_BaseAnimating);
};
struct DT_ParticleSystem
{
	NETVAR_REFLECTION_NOBASE (DT_ParticleSystem);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_ParticleSystem", "m_vecOrigin");
	}
	inline EHANDLE &hOwnerEntity ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_ParticleSystem", "m_hOwnerEntity");
	}
	inline int &moveparent ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ParticleSystem", "moveparent");
	}
	inline int &iParentAttachment ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ParticleSystem", "m_iParentAttachment");
	}
	inline QAngle &angRotation ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_ParticleSystem", "m_angRotation");
	}
	inline int &iEffectIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ParticleSystem", "m_iEffectIndex");
	}
	inline bool &bActive ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_ParticleSystem", "m_bActive");
	}
	inline float &flStartTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_ParticleSystem", "m_flStartTime");
	}
	inline EHANDLE *hControlPointEnts ()
	{
		NETVAR_RETURN_ARRAY_THIS (EHANDLE *, "DT_ParticleSystem", "m_hControlPointEnts");
	} // Array size = 63
	inline int *iControlPointParents ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_ParticleSystem", "m_iControlPointParents");
	} // Array size = 63
	inline bool &bWeatherEffect ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_ParticleSystem", "m_bWeatherEffect");
	}
};
struct DT_MaterialModifyControl : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_MaterialModifyControl, DT_BaseEntity);
	inline char *&szMaterialName ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_MaterialModifyControl", "m_szMaterialName");
	}
	inline char *&szMaterialVar ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_MaterialModifyControl", "m_szMaterialVar");
	}
	inline char *&szMaterialVarValue ()
	{
		NETVAR_RETURN_THIS (char *&, "DT_MaterialModifyControl", "m_szMaterialVarValue");
	}
	inline int &iFrameStart ()
	{
		NETVAR_RETURN_THIS (int &, "DT_MaterialModifyControl", "m_iFrameStart");
	}
	inline int &iFrameEnd ()
	{
		NETVAR_RETURN_THIS (int &, "DT_MaterialModifyControl", "m_iFrameEnd");
	}
	inline bool &bWrap ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_MaterialModifyControl", "m_bWrap");
	}
	inline float &flFramerate ()
	{
		NETVAR_RETURN_THIS (float &, "DT_MaterialModifyControl", "m_flFramerate");
	}
	inline bool &bNewAnimCommandsSemaphore ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_MaterialModifyControl", "m_bNewAnimCommandsSemaphore");
	}
	inline float &flFloatLerpStartValue ()
	{
		NETVAR_RETURN_THIS (float &, "DT_MaterialModifyControl", "m_flFloatLerpStartValue");
	}
	inline float &flFloatLerpEndValue ()
	{
		NETVAR_RETURN_THIS (float &, "DT_MaterialModifyControl", "m_flFloatLerpEndValue");
	}
	inline float &flFloatLerpTransitionTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_MaterialModifyControl", "m_flFloatLerpTransitionTime");
	}
	inline bool &bFloatLerpWrap ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_MaterialModifyControl", "m_bFloatLerpWrap");
	}
	inline int &nModifyMode ()
	{
		NETVAR_RETURN_THIS (int &, "DT_MaterialModifyControl", "m_nModifyMode");
	}
};
struct DT_LightGlow
{
	NETVAR_REFLECTION_NOBASE (DT_LightGlow);
	inline int &clrRender ()
	{
		NETVAR_RETURN_THIS (int &, "DT_LightGlow", "m_clrRender");
	}
	inline int &nHorizontalSize ()
	{
		NETVAR_RETURN_THIS (int &, "DT_LightGlow", "m_nHorizontalSize");
	}
	inline int &nVerticalSize ()
	{
		NETVAR_RETURN_THIS (int &, "DT_LightGlow", "m_nVerticalSize");
	}
	inline int &nMinDist ()
	{
		NETVAR_RETURN_THIS (int &, "DT_LightGlow", "m_nMinDist");
	}
	inline int &nMaxDist ()
	{
		NETVAR_RETURN_THIS (int &, "DT_LightGlow", "m_nMaxDist");
	}
	inline int &nOuterMaxDist ()
	{
		NETVAR_RETURN_THIS (int &, "DT_LightGlow", "m_nOuterMaxDist");
	}
	inline int &spawnflags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_LightGlow", "m_spawnflags");
	}
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_LightGlow", "m_vecOrigin");
	}
	inline QAngle &angRotation ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_LightGlow", "m_angRotation");
	}
	inline int &moveparent ()
	{
		NETVAR_RETURN_THIS (int &, "DT_LightGlow", "moveparent");
	}
	inline float &flGlowProxySize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_LightGlow", "m_flGlowProxySize");
	}
	inline float &HDRColorScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_LightGlow", "HDRColorScale");
	}
};
struct DT_InfoOverlayAccessor
{
	NETVAR_REFLECTION_NOBASE (DT_InfoOverlayAccessor);
	inline int &iTextureFrameIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_InfoOverlayAccessor", "m_iTextureFrameIndex");
	}
	inline int &iOverlayID ()
	{
		NETVAR_RETURN_THIS (int &, "DT_InfoOverlayAccessor", "m_iOverlayID");
	}
};
struct DT_FuncTrackTrain : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_FuncTrackTrain, DT_BaseEntity);
};
struct DT_FuncSmokeVolume : public DT_BaseParticleEntity
{
	NETVAR_REFLECTION (DT_FuncSmokeVolume, DT_BaseParticleEntity);
	inline int &Color1 ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FuncSmokeVolume", "m_Color1");
	}
	inline int &Color2 ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FuncSmokeVolume", "m_Color2");
	}
	inline float &ParticleDrawWidth ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FuncSmokeVolume", "m_ParticleDrawWidth");
	}
	inline float &ParticleSpacingDistance ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FuncSmokeVolume", "m_ParticleSpacingDistance");
	}
	inline float &DensityRampSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FuncSmokeVolume", "m_DensityRampSpeed");
	}
	inline float &RotationSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FuncSmokeVolume", "m_RotationSpeed");
	}
	inline float &MovementSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FuncSmokeVolume", "m_MovementSpeed");
	}
	inline float &Density ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FuncSmokeVolume", "m_Density");
	}
	inline int &spawnflags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FuncSmokeVolume", "m_spawnflags");
	}
	inline CCollisionProperty &Collision ()
	{
		NETVAR_RETURN_THIS (CCollisionProperty &, "DT_FuncSmokeVolume", "m_Collision");
	}
}; // Fail count = 1
struct DT_FuncRotating : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_FuncRotating, DT_BaseEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_FuncRotating", "m_vecOrigin");
	}
	inline QAngle &angRotation0 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_FuncRotating", "m_angRotation[0]");
	}
	inline QAngle &angRotation1 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_FuncRotating", "m_angRotation[1]");
	}
	inline QAngle &angRotation2 ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_FuncRotating", "m_angRotation[2]");
	}
	inline float &flSimulationTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FuncRotating", "m_flSimulationTime");
	}
};
struct DT_FuncReflectiveGlass : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_FuncReflectiveGlass, DT_BaseEntity);
};
struct DT_FuncOccluder : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_FuncOccluder, DT_BaseEntity);
	inline bool &bActive ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_FuncOccluder", "m_bActive");
	}
	inline int &nOccluderIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FuncOccluder", "m_nOccluderIndex");
	}
};
struct DT_FuncMonitor : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_FuncMonitor, DT_BaseEntity);
};
struct DT_Func_LOD : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_Func_LOD, DT_BaseEntity);
	inline int &fDisappearDist ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Func_LOD", "m_fDisappearDist");
	}
};
struct DT_TEDust : public DT_TEParticleSystem
{
	NETVAR_REFLECTION (DT_TEDust, DT_TEParticleSystem);
	inline float &flSize ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TEDust", "m_flSize");
	}
	inline float &flSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_TEDust", "m_flSpeed");
	}
	inline Vector &vecDirection ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_TEDust", "m_vecDirection");
	}
};
struct DT_Func_Dust
{
	NETVAR_REFLECTION_NOBASE (DT_Func_Dust);
	struct CCollisionProperty
	{
		NETVAR_REFLECTION (CCollisionProperty, DT_Func_Dust);
		inline Vector &vecMinsPreScaled ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_Func_Dust", "m_Collision", "m_vecMinsPreScaled");
		}
		inline Vector &vecMaxsPreScaled ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_Func_Dust", "m_Collision", "m_vecMaxsPreScaled");
		}
		inline Vector &vecMins ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_Func_Dust", "m_Collision", "m_vecMins");
		}
		inline Vector &vecMaxs ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_Func_Dust", "m_Collision", "m_vecMaxs");
		}
		inline int &nSolidType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_Func_Dust", "m_Collision", "m_nSolidType");
		}
		inline int &usSolidFlags ()
		{
			NETVAR_RETURN_THIS (int &, "DT_Func_Dust", "m_Collision", "m_usSolidFlags");
		}
		inline int &nSurroundType ()
		{
			NETVAR_RETURN_THIS (int &, "DT_Func_Dust", "m_Collision", "m_nSurroundType");
		}
		inline int &triggerBloat ()
		{
			NETVAR_RETURN_THIS (int &, "DT_Func_Dust", "m_Collision", "m_triggerBloat");
		}
		inline Vector &vecSpecifiedSurroundingMinsPreScaled ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_Func_Dust", "m_Collision", "m_vecSpecifiedSurroundingMinsPreScaled");
		}
		inline Vector &vecSpecifiedSurroundingMaxsPreScaled ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_Func_Dust", "m_Collision", "m_vecSpecifiedSurroundingMaxsPreScaled");
		}
		inline Vector &vecSpecifiedSurroundingMins ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_Func_Dust", "m_Collision", "m_vecSpecifiedSurroundingMins");
		}
		inline Vector &vecSpecifiedSurroundingMaxs ()
		{
			NETVAR_RETURN_THIS (Vector &, "DT_Func_Dust", "m_Collision", "m_vecSpecifiedSurroundingMaxs");
		}
	};
	inline int &Color ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Func_Dust", "m_Color");
	}
	inline int &SpawnRate ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Func_Dust", "m_SpawnRate");
	}
	inline float &flSizeMin ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Func_Dust", "m_flSizeMin");
	}
	inline float &flSizeMax ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Func_Dust", "m_flSizeMax");
	}
	inline int &LifetimeMin ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Func_Dust", "m_LifetimeMin");
	}
	inline int &LifetimeMax ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Func_Dust", "m_LifetimeMax");
	}
	inline int &DustFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Func_Dust", "m_DustFlags");
	}
	inline int &SpeedMax ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Func_Dust", "m_SpeedMax");
	}
	inline int &DistMax ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Func_Dust", "m_DistMax");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Func_Dust", "m_nModelIndex");
	}
	inline float &FallSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Func_Dust", "m_FallSpeed");
	}
	inline CCollisionProperty &Collision ()
	{
		NETVAR_RETURN_THIS (CCollisionProperty &, "DT_Func_Dust", "m_Collision");
	}
};
struct DT_FuncConveyor : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_FuncConveyor, DT_BaseEntity);
	inline float &flConveyorSpeed ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FuncConveyor", "m_flConveyorSpeed");
	}
};
struct DT_BreakableSurface : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_BreakableSurface, DT_BaseEntity);
	inline int &nNumWide ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BreakableSurface", "m_nNumWide");
	}
	inline int &nNumHigh ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BreakableSurface", "m_nNumHigh");
	}
	inline float &flPanelWidth ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BreakableSurface", "m_flPanelWidth");
	}
	inline float &flPanelHeight ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BreakableSurface", "m_flPanelHeight");
	}
	inline Vector &vNormal ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_BreakableSurface", "m_vNormal");
	}
	inline Vector &vCorner ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_BreakableSurface", "m_vCorner");
	}
	inline bool &bIsBroken ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_BreakableSurface", "m_bIsBroken");
	}
	inline int &nSurfaceType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BreakableSurface", "m_nSurfaceType");
	}
}; // Fail count = 1
struct DT_FuncAreaPortalWindow : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_FuncAreaPortalWindow, DT_BaseEntity);
	inline float &flFadeStartDist ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FuncAreaPortalWindow", "m_flFadeStartDist");
	}
	inline float &flFadeDist ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FuncAreaPortalWindow", "m_flFadeDist");
	}
	inline float &flTranslucencyLimit ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FuncAreaPortalWindow", "m_flTranslucencyLimit");
	}
	inline int &iBackgroundModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FuncAreaPortalWindow", "m_iBackgroundModelIndex");
	}
};
struct DT_CFish
{
	NETVAR_REFLECTION_NOBASE (DT_CFish);
	inline Vector &poolOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_CFish", "m_poolOrigin");
	}
	inline float &x ()
	{
		NETVAR_RETURN_THIS (float &, "DT_CFish", "m_x");
	}
	inline float &y ()
	{
		NETVAR_RETURN_THIS (float &, "DT_CFish", "m_y");
	}
	inline float &z ()
	{
		NETVAR_RETURN_THIS (float &, "DT_CFish", "m_z");
	}
	inline QAngle &angle ()
	{
		NETVAR_RETURN_THIS (QAngle &, "DT_CFish", "m_angle");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_CFish", "m_nModelIndex");
	}
	inline int &lifeState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_CFish", "m_lifeState");
	}
	inline float &waterLevel ()
	{
		NETVAR_RETURN_THIS (float &, "DT_CFish", "m_waterLevel");
	}
};
struct DT_EntityFlame : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_EntityFlame, DT_BaseEntity);
	inline EHANDLE &hEntAttached ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_EntityFlame", "m_hEntAttached");
	}
};
struct DT_FireSmoke : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_FireSmoke, DT_BaseEntity);
	inline float &flStartScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FireSmoke", "m_flStartScale");
	}
	inline float &flScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FireSmoke", "m_flScale");
	}
	inline float &flScaleTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_FireSmoke", "m_flScaleTime");
	}
	inline int &nFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FireSmoke", "m_nFlags");
	}
	inline int &nFlameModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FireSmoke", "m_nFlameModelIndex");
	}
	inline int &nFlameFromAboveModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FireSmoke", "m_nFlameFromAboveModelIndex");
	}
};
struct DT_EnvTonemapController : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_EnvTonemapController, DT_BaseEntity);
	inline bool &bUseCustomAutoExposureMin ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_EnvTonemapController", "m_bUseCustomAutoExposureMin");
	}
	inline bool &bUseCustomAutoExposureMax ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_EnvTonemapController", "m_bUseCustomAutoExposureMax");
	}
	inline bool &bUseCustomBloomScale ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_EnvTonemapController", "m_bUseCustomBloomScale");
	}
	inline float &flCustomAutoExposureMin ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EnvTonemapController", "m_flCustomAutoExposureMin");
	}
	inline float &flCustomAutoExposureMax ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EnvTonemapController", "m_flCustomAutoExposureMax");
	}
	inline float &flCustomBloomScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EnvTonemapController", "m_flCustomBloomScale");
	}
	inline float &flCustomBloomScaleMinimum ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EnvTonemapController", "m_flCustomBloomScaleMinimum");
	}
};
struct DT_EnvScreenEffect : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_EnvScreenEffect, DT_BaseEntity);
	inline float &flDuration ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EnvScreenEffect", "m_flDuration");
	}
	inline int &nType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_EnvScreenEffect", "m_nType");
	}
};
struct DT_EnvScreenOverlay : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_EnvScreenOverlay, DT_BaseEntity);
	inline int &iszOverlayNames0 ()
	{
		NETVAR_RETURN_THIS (int &, "DT_EnvScreenOverlay", "m_iszOverlayNames[0]");
	}
	inline int *iszOverlayNames ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_EnvScreenOverlay", "m_iszOverlayNames");
	} // Array size = 10
	inline float &flOverlayTimes0 ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EnvScreenOverlay", "m_flOverlayTimes[0]");
	}
	inline float *flOverlayTimes ()
	{
		NETVAR_RETURN_ARRAY_THIS (float *, "DT_EnvScreenOverlay", "m_flOverlayTimes");
	} // Array size = 10
	inline float &flStartTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EnvScreenOverlay", "m_flStartTime");
	}
	inline int &iDesiredOverlay ()
	{
		NETVAR_RETURN_THIS (int &, "DT_EnvScreenOverlay", "m_iDesiredOverlay");
	}
	inline bool &bIsActive ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_EnvScreenOverlay", "m_bIsActive");
	}
};
struct DT_EnvProjectedTexture : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_EnvProjectedTexture, DT_BaseEntity);
	inline EHANDLE &hTargetEntity ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_EnvProjectedTexture", "m_hTargetEntity");
	}
	inline bool &bState ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_EnvProjectedTexture", "m_bState");
	}
	inline float &flLightFOV ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EnvProjectedTexture", "m_flLightFOV");
	}
	inline bool &bEnableShadows ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_EnvProjectedTexture", "m_bEnableShadows");
	}
	inline bool &bLightOnlyTarget ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_EnvProjectedTexture", "m_bLightOnlyTarget");
	}
	inline bool &bLightWorld ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_EnvProjectedTexture", "m_bLightWorld");
	}
	inline bool &bCameraSpace ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_EnvProjectedTexture", "m_bCameraSpace");
	}
	inline Vector &LinearFloatLightColor ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_EnvProjectedTexture", "m_LinearFloatLightColor");
	}
	inline float &flAmbient ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EnvProjectedTexture", "m_flAmbient");
	}
	inline int &nSpotlightTextureFrame ()
	{
		NETVAR_RETURN_THIS (int &, "DT_EnvProjectedTexture", "m_nSpotlightTextureFrame");
	}
	inline float &flNearZ ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EnvProjectedTexture", "m_flNearZ");
	}
	inline float &flFarZ ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EnvProjectedTexture", "m_flFarZ");
	}
	inline int &nShadowQuality ()
	{
		NETVAR_RETURN_THIS (int &, "DT_EnvProjectedTexture", "m_nShadowQuality");
	}
}; // Fail count = 1
struct DT_EnvParticleScript : public DT_BaseAnimating
{
	NETVAR_REFLECTION (DT_EnvParticleScript, DT_BaseAnimating);
	inline float &flSequenceScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EnvParticleScript", "m_flSequenceScale");
	}
};
struct DT_FogController
{
	NETVAR_REFLECTION_NOBASE (DT_FogController);
	inline int &fog_enable ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.enable");
	}
	inline int &fog_blend ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.blend");
	}
	inline int &fog_dirPrimary ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.dirPrimary");
	}
	inline int &fog_colorPrimary ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.colorPrimary");
	}
	inline int &fog_colorSecondary ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.colorSecondary");
	}
	inline int &fog_start ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.start");
	}
	inline int &fog_end ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.end");
	}
	inline int &fog_farz ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.farz");
	}
	inline int &fog_maxdensity ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.maxdensity");
	}
	inline int &fog_colorPrimaryLerpTo ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.colorPrimaryLerpTo");
	}
	inline int &fog_colorSecondaryLerpTo ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.colorSecondaryLerpTo");
	}
	inline int &fog_startLerpTo ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.startLerpTo");
	}
	inline int &fog_endLerpTo ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.endLerpTo");
	}
	inline int &fog_lerptime ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.lerptime");
	}
	inline int &fog_duration ()
	{
		NETVAR_RETURN_THIS (int &, "DT_FogController", "m_fog.duration");
	}
};
struct DT_EntityParticleTrail : public DT_BaseParticleEntity
{
	NETVAR_REFLECTION (DT_EntityParticleTrail, DT_BaseParticleEntity);
	struct CEntityParticleTrailInfo
	{
		NETVAR_REFLECTION (CEntityParticleTrailInfo, DT_EntityParticleTrail);
		inline float &flLifetime ()
		{
			NETVAR_RETURN_THIS (float &, "DT_EntityParticleTrail", "m_Info", "m_flLifetime");
		}
		inline float &flStartSize ()
		{
			NETVAR_RETURN_THIS (float &, "DT_EntityParticleTrail", "m_Info", "m_flStartSize");
		}
		inline float &flEndSize ()
		{
			NETVAR_RETURN_THIS (float &, "DT_EntityParticleTrail", "m_Info", "m_flEndSize");
		}
	};
	inline int &iMaterialName ()
	{
		NETVAR_RETURN_THIS (int &, "DT_EntityParticleTrail", "m_iMaterialName");
	}
	inline CEntityParticleTrailInfo &Info ()
	{
		NETVAR_RETURN_THIS (CEntityParticleTrailInfo &, "DT_EntityParticleTrail", "m_Info");
	}
	inline EHANDLE &hConstraintEntity ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_EntityParticleTrail", "m_hConstraintEntity");
	}
};
struct DT_EntityDissolve : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_EntityDissolve, DT_BaseEntity);
	inline float &flStartTime ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EntityDissolve", "m_flStartTime");
	}
	inline float &flFadeOutStart ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EntityDissolve", "m_flFadeOutStart");
	}
	inline float &flFadeOutLength ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EntityDissolve", "m_flFadeOutLength");
	}
	inline float &flFadeOutModelStart ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EntityDissolve", "m_flFadeOutModelStart");
	}
	inline float &flFadeOutModelLength ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EntityDissolve", "m_flFadeOutModelLength");
	}
	inline float &flFadeInStart ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EntityDissolve", "m_flFadeInStart");
	}
	inline float &flFadeInLength ()
	{
		NETVAR_RETURN_THIS (float &, "DT_EntityDissolve", "m_flFadeInLength");
	}
	inline int &nDissolveType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_EntityDissolve", "m_nDissolveType");
	}
	inline Vector &vDissolverOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_EntityDissolve", "m_vDissolverOrigin");
	}
	inline int &nMagnitude ()
	{
		NETVAR_RETURN_THIS (int &, "DT_EntityDissolve", "m_nMagnitude");
	}
};
struct DT_DynamicLight : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_DynamicLight, DT_BaseEntity);
	inline int &Flags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_DynamicLight", "m_Flags");
	}
	inline int &LightStyle ()
	{
		NETVAR_RETURN_THIS (int &, "DT_DynamicLight", "m_LightStyle");
	}
	inline float &Radius ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DynamicLight", "m_Radius");
	}
	inline int &Exponent ()
	{
		NETVAR_RETURN_THIS (int &, "DT_DynamicLight", "m_Exponent");
	}
	inline float &InnerAngle ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DynamicLight", "m_InnerAngle");
	}
	inline float &OuterAngle ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DynamicLight", "m_OuterAngle");
	}
	inline float &SpotRadius ()
	{
		NETVAR_RETURN_THIS (float &, "DT_DynamicLight", "m_SpotRadius");
	}
};
struct DT_ColorCorrectionVolume : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_ColorCorrectionVolume, DT_BaseEntity);
	inline float &Weight ()
	{
		NETVAR_RETURN_THIS (float &, "DT_ColorCorrectionVolume", "m_Weight");
	}
}; // Fail count = 1
struct DT_ColorCorrection : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_ColorCorrection, DT_BaseEntity);
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_ColorCorrection", "m_vecOrigin");
	}
	inline float &minFalloff ()
	{
		NETVAR_RETURN_THIS (float &, "DT_ColorCorrection", "m_minFalloff");
	}
	inline float &maxFalloff ()
	{
		NETVAR_RETURN_THIS (float &, "DT_ColorCorrection", "m_maxFalloff");
	}
	inline float &flCurWeight ()
	{
		NETVAR_RETURN_THIS (float &, "DT_ColorCorrection", "m_flCurWeight");
	}
	inline int &netLookupFilename ()
	{
		NETVAR_RETURN_THIS (int &, "DT_ColorCorrection", "m_netLookupFilename");
	}
	inline bool &bEnabled ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_ColorCorrection", "m_bEnabled");
	}
};
struct DT_BaseDoor : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_BaseDoor, DT_BaseEntity);
	inline float &flWaveHeight ()
	{
		NETVAR_RETURN_THIS (float &, "DT_BaseDoor", "m_flWaveHeight");
	}
};
struct DT_BoneFollower : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_BoneFollower, DT_BaseEntity);
	inline int &modelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BoneFollower", "m_modelIndex");
	}
	inline int &solidIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_BoneFollower", "m_solidIndex");
	}
};
struct DT_InfoLightingRelative : public DT_BaseEntity
{
	NETVAR_REFLECTION (DT_InfoLightingRelative, DT_BaseEntity);
	inline EHANDLE &hLightingLandmark ()
	{
		NETVAR_RETURN_THIS (EHANDLE &, "DT_InfoLightingRelative", "m_hLightingLandmark");
	}
};
struct DT_AI_BaseNPC : public DT_BaseCombatCharacter
{
	NETVAR_REFLECTION (DT_AI_BaseNPC, DT_BaseCombatCharacter);
	inline int &lifeState ()
	{
		NETVAR_RETURN_THIS (int &, "DT_AI_BaseNPC", "m_lifeState");
	}
	inline bool &bPerformAvoidance ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_AI_BaseNPC", "m_bPerformAvoidance");
	}
	inline bool &bIsMoving ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_AI_BaseNPC", "m_bIsMoving");
	}
	inline bool &bFadeCorpse ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_AI_BaseNPC", "m_bFadeCorpse");
	}
	inline int &iDeathPose ()
	{
		NETVAR_RETURN_THIS (int &, "DT_AI_BaseNPC", "m_iDeathPose");
	}
	inline int &iDeathFrame ()
	{
		NETVAR_RETURN_THIS (int &, "DT_AI_BaseNPC", "m_iDeathFrame");
	}
	inline int &iSpeedModRadius ()
	{
		NETVAR_RETURN_THIS (int &, "DT_AI_BaseNPC", "m_iSpeedModRadius");
	}
	inline int &iSpeedModSpeed ()
	{
		NETVAR_RETURN_THIS (int &, "DT_AI_BaseNPC", "m_iSpeedModSpeed");
	}
	inline bool &bSpeedModActive ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_AI_BaseNPC", "m_bSpeedModActive");
	}
	inline bool &bImportanRagdoll ()
	{
		NETVAR_RETURN_THIS (bool &, "DT_AI_BaseNPC", "m_bImportanRagdoll");
	}
	inline float &flTimePingEffect ()
	{
		NETVAR_RETURN_THIS (float &, "DT_AI_BaseNPC", "m_flTimePingEffect");
	}
};
struct DT_Beam
{
	NETVAR_REFLECTION_NOBASE (DT_Beam);
	struct CBeamPredictableId
	{
		NETVAR_REFLECTION (CBeamPredictableId, DT_Beam);
		inline int &PredictableID ()
		{
			NETVAR_RETURN_THIS (int &, "DT_Beam", "beampredictable_id", "m_PredictableID");
		}
		inline bool &bIsPlayerSimulated ()
		{
			NETVAR_RETURN_THIS (bool &, "DT_Beam", "beampredictable_id", "m_bIsPlayerSimulated");
		}
	};
	inline int &nBeamType ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_nBeamType");
	}
	inline int &nBeamFlags ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_nBeamFlags");
	}
	inline int &nNumBeamEnts ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_nNumBeamEnts");
	}
	inline EHANDLE *hAttachEntity ()
	{
		NETVAR_RETURN_ARRAY_THIS (EHANDLE *, "DT_Beam", "m_hAttachEntity");
	} // Array size = 10
	inline int *nAttachIndex ()
	{
		NETVAR_RETURN_ARRAY_THIS (int *, "DT_Beam", "m_nAttachIndex");
	} // Array size = 10
	inline int &nHaloIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_nHaloIndex");
	}
	inline int &fHaloScale ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_fHaloScale");
	}
	inline int &fWidth ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_fWidth");
	}
	inline int &fEndWidth ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_fEndWidth");
	}
	inline int &fFadeLength ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_fFadeLength");
	}
	inline int &fAmplitude ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_fAmplitude");
	}
	inline int &fStartFrame ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_fStartFrame");
	}
	inline int &fSpeed ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_fSpeed");
	}
	inline float &flFrameRate ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Beam", "m_flFrameRate");
	}
	inline float &flHDRColorScale ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Beam", "m_flHDRColorScale");
	}
	inline int &clrRender ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_clrRender");
	}
	inline int &nRenderFX ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_nRenderFX");
	}
	inline int &nRenderMode ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_nRenderMode");
	}
	inline float &flFrame ()
	{
		NETVAR_RETURN_THIS (float &, "DT_Beam", "m_flFrame");
	}
	inline Vector &vecEndPos ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_Beam", "m_vecEndPos");
	}
	inline int &nModelIndex ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_nModelIndex");
	}
	inline int &nMinDXLevel ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "m_nMinDXLevel");
	}
	inline Vector &vecOrigin ()
	{
		NETVAR_RETURN_THIS (Vector &, "DT_Beam", "m_vecOrigin");
	}
	inline int &moveparent ()
	{
		NETVAR_RETURN_THIS (int &, "DT_Beam", "moveparent");
	}
	inline CBeamPredictableId &beampredictable_id ()
	{
		NETVAR_RETURN_THIS (CBeamPredictableId &, "DT_Beam", "beampredictable_id");
	}
};
