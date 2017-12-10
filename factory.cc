#include "baseHeaders.hh"

#include "Log.hh"
#include "factory.hh"

void *srcFactory::getImpl (const char *name, int *ret)
{
	try {
		return factory (name, ret);
	} catch (...) {
		Log::Fatal ("Unable to get interface '%s'", name);
	}
	return nullptr;
}
