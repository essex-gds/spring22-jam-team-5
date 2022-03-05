#include "Level.h"

Level* Level::create(uint64_t width, uint64_t height)
{
	size_t sizeOfMap = (width * height) * sizeof(tile_t);
	size_t size = sizeof(Level) + ( sizeOfMap * MAP_COUNT );
	Level* level = (Level*) calloc(  1,  size );

	level->mWidth  = width;
	level->mHeight = height;

	level->mSize = level->mWidth * level->mHeight;

	level->mTileMap     = level->mMapData + ( level->mSize * 0 );
	level->mOverTileMap = level->mMapData + ( level->mSize * 1 );
	level->mCharMap     = level->mMapData + ( level->mSize * 2 );
	level->mActorMap    = level->mMapData + ( level->mSize * 3 );
	level->mMovementMap = level->mMapData + ( level->mSize * 4 );

	return level;
}