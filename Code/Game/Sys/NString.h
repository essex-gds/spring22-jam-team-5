#ifndef BAWL_NSTRING_H
#define BAWL_NSTRING_H

#include <malloc.h>
#include <cstring>

struct NString
{
	size_t mLen;
	char   mStr[0];

	static NString* create(size_t len);
	static NString* create(const char* copyFrom);
	static NString* link(const char* copyFrom);
};

#endif // BAWL_NSTRING_H
