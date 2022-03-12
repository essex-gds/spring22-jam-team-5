#include "NString.h"

NString* NString::create(size_t len)
{
	return nullptr;
}

NString* NString::create(const char* copyFrom)
{
	size_t len = strlen(copyFrom); /* seethe */
	NString* ret = (NString*) malloc( sizeof(NString) + len );

	ret->mLen = len;
	memcpy(ret->mStr, copyFrom, ret->mLen);
	return ret;
}
