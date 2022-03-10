#ifndef BAWL_TYPES_H
#define BAWL_TYPES_H

#include <cstdint>
#include <cstddef>

typedef size_t hash_t;

struct NString
{
	size_t len;
	char   str[0];
};

#endif // BAWL_TYPES_H
