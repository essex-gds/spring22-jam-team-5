#ifndef BAWL_TYPES_H
#define BAWL_TYPES_H

#include <cfloat>
#include <cstdint>
#include <cstddef>

#include "NString.h"

typedef size_t hash_t;

typedef const char ID[8];

#define HAS_ID(x)      \
	inline static ID mID = x; \
	virtual inline ID& getID(){ return mID; }

#endif // BAWL_TYPES_H
