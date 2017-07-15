#pragma once
#include "../SDK/SDK.h"

// stuff for trace

enum TraceType_t : int
{
	TRACE_EVERYTHING = 0,
	TRACE_WORLD_ONLY,              // NOTE: This does *not* test static props!!!
	TRACE_ENTITIES_ONLY,           // NOTE: This version will *not* test static props
	TRACE_EVERYTHING_FILTER_PROPS, // NOTE: This version will pass the IHandleEntity for props through the filter, unlike all other filters
};

#define MAX_COORD_INTEGER (16384)
#define COORD_EXTENT (float)(2 * MAX_COORD_INTEGER)
#define MAX_TRACE_LENGTH (float)(1.732050807569 * COORD_EXTENT)

class ITraceFilter
{
public:
	virtual bool        ShouldHitEntity (IHandleEntity *BaseEntity, int mask) = 0;
	virtual TraceType_t GetTraceType () const                                 = 0;
};

class CBaseFilter : public ITraceFilter
{
public:
	CBaseFilter ()
	    : self (nullptr), ignore (nullptr)
	{
	}

	virtual bool        ShouldHitEntity (IHandleEntity *entity, int contentsMask);
	virtual TraceType_t GetTraceType () const;

	// Setup the filter
	inline void SetIgnoreSelf (CBaseEntity *e)
	{
		this->self = e;
	}
	inline void SetIgnoreEntity (CBaseEntity *e)
	{
		this->ignore = e;
	}

protected:
	// void Debug( CBaseEntity* pEnt );

protected:
	CBaseEntity *self;
	CBaseEntity *ignore;
};

inline bool CBaseFilter::ShouldHitEntity (IHandleEntity *handle, int contentsMask)
{
	CBaseEntity *ent   = GetBaseEntity (handle);
	ClientClass *entCC = ent->GetClientClass ();

	switch (entCC->classId) {
	case classId::CFuncRespawnRoomVisualizer:
	case classId::CTFMedigunShield:
	case classId::CFuncAreaPortalWindow:
		return false;
	}
	// Ignore specific entities
	if (ent == self || ent == ignore) {
		return false;
	}

	return true;
}
inline TraceType_t CBaseFilter::GetTraceType () const
{
	return TRACE_EVERYTHING;
}

class CCustomFilter : public ITraceFilter
{
public:
	CCustomFilter ()
	{
	}
	CCustomFilter (std::function<bool(IHandleEntity *, int)> s)
	    : shouldHit (s){

	      };
	bool ShouldHitEntity (IHandleEntity *entity, int contentsMask) override
	{
		return shouldHit (entity, contentsMask);
	}
	TraceType_t GetTraceType () const override
	{
		return TRACE_EVERYTHING;
	}
	void SetShouldHit (std::function<bool(IHandleEntity *, int)> s)
	{
		shouldHit = s;
	}

private:
	std::function<bool(IHandleEntity *, int)> shouldHit = [](IHandleEntity *, int) { return false; };
};

class CEngineTrace
{
public:
	void TraceRay (const Ray_t &ray, unsigned int mask, ITraceFilter *traceFilter, trace_t *trace)
	{
		typedef void(__thiscall * OriginalFn) (PVOID, const Ray_t &, unsigned int, ITraceFilter *, trace_t *);
		return getvfunc<OriginalFn> (this, 4) (this, ray, mask, traceFilter, trace);
	}
	void SweepCollideable (CBaseEntity *ent, const Vector &absStart, const Vector &absEnd, const QAngle &angles, unsigned int mask, ITraceFilter *traceFilter, trace_t *trace)
	{
		Ray_t ray;
		ray.Init (absStart, absEnd, ent->GetCollideableMins (), ent->GetCollideableMaxs ());
		TraceRay (ray, mask, traceFilter, trace);
	}
};
