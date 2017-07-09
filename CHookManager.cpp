
#include "CHookManager.h"

CHookManager gHookManager;

CHookManager::~CHookManager ()
{
	for (auto &h : hookedMethods) {
		delete findOrCreateHook (h.first.first, h.first.second);
	}

	// this gets called by FreeLibraryAndExitThread so we need to sleep here
	Sleep (5000);
}

bool CHookManager::isHooked (void *address, unsigned offset) try {
	return VMTManager::HookPresent (address, offset);
} catch (...) {
	return false;
}

VMTBaseManager *CHookManager::findOrCreateHook (void *address, unsigned offset)
{
	if (isHooked (address, offset)) {
		return &VMTBaseManager::GetHook ((void *)address, offset);
	} else {
		hookedMethods[std::make_pair (address, offset)] = {0};
		auto hook                                       = new VMTBaseManager ();

		hook->Init (address, offset);

		return hook;
	}
}

bool CHookManager::methodHooked (void *address, int index, int offset)
{
	for (auto &hookedMethod : hookedMethods[std::make_pair (address, offset)]) {
		if (hookedMethod == index)
			return true;
	}

	return false;
}

void CHookManager::hookMethod (void *address, int index, void *newFunc, unsigned offset)
{
	if (methodHooked (address, index, offset)) {
		Log::Error ("Possible erronious double hook on method index %d from instance 0x%X", index, address);
	}

	hookedMethods[std::make_pair (address, offset)].push_back (index);

	VMTBaseManager *hook = findOrCreateHook (address, offset);

	hook->HookMethod (newFunc, index);
	hook->Rehook ();
}
