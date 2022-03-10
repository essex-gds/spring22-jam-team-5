#ifndef BAWL_LEVEL_H
#define BAWL_LEVEL_H

#include <gLog.h>

#include <cstdint>
#include <cstddef>
#include <malloc.h>

typedef uint8_t tile_t;

struct Level
{
	static Level* create(uint64_t width, uint64_t height);

	uint64_t  mSize;            // Total map size width * height
	uint64_t  mWidth;           //
	uint64_t  mHeight;          //
	                            // Pointers point to set offsets in mapData
	tile_t* mMovementMap;       //
	tile_t* mTileMap;           //
	tile_t* mOverTileMap;       //
	tile_t* mOverMap;           //
	tile_t* mCharMap;           //
	tile_t mMapData[0];         // Data for all maps

	static const inline size_t MAP_COUNT = 5; // update when you add / remove a map
};

#endif // BAWL_LEVEL_H
