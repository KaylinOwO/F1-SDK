
#include "CDrawManager.h"

DrawManager gDrawManager;

void DrawManager::Initialize ()
{
	if (gInts->Surface == nullptr)
		return;

	// TODO: redundent with width height from glow
	gInts->Engine->GetScreenSize (gScreenSize.iScreenWidth, gScreenSize.iScreenHeight);

	EspFont = gInts->Surface->CreateFont ();
	gInts->Surface->SetFontGlyphSet (EspFont, "Tahoma", GetESPHeight (), 500, 0, 0, DrawManager::FontFlags::Outline);

	HudFont = gInts->Surface->CreateFont ();
	gInts->Surface->SetFontGlyphSet (HudFont, "Tahoma", GetHudHeight (), 500, 0, 0, DrawManager::FontFlags::Antialias | DrawManager::FontFlags::DropShadow);
}

void DrawManager::SetupDrawString (HFont font, int x, int y, DWORD color)
{
	gInts->Surface->DrawSetTextPos (x, y);
	gInts->Surface->DrawSetTextFont (font);
	gInts->Surface->DrawSetTextColor (RED (color), GREEN (color), BLUE (color), ALPHA (color));
}

void DrawManager::DrawString (const wchar_t *text)
{
	if (text == NULL) {
		return;
	}

	gInts->Surface->DrawPrintText (text, wcslen (text));
}

void DrawManager::DrawString (HFont font, int x, int y, DWORD color, const char *format, ...)
{
	if (format == NULL) {
		return;
	}

	SetupDrawString (font, x, y, color);

	va_list vaList;
	char    buffer[1024] = {'\0'};
	wchar_t string[1024] = {'\0'};

	va_start (vaList, format);
	V_vsprintf_safe (buffer, format, vaList);
	va_end (vaList);

	V_swprintf_safe (string, L"%S", buffer);

	DrawString (string);
}

void DrawManager::DrawString (HFont font, int x, int y, DWORD color, const wchar_t *format, ...)
{
	if (format == NULL) {
		return;
	}

	SetupDrawString (font, x, y, color);

	va_list vaList;
	wchar_t string[1024] = {'\0'};

	va_start (vaList, format);
	V_vswprintf_safe (string, format, vaList);
	va_end (vaList);

	DrawString (string);
}

int DrawManager::GetESPHeight ()
{
	return 12;
}

int DrawManager::GetHudHeight ()
{
	return 16;
}

DrawManager::font_size_t DrawManager::GetPixelTextSize (HFont font, const char *text)
{
	font_size_t temp;
	wchar_t     buffer[1024] = {'/0'};

	V_swprintf_safe (buffer, L"%s", text);

	gInts->Surface->GetTextSize (font, buffer, temp.length, temp.height);

	// temp.length *= 1.1f;

	return temp;
}

void DrawManager::DrawRect (int x, int y, int w, int h, DWORD color)
{
	gInts->Surface->DrawSetColor (RED (color), GREEN (color), BLUE (color), ALPHA (color));
	gInts->Surface->DrawFilledRect (x, y, x + w, y + h);
}

void DrawManager::OutlineRect (int x, int y, int w, int h, DWORD color)
{
	gInts->Surface->DrawSetColor (RED (color), GREEN (color), BLUE (color), ALPHA (color));
	gInts->Surface->DrawOutlinedRect (x, y, x + w, y + h);
}

void DrawManager::DrawCircle (int x, int y, int radius, int segments, DWORD color)
{
	gInts->Surface->DrawSetColor (RED (color), GREEN (color), BLUE (color), ALPHA (color));
	gInts->Surface->DrawOutlinedCircle (x, y, radius, segments);
}

void DrawManager::DrawBox (Vector vOrigin, int r, int g, int b, int alpha, int box_width, int radius)
{
	Vector vScreen;

	if (!WorldToScreen (vOrigin, vScreen))
		return;

	int radius2 = radius << 1;

	OutlineRect (vScreen.x - radius + box_width, vScreen.y - radius + box_width, radius2 - box_width, radius2 - box_width, 0x000000FF);
	OutlineRect (vScreen.x - radius - 1, vScreen.y - radius - 1, radius2 + (box_width + 2), radius2 + (box_width + 2), 0x000000FF);
	DrawRect (vScreen.x - radius + box_width, vScreen.y - radius, radius2 - box_width, box_width, COLORCODE (r, g, b, alpha));
	DrawRect (vScreen.x - radius, vScreen.y + radius, radius2, box_width, COLORCODE (r, g, b, alpha));
	DrawRect (vScreen.x - radius, vScreen.y - radius, box_width, radius2, COLORCODE (r, g, b, alpha));
	DrawRect (vScreen.x + radius, vScreen.y - radius, box_width, radius2 + box_width, COLORCODE (r, g, b, alpha));
}

void DrawManager::DrawBox (Vector vOrigin, DWORD color, int box_width, int box_height, int radius)
{
	Vector vScreen;

	if (!WorldToScreen (vOrigin, vScreen))
		return;

	int radius2 = radius << 1;

	OutlineRect (vScreen.x - radius + box_width, vScreen.y - radius + box_height, radius2 - box_width, radius2 - box_height, 0x000000FF);
	OutlineRect (vScreen.x - radius - 1, vScreen.y - radius - 1, radius2 + (box_width + 2), radius2 + (box_height + 2), 0x000000FF);
	DrawRect (vScreen.x - radius + box_width, vScreen.y - radius, radius2 - box_width, box_height, color);
	DrawRect (vScreen.x - radius, vScreen.y + radius, radius2, box_height, color);
	DrawRect (vScreen.x - radius, vScreen.y - radius, box_width, radius2, color);
	DrawRect (vScreen.x + radius, vScreen.y - radius, box_width, radius2 + box_height, color);
}

void DrawManager::DrawBox (Vector *pointList, DWORD color)
{
	// TODO: optimize

	Vector vStart, vEnd;

	for (auto i = 0; i < 3; i++) {
		if (gDrawManager.WorldToScreen (pointList[i], vStart)) {
			if (gDrawManager.WorldToScreen (pointList[i + 1], vEnd))
				gDrawManager.drawLine (vStart.x, vStart.y, vEnd.x, vEnd.y, color);
		}
	}

	if (gDrawManager.WorldToScreen (pointList[0], vStart)) {
		if (gDrawManager.WorldToScreen (pointList[3], vEnd))
			gDrawManager.drawLine (vStart.x, vStart.y, vEnd.x, vEnd.y, color);
	}

	for (int i = 4; i < 7; i++) {
		if (gDrawManager.WorldToScreen (pointList[i], vStart)) {
			if (gDrawManager.WorldToScreen (pointList[i + 1], vEnd))
				gDrawManager.drawLine (vStart.x, vStart.y, vEnd.x, vEnd.y, color);
		}
	}

	if (gDrawManager.WorldToScreen (pointList[4], vStart)) {
		if (gDrawManager.WorldToScreen (pointList[7], vEnd))
			gDrawManager.drawLine (vStart.x, vStart.y, vEnd.x, vEnd.y, color);
	}

	if (gDrawManager.WorldToScreen (pointList[0], vStart)) {
		if (gDrawManager.WorldToScreen (pointList[6], vEnd))
			gDrawManager.drawLine (vStart.x, vStart.y, vEnd.x, vEnd.y, color);
	}

	if (gDrawManager.WorldToScreen (pointList[1], vStart)) {
		if (gDrawManager.WorldToScreen (pointList[5], vEnd))
			gDrawManager.drawLine (vStart.x, vStart.y, vEnd.x, vEnd.y, color);
	}

	if (gDrawManager.WorldToScreen (pointList[2], vStart)) {
		if (gDrawManager.WorldToScreen (pointList[4], vEnd))
			gDrawManager.drawLine (vStart.x, vStart.y, vEnd.x, vEnd.y, color);
	}

	if (gDrawManager.WorldToScreen (pointList[3], vStart)) {
		if (gDrawManager.WorldToScreen (pointList[7], vEnd))
			gDrawManager.drawLine (vStart.x, vStart.y, vEnd.x, vEnd.y, color);
	}
}

void DrawManager::DrawRadiusBox (int x, int y, int w, int h, int outline, DWORD color)
{
	gDrawManager.OutlineRect (x - (outline * 2), y - (outline * 2), w + (outline * 4), h + (outline * 4), 0x000000FF);
	gDrawManager.OutlineRect (x + (outline * 2), y + (outline * 2), w - (outline * 4), h - (outline * 4), 0x000000FF);

	for (int iIndex = 0; iIndex <= outline; iIndex++) {
		gDrawManager.DrawRect (x - (outline * 2) + iIndex, y + (outline * 2) + iIndex, w - (outline * 4) - iIndex, h - (outline * 4) - iIndex, 0x000000FF);
	}
}

void DrawManager::DrawCornerBox (int x, int y, int w, int h, int cx, int cy, DWORD color)
{
	drawLine (x, y, x + (w / cx), y, color);
	drawLine (x, y, x, y + (h / cy), color);

	drawLine (x + w, y, x + w - (w / cx), y, color);
	drawLine (x + w, y, x + w, y + (h / cy), color);

	drawLine (x, y + h, x + (w / cx), y + h, color);
	drawLine (x, y + h, x, y + h - (h / cy), color);

	drawLine (x + w, y + h, x + w - (w / cx), y + h, color);
	drawLine (x + w, y + h, x + w, y + h - (h / cy), color);
}

// World to screen matrix that we are going to reconstruct
VMatrix m_matrixWorldToScreen;

bool DrawManager::WorldToScreen (Vector &vOrigin, Vector &vScreen)
{

	return !gInts->DebugOverlay->ScreenPosition (vOrigin, vScreen);

	if (m_bWorldToScreenMatrixValid == false) {
		if (gScreenSize.iScreenHeight == 0 || gScreenSize.iScreenWidth == 0) {
			gInts->Engine->GetScreenSize (gScreenSize.iScreenWidth, gScreenSize.iScreenHeight);
		}

		// begin compute view matrices
		VMatrix projectionToPixels, worldToProjection, worldToView, viewToProjection;

		gInts->RenderView->GetMatricesForView (lastSetup, &worldToView, &viewToProjection, &worldToProjection, &m_matrixWorldToScreen);

		// matrix is now valid
		m_bWorldToScreenMatrixValid = true;
	}

	const VMatrix &worldToScreen = gInts->Engine->WorldToScreenMatrix ();

	float w   = worldToScreen[3][0] * vOrigin[0] + worldToScreen[3][1] * vOrigin[1] + worldToScreen[3][2] * vOrigin[2] + worldToScreen[3][3]; //Calculate the angle in compareson to the player's camera.
	vScreen.z = 0;

	if (w > 0.001) //If the object is within view.
	{
		float fl1DBw = 1 / w;                                                                                                                                                                                                                 //Divide 1 by the angle.
		vScreen.x    = (gScreenSize.iScreenWidth / 2) + (0.5 * ((worldToScreen[0][0] * vOrigin[0] + worldToScreen[0][1] * vOrigin[1] + worldToScreen[0][2] * vOrigin[2] + worldToScreen[0][3]) * fl1DBw) * gScreenSize.iScreenWidth + 0.5);   //Get the X dimension and push it in to the Vector.
		vScreen.y    = (gScreenSize.iScreenHeight / 2) - (0.5 * ((worldToScreen[1][0] * vOrigin[0] + worldToScreen[1][1] * vOrigin[1] + worldToScreen[1][2] * vOrigin[2] + worldToScreen[1][3]) * fl1DBw) * gScreenSize.iScreenHeight + 0.5); //Get the Y dimension and push it in to the Vector.
		return true;
	}

	return false;
}

void DrawManager::drawLine (int startx, int starty, int endx, int endy, DWORD color)
{
	gInts->Surface->DrawSetColor (RED (color), GREEN (color), BLUE (color), ALPHA (color));
	gInts->Surface->DrawLine (startx, starty, endx, endy);
}
