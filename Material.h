#pragma once

#include "baseHeaders.h"
#include "steam/SteamTypes.h"

class CModelRender
{
public:
	void ForcedMaterialOverride (IMaterial *mat, OverrideType_t type)
	{
		typedef void(__thiscall * OriginalFn) (PVOID, IMaterial *, OverrideType_t);
		return getvfunc<OriginalFn> (this, 1) (this, mat, type);
	}

	void DrawModelExecute (void *state, ModelRenderInfo_t &pInfo, matrix3x4_t *pCustomBoneToWorld)
	{
		typedef void(__thiscall * OriginalFn) (PVOID, void *, ModelRenderInfo_t &, matrix3x4_t *);
		return getvfunc<OriginalFn> (this, 19) (this, state, pInfo, pCustomBoneToWorld);
	}

	void SuppressEngineLighting (bool t)
	{
		typedef void(__thiscall * OriginalFn) (PVOID, bool);
		return getvfunc<OriginalFn> (this, 22) (this, t);
	}
};

class CMaterialSystem
{
public:
	IMaterial *FindMaterial (char const *pMaterialName, const char *pTextureGroupName, bool complain = true, const char *pComplainPrefix = NULL)
	{
		typedef IMaterial *(__thiscall * OriginalFn) (PVOID, const char *, const char *, bool, const char *);
		return getvfunc<OriginalFn> (this, 73) (this, pMaterialName, pTextureGroupName, complain, pComplainPrefix);
	}

	ITexture *FindTexture (char const *pTextureName, const char *pTextureGroupName, bool complain = true, int nAdditionalCreationFlags = 0)
	{
		typedef ITexture *(__thiscall * OriginalFn) (PVOID, const char *, const char *, bool, int);
		return getvfunc<OriginalFn> (this, 81) (this, pTextureName, pTextureGroupName, complain, nAdditionalCreationFlags);
	}

	IMaterial *CreateMaterial_Internal (const char *pMaterialName, KeyValues *pKeyValues)
	{
		typedef IMaterial *(__thiscall * OriginalFn) (PVOID, const char *, KeyValues *);
		auto *material = getvfunc<OriginalFn> (this, 72) (this, pMaterialName, pKeyValues);

		material->IncrementReferenceCount ();

		return material;
	}

	IMaterial *CreateMaterial (const char *pMaterialName, bool flat, bool ignorez, bool wireframe)
	{
		typedef IMaterial *(__thiscall * OriginalFn) (PVOID, const char *, KeyValues *);

		std::string type = (flat) ? "UnlitGeneric" : "VertexLitGeneric";

		std::string matdata = "\"" + type + "\"\n{\n\t\"$basetexture\" \"vgui/white_additive\"\n\t\"$envmap\"  \"\"\n\t\"$model\" \"1\"\n\t\"$flat\" \"1\"\n\t\"$nocull\"  \"0\"\n\t\"$selfillum\" \"1\"\n\t\"$halflambert\" \"1\"\n\t\"$nofog\"  \"0\"\n\t\"$znearer\" \"0\"\n\t\"$wireframe\" \"" + std::to_string (wireframe) + "\"\n\t\"$ignorez\" \"" + std::to_string (ignorez) + "\"\n}\n";

		KeyValues *pKeyValues = new KeyValues (type.c_str ());
		// U::InitKeyValues(pKeyValues, type.c_str());
		pKeyValues->LoadFromBuffer (pMaterialName, matdata.c_str ());

		auto *material = getvfunc<OriginalFn> (this, 72) (this, pMaterialName, pKeyValues);

		material->IncrementReferenceCount ();

		return material;
	}

	ITexture *CreateNamedRenderTargetTextureEx (const char *                rtName,
	                                            int                         w,
	                                            int                         h,
	                                            RenderTargetSizeMode_t      sizeMode, // Controls how size is generated (and regenerated on video mode change).
	                                            ImageFormat                 format,
	                                            MaterialRenderTargetDepth_t depth             = MATERIAL_RT_DEPTH_SHARED,
	                                            unsigned int                textureFlags      = TEXTUREFLAGS_CLAMPS | TEXTUREFLAGS_CLAMPT,
	                                            unsigned int                renderTargetFlags = 0)
	{
		typedef ITexture *(__thiscall * OriginalFn) (PVOID, char const *, int, int, RenderTargetSizeMode_t, ImageFormat, MaterialRenderTargetDepth_t, unsigned int, unsigned int);

		return getvfunc<OriginalFn> (this, 87) (this, rtName, w, h, sizeMode, format, depth, textureFlags, renderTargetFlags);
	}

	IMatRenderContext *GetRenderContext ()
	{
		typedef IMatRenderContext *(__thiscall * OriginalFn) (PVOID);
		return getvfunc<OriginalFn> (this, 100) (this);
	}
};

class CRenderView
{
public:
	void SetBlend (float f)
	{
		typedef void(__thiscall * OriginalFn) (PVOID, float);
		return getvfunc<OriginalFn> (this, 4) (this, f);
	}

	float GetBlend ()
	{
		typedef float(__thiscall * OriginalFn) (PVOID);
		return getvfunc<OriginalFn> (this, 5) (this);
	}

	void SetColorModulation (float *col)
	{
		typedef void(__thiscall * OriginalFn) (PVOID, float *);
		return getvfunc<OriginalFn> (this, 6) (this, col);
	}

	void GetColorModulation (float *col)
	{
		typedef void(__thiscall * OriginalFn) (PVOID, float *);
		return getvfunc<OriginalFn> (this, 7) (this, col);
	}

	void GetMatricesForView (const CViewSetup &view, VMatrix *pWorldToView, VMatrix *pViewToProjection, VMatrix *pWorldToProjection, VMatrix *pWorldToPixels)
	{
		typedef void(__thiscall * OriginalFn) (PVOID, CViewSetup const &, VMatrix *, VMatrix *, VMatrix *, VMatrix *);
		return getvfunc<OriginalFn> (this, 50) (this, view, pWorldToView, pViewToProjection, pWorldToProjection, pWorldToPixels);
	}
};