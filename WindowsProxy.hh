#pragma once

// TODO: include this everywhere where you would normally include Windows.h

#if defined(_MSC_VER)
#include <Windows.h>
#else
// windows.h compat (from f1linux)

// redefine windows types!
typedef uintptr_t    DWORD, *PDWORD;
typedef void *       PVOID, *LPVOID;
typedef uint8_t      BYTE, byte, *PBYTE;
typedef uint16_t     WORD, *PWORD;
typedef unsigned int UINT;

// this is from winnt.h
#define DEFINE_ENUM_FLAG_OPERATORS(ENUMTYPE)             \
	extern "C++" {                                       \
	inline ENUMTYPE operator| (ENUMTYPE a, ENUMTYPE b)   \
	{                                                    \
		return ENUMTYPE (((int)a) | ((int)b));           \
	}                                                    \
	inline ENUMTYPE operator|= (ENUMTYPE &a, ENUMTYPE b) \
	{                                                    \
		return (ENUMTYPE &)(((int &)a) |= ((int)b));     \
	}                                                    \
	inline ENUMTYPE operator& (ENUMTYPE a, ENUMTYPE b)   \
	{                                                    \
		return ENUMTYPE (((int)a) & ((int)b));           \
	}                                                    \
	inline ENUMTYPE operator&= (ENUMTYPE &a, ENUMTYPE b) \
	{                                                    \
		return (ENUMTYPE &)(((int &)a) &= ((int)b));     \
	}                                                    \
	inline ENUMTYPE operator~ (ENUMTYPE a)               \
	{                                                    \
		return (ENUMTYPE) (~((int)a));                   \
	}                                                    \
	inline ENUMTYPE operator^ (ENUMTYPE a, ENUMTYPE b)   \
	{                                                    \
		return ENUMTYPE (((int)a) ^ ((int)b));           \
	}                                                    \
	inline ENUMTYPE operator^= (ENUMTYPE &a, ENUMTYPE b) \
	{                                                    \
		return (ENUMTYPE &)(((int &)a) ^= ((int)b));     \
	}                                                    \
	}

// remove the sideaffects of these macros

#define __thiscall
#define __fastcall
#define __stdcall
#define __cdecl
#define WINAPI __stdcall

#define __forceinline inline __attribute__((always_inline))

#if defined(F1_GCC) && !defined(F1_WINDOWS)
// some other helper functions from msvc
template <size_t size>
inline char *strcpy_s (char (&strDestination)[size], const char *strSource)
{
	return strncpy (strDestination, strSource, size);
}
// some other helper functions from msvc
template <size_t size>
inline char *strcat_s (char (&strDestination)[size], const char *strSource)
{
	return strncat (strDestination, strSource, size);
}
inline int vsprintf_s (char *buffer, size_t numberOfElements, const char *format, va_list argptr)
{
	return vsnprintf (buffer, numberOfElements, format, argptr);
}
template <size_t size>
inline int vsprintf_s (char (&buffer)[size], const char *format, va_list argptr)
{
	return vsnprintf (buffer, size, format, argptr);
}
inline int sprintf_s (char *buffer, size_t sizeOfBuffer, const char *format, ...)
{
	va_list args;
	va_start (args, format);
	int ret = vsnprintf (buffer, sizeOfBuffer, format, args);
	va_end (args);
	return ret;
}
template <size_t size>
inline int sprintf_s (char (&buffer)[size], const char *format, ...)
{
	va_list args;
	va_start (args, format);
	int ret = vsnprintf (buffer, size, format, args);
	va_end (args);
	return ret;
}
#endif
#if defined(F1_GCC)
inline void __fastfail (unsigned int Code)
{
	__asm__("int $0x29"
	        :
	        : "c"(Code)
	        : "memory");
}

// nasty hack i need to remove
#undef __CRT_UUID_DECL
#define __CRT_UUID_DECL(type, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)              \
	extern "C++" {                                                                    \
	template <>                                                                       \
	inline const GUID &__mingw_uuidof<type> ()                                        \
	{                                                                                 \
		static const IID __uuid_inst = {l, w1, w2, {b1, b2, b3, b4, b5, b6, b7, b8}}; \
		return __uuid_inst;                                                           \
	}                                                                                 \
	template <>                                                                       \
	inline const GUID &__mingw_uuidof<type *> ()                                      \
	{                                                                                 \
		return __mingw_uuidof<type> ();                                               \
	}                                                                                 \
	}

#undef __uuidof
#define __uuidof(type) __mingw_uuidof < __typeof(type) > ()
#endif

#endif