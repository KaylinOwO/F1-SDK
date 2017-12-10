#pragma once

//#include "sourcesdk/game/shared/animation.hh"

template <class T>
inline T LoopingLerp (float flPercent, T flFrom, T flTo)
{
    T s = flTo * flPercent + flFrom * (1.0f - flPercent);
    return s;
}

template <>
inline float LoopingLerp (float flPercent, float flFrom, float flTo)
{
    if (fabs (flTo - flFrom) >= 0.5f) {
        if (flFrom < flTo)
            flFrom += 1.0f;
        else
            flTo += 1.0f;
    }

    float s = flTo * flPercent + flFrom * (1.0f - flPercent);

    s = s - (int)(s);
    if (s < 0.0f)
        s = s + 1.0f;

    return s;
}

template <class T>
inline T Lerp_Hermite (float t, const T &p0, const T &p1, const T &p2)
{
    T d1 = p1 - p0;
    T d2 = p2 - p1;

    T     output;
    float tSqr  = t * t;
    float tCube = t * tSqr;

    output = p1 * (2 * tCube - 3 * tSqr + 1);
    output += p2 * (-2 * tCube + 3 * tSqr);
    output += d1 * (tCube - 2 * tSqr + t);
    output += d2 * (tCube - tSqr);

    return output;
}

template <class T>
inline T Derivative_Hermite (float t, const T &p0, const T &p1, const T &p2)
{
    T d1 = p1 - p0;
    T d2 = p2 - p1;

    T     output;
    float tSqr = t * t;

    output = p1 * (6 * tSqr - 6 * t);
    output += p2 * (-6 * tSqr + 6 * t);
    output += d1 * (3 * tSqr - 4 * t + 1);
    output += d2 * (3 * tSqr - 2 * t);

    return output;
}

inline void Lerp_Clamp (int val)
{
}

inline void Lerp_Clamp (float val)
{
}

inline void Lerp_Clamp (const Vector &val)
{
}

inline void Lerp_Clamp (const QAngle &val)
{
}

// If we have a range checked var, then we can clamp to its limits.
// template< class T, int minValue, int maxValue, int startValue >
// inline void Lerp_Clamp(CRangeCheckedVar<T, minValue, maxValue, startValue> &val)
//{
//  val.Clamp();
//}

template <>
inline QAngle Lerp_Hermite<QAngle> (float t, const QAngle &p0, const QAngle &p1, const QAngle &p2)
{
    // Can't do hermite with QAngles, get discontinuities, just do a regular interpolation
    return Lerp (t, p1, p2);
}

template <class T>
inline T LoopingLerp_Hermite (float t, T p0, T p1, T p2)
{
    return Lerp_Hermite (t, p0, p1, p2);
}

template <>
inline float LoopingLerp_Hermite (float t, float p0, float p1, float p2)
{
    if (fabs (p1 - p0) > 0.5f) {
        if (p0 < p1)
            p0 += 1.0f;
        else
            p1 += 1.0f;
    }

    if (fabs (p2 - p1) > 0.5f) {
        if (p1 < p2) {
            p1 += 1.0f;

            // see if we need to fix up p0
            // important for vars that are decreasing from p0->p1->p2 where
            // p1 is fixed up relative to p2, eg p0 = 0.2, p1 = 0.1, p2 = 0.9
            if (abs (p1 - p0) > 0.5) {
                if (p0 < p1)
                    p0 += 1.0f;
                else
                    p1 += 1.0f;
            }
        } else {
            p2 += 1.0f;
        }
    }

    float s = Lerp_Hermite (t, p0, p1, p2);

    s = s - (int)(s);
    if (s < 0.0f) {
        s = s + 1.0f;
    }

    return s;
}

class C_AnimationLayer
{
public:
    C_AnimationLayer ();
    void Reset ();

    void SetOrder (int order);

public:
    bool IsActive (void);

    int   m_nSequence;
    float m_flPrevCycle;
    float m_flWeight;
    int   m_nOrder;

    // used for automatic crossfades between sequence changes
    float m_flPlaybackRate;
    float m_flCycle;

    float GetFadeout (float flCurTime);

    void BlendWeight ();

    float m_flLayerAnimtime;
    float m_flLayerFadeOuttime;

    float m_flBlendIn;
    float m_flBlendOut;

    bool m_bClientBlend;
};

inline C_AnimationLayer::C_AnimationLayer ()
{
    Reset ();
}

inline void C_AnimationLayer::Reset ()
{
    m_nSequence          = 0;
    m_flPrevCycle        = 0;
    m_flWeight           = 0;
    m_flPlaybackRate     = 0;
    m_flCycle            = 0;
    m_flLayerAnimtime    = 0;
    m_flLayerFadeOuttime = 0;
    m_flBlendIn          = 0;
    m_flBlendOut         = 0;
    m_bClientBlend       = false;
}

inline void C_AnimationLayer::SetOrder (int order)
{
    m_nOrder = order;
}

inline float C_AnimationLayer::GetFadeout (float flCurTime)
{
    float s;

    if (m_flLayerFadeOuttime <= 0.0f) {
        s = 0;
    } else {
        // blend in over 0.2 seconds
        s = 1.0 - (flCurTime - m_flLayerAnimtime) / m_flLayerFadeOuttime;
        if (s > 0 && s <= 1.0) {
            // do a nice spline curve
            s = 3 * s * s - 2 * s * s * s;
        } else if (s > 1.0f) {
            // Shouldn't happen, but maybe curtime is behind animtime?
            s = 1.0f;
        }
    }
    return s;
}

inline C_AnimationLayer LoopingLerp (float flPercent, C_AnimationLayer &from, C_AnimationLayer &to)
{
    C_AnimationLayer output;

    output.m_nSequence   = to.m_nSequence;
    output.m_flCycle     = LoopingLerp (flPercent, (float)from.m_flCycle, (float)to.m_flCycle);
    output.m_flPrevCycle = to.m_flPrevCycle;
    output.m_flWeight    = Lerp (flPercent, from.m_flWeight, to.m_flWeight);
    output.m_nOrder      = to.m_nOrder;

    output.m_flLayerAnimtime    = to.m_flLayerAnimtime;
    output.m_flLayerFadeOuttime = to.m_flLayerFadeOuttime;
    return output;
}

inline C_AnimationLayer Lerp (float flPercent, const C_AnimationLayer &from, const C_AnimationLayer &to)
{
    C_AnimationLayer output;

    output.m_nSequence   = to.m_nSequence;
    output.m_flCycle     = Lerp (flPercent, from.m_flCycle, to.m_flCycle);
    output.m_flPrevCycle = to.m_flPrevCycle;
    output.m_flWeight    = Lerp (flPercent, from.m_flWeight, to.m_flWeight);
    output.m_nOrder      = to.m_nOrder;

    output.m_flLayerAnimtime    = to.m_flLayerAnimtime;
    output.m_flLayerFadeOuttime = to.m_flLayerFadeOuttime;
    return output;
}

inline C_AnimationLayer LoopingLerp_Hermite (float flPercent, C_AnimationLayer &prev, C_AnimationLayer &from, C_AnimationLayer &to)
{
    C_AnimationLayer output;

    output.m_nSequence   = to.m_nSequence;
    output.m_flCycle     = LoopingLerp_Hermite<float> (flPercent, (float)prev.m_flCycle, (float)from.m_flCycle, (float)to.m_flCycle);
    output.m_flPrevCycle = to.m_flPrevCycle;
    output.m_flWeight    = Lerp (flPercent, from.m_flWeight, to.m_flWeight);
    output.m_nOrder      = to.m_nOrder;

    output.m_flLayerAnimtime    = to.m_flLayerAnimtime;
    output.m_flLayerFadeOuttime = to.m_flLayerFadeOuttime;
    return output;
}

// YWB:  Specialization for interpolating euler angles via quaternions...
inline C_AnimationLayer Lerp_Hermite (float flPercent, const C_AnimationLayer &prev, const C_AnimationLayer &from, const C_AnimationLayer &to)
{
    C_AnimationLayer output;

    output.m_nSequence   = to.m_nSequence;
    output.m_flCycle     = Lerp_Hermite (flPercent, prev.m_flCycle, from.m_flCycle, to.m_flCycle);
    output.m_flPrevCycle = to.m_flPrevCycle;
    output.m_flWeight    = Lerp (flPercent, from.m_flWeight, to.m_flWeight);
    output.m_nOrder      = to.m_nOrder;

    output.m_flLayerAnimtime    = to.m_flLayerAnimtime;
    output.m_flLayerFadeOuttime = to.m_flLayerFadeOuttime;
    return output;
}

inline void Lerp_Clamp (C_AnimationLayer &val)
{
    // TODO: shouldnt we not implement this if it doesnt do anything
}

inline void C_AnimationLayer::BlendWeight ()
{
    if (!m_bClientBlend)
        return;

    m_flWeight = 1;

    // blend in?
    if (m_flBlendIn != 0.0f) {
        if (m_flCycle < m_flBlendIn) {
            m_flWeight = m_flCycle / m_flBlendIn;
        }
    }

    // blend out?
    if (m_flBlendOut != 0.0f) {
        if (m_flCycle > 1.0 - m_flBlendOut) {
            m_flWeight = (1.0 - m_flCycle) / m_flBlendOut;
        }
    }

    m_flWeight = 3.0 * m_flWeight * m_flWeight - 2.0 * m_flWeight * m_flWeight * m_flWeight;
    if (m_nSequence == 0)
        m_flWeight = 0;
}
