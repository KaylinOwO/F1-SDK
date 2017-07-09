#pragma once

//#define SOURCE_SDK_INCLUDED

#include "ignorewarnings_on.h"

#define CLIENT_DLL
#pragma warning(disable : 4311)
#pragma warning(disable : 4312)
#pragma warning(disable : 4541)
#pragma warning(disable : 4267)
#pragma warning(disable : 4183)

#define VERSION_SAFE_STEAM_API_INTERFACES
//#undef VERSION_SAFE_STEAM_API_INTERFACES

#define GLOWS_ENABLE
#undef MessageBox
#undef Yield
#undef PropertySheet

#include <valve_minmax_on.h>

// == VGUI ==
#include "engine/IEngineSound.h"
#include "engine/ivmodelinfo.h"
#include "ienginevgui.h"
#include "materialsystem/imaterialsystemstub.h"
#include "sourcesdk/game/shared/ehandle.h"
#include "sourcesdk/public/Color.h"
#include "vstdlib/jobthread.h"
#include <VGuiMatSurface/IMatSystemSurface.h>
#include <bitvec.h>
#include <checksum_crc.h>
#include <engine/ivdebugoverlay.h>
#include <engine/ivmodelrender.h>
#include <igameevents.h>
#include <ihandleentity.h>
#include <ivrenderview.h>
#include <materialsystem/MaterialSystemUtil.h>
#include <materialsystem/imaterial.h>
#include <materialsystem/imaterialvar.h>
#include <mempool.h>
#include <steam/steam_api.h>
#include <tier1/bitbuf.h>
#include <tier1/checksum_crc.h>
#include <tier1/checksum_md5.h>
#include <tier1/utlvector.h>
#include <utlmemory.h>
#include <vgui/Cursor.h>
#include <vgui/Dar.h>
#include <vgui/IBorder.h>
#include <vgui/IClientPanel.h>
#include <vgui/IInputInternal.h>
#include <vgui/ILocalize.h>
#include <vgui/IPanel.h>
#include <vgui/ISurface.h>
#include <vgui/IVGui.h>
#include <vgui_controls/Button.h>
#include <vgui_controls/CheckButton.h>
#include <vgui_controls/ComboBox.h>
#include <vgui_controls/Controls.h>
#include <vgui_controls/DialogManager.h>
#include <vgui_controls/Frame.h>
#include <vgui_controls/Menu.h>
#include <vgui_controls/Panel.h>
#include <vgui_controls/PropertyPage.h>
#include <vgui_controls/PropertySheet.h>
#include <vgui_controls/RadioButton.h>
#include <vgui_controls/TextEntry.h>

#define RAD_TELEMETRY_DISABLED
#include <tier0/vprof.h>

#define CLIENT_DLL

#include "sourcesdk/public/bone_accessor.h"
#include "sourcesdk/public/bone_setup.h"

#include <valve_minmax_off.h>

#undef TICK_INTERVAL
#undef TIME_TO_TICKS
#undef TICKS_TO_TIME
#define TICK_INTERVAL (gInts->Globals->interval_per_tick)
#define TIME_TO_TICKS(dt) ((int)(0.5f + (float)(dt) / TICK_INTERVAL))
#define TICKS_TO_TIME(t) (TICK_INTERVAL * (t))

#include "ignorewarnings_off.h"