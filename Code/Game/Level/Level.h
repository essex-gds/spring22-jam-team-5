#ifndef BAWL_LEVEL_H
#define BAWL_LEVEL_H

#include <stdint.h>

class Level
{

	Level();

	virtual ~Level();

	uint64_t  mSize;            // Total map size width * height
	uint64_t  mWidth;           //
	uint64_t  mHeight;          //
	                            // Pointers point to set offsets in mapData
	uint16_t* mTileMap;         //
	uint16_t* mAnimatedTileMap; //
	uint16_t* mMovementMap;     //
	uint16_t* mCharMap;         //
	uint16_t* mActorMap;        //
	uint16_t* mMapData;         // Data for all maps
};

#endif // BAWL_LEVEL_H
