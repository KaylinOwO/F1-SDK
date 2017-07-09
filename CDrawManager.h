#pragma once
//===================================================================================
#include "SDK.h"
#include "WindowsProxy.h"
#include <cctype>

#include <view_shared.h>

struct CScreenSize
{
	int iScreenWidth;
	int iScreenHeight;
};
extern CScreenSize gScreenSize;

//===================================================================================
// messy fix later
#define COLOR_OBJ COLORCODE (255, 255, 255, 255)           // 0
#define COLOR_TEAMONE COLORCODE (0, 128, 255, 255)         // 1
#define COLOR_TEAMTWO COLORCODE (186, 52, 53, 255)         // 2 red
#define COLOR_TEAMTHREE COLORCODE (0, 128, 255, 255)       // 3 blue
#define COLOR_TEAMFOUR COLORCODE (255, 128, 0, 255)        // 4
#define COLOR_BACK COLORCODE (30, 30, 30, 128)             // 5
#define COLOR_LINE COLORCODE (255, 120, 0, 255)            // 6
#define COLOR_OUTLINE COLORCODE (255, 100, 000, 255)       // 7
#define COLOR_SELECT COLORCODE (255, 100, 000, 255)        // 8
#define COLOR_HUD_TEXT COLORCODE (255, 255, 255, 255)      // 9
#define COLOR_CROSS COLORCODE (255, 255, 255, 255)         // 10
#define COLOR_CROSS_SEC COLORCODE (255, 0, 0, 255)         // 11
#define COLOR_INVIS_TEAMTWO COLORCODE (110, 180, 255, 255) // 12
#define COLOR_INVIS_TEAMTHREE COLORCODE (255, 0, 0, 255)   // 13
#define COLOR_MENU_ON COLORCODE (0, 128, 255, 255)         // 14
#define COLOR_MENU_OFF COLORCODE (255, 255, 255, 255)      // 15
#define COLOR_AIM_TARGET COLORCODE (0, 255, 0, 255)        // 16
#define COLOR_BLACK COLORCODE (0, 0, 0, 255)               // 17
//===================================================================================
class DrawManager
{
public:
	enum FontFlags
	{
		None,
		Italic       = 0x001,
		Underline    = 0x002,
		Strikeout    = 0x004,
		Symbol       = 0x008,
		Antialias    = 0x010,
		GaussianBlur = 0x020,
		Rotart       = 0x040,
		DropShadow   = 0x080,
		Addative     = 0x100,
		Outline      = 0x200,
		Custom       = 0x400, // custom generated font - never fall back to asian compatibility mode
	};

	using HFont = unsigned long;

	// TODO:
	HFont EspFont;
	HFont HudFont;

	// TODO:
	struct font_size_t
	{
		int height;
		int length;
	};

	void        Initialize ();
	void        SetupDrawString (HFont font, int x, int y, DWORD color);
	void        DrawString (const wchar_t *text);
	void        DrawString (HFont font, int x, int y, DWORD color, const char *format, ...);
	void        DrawString (HFont font, int x, int y, DWORD color, const wchar_t *format, ...);
	int         GetESPHeight ();
	int         GetHudHeight ();
	font_size_t GetPixelTextSize (HFont font, const char *pszText);
	void        DrawBox (Vector vOrigin, int r, int g, int b, int alpha, int box_width, int radius);
	void        DrawBox (Vector vOrigin, DWORD color, int box_width, int box_height, int radius);
	void        DrawBox (Vector *pointList, DWORD color);
	void        DrawRadiusBox (int x, int y, int w, int h, int outline, DWORD color);
	void        DrawRect (int x, int y, int w, int h, DWORD color);
	void        DrawCornerBox (int x, int y, int w, int h, int cx, int cy, DWORD color);
	void        OutlineRect (int x, int y, int w, int h, DWORD color);
	void        DrawCircle (int x, int y, int radius, int segments, DWORD color);
	bool        WorldToScreen (Vector &vOrigin, Vector &vScreen);
	void        drawLine (int startx, int starty, int endx, int endy, DWORD color);
	DWORD       dwGetTeamColor (int iIndex)
	{
		static DWORD colors[] = {
		    COLORCODE (255, 255, 255, 255), // Dummy
		    COLOR_TEAMONE,                  // 1 Teamone (SPECTATORS)
		    /*0xFF8000FF*/ COLOR_TEAMTWO,   // 2 Teamtwo (RED)
		    /*0x0080FFFF*/ COLOR_TEAMTHREE, // 3 teamthree (BLUE)
		    COLOR_TEAMFOUR                  // 4 Teamfour (UNUSED)
		};
		return colors[iIndex];
	}
	void Invalidate ()
	{
		m_bWorldToScreenMatrixValid = false;
	}
	CViewSetup *GetLastSetup ()
	{
		return &lastSetup;
	}

private:
	unsigned long m_Font;
	bool          m_bWorldToScreenMatrixValid = true;
	CViewSetup    lastSetup;
};

extern DrawManager gDrawManager;

DEFINE_ENUM_BITWISE_OPERATORS (DrawManager::FontFlags);