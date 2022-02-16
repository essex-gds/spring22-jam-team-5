#ifndef BAWL_LEVEL_H
#define BAWL_LEVEL_H

#include <gLog.h>

#include <cstdint>
#include <cstddef>
#include <malloc.h>


class Level
{
public:

	Level();

	virtual ~Level();

	int init(uint64_t width, uint64_t height);

	typedef uint8_t tile_t;

	uint64_t  mSize;            // Total map size width * height
	uint64_t  mWidth;           //
	uint64_t  mHeight;          //
	                            // Pointers point to set offsets in mapData
	tile_t* mTileMap;           //
	tile_t* mAnimatedTileMap;   //
	tile_t* mMovementMap;       //
	tile_t* mCharMap;           //
	tile_t* mActorMap;          //
	tile_t* mMapData;           // Data for all maps

};

#endif // BAWL_LEVEL_H
