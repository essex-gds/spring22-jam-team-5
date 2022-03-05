#include "Level.h"

Level::Level()
{
	mSize   = 0;
	mWidth  = 0;
	mHeight = 0;

	mTileMap         = nullptr;
	mAnimatedTileMap = nullptr;
	mMovementMap     = nullptr;
	mCharMap         = nullptr;
	mActorMap        = nullptr;
	mMapData         = nullptr;
}

Level::~Level()
{

}

int Level::init(uint64_t width, uint64_t height)
{
	mWidth  = width;
	mHeight = height;

	mSize = mWidth * mHeight;

	size_t mapSize = mSize // mTileMap
	               + mSize // mAnimatedTileMap
	               + mSize // mMovementMap
	               + mSize // mCharMap
	               ;       // mActorMap

	mMapData = static_cast<tile_t*>( calloc( mapSize, sizeof(tile_t) ) );

	mTileMap         = mMapData + ( mSize * 0 );
	mAnimatedTileMap = mMapData + ( mSize * 1 );
	mMovementMap     = mMapData + ( mSize * 2 );
	mCharMap         = mMapData + ( mSize * 3 );
	mActorMap        = mMapData + ( mSize * 4 );

	ptrdiff_t tileMapOffSet         = ( ((uintptr_t) mTileMap)         - ((uintptr_t) mMapData) ) / sizeof(tile_t);
	ptrdiff_t animatedTileMapOffset = ( ((uintptr_t) mAnimatedTileMap) - ((uintptr_t) mMapData) ) / sizeof(tile_t);
	ptrdiff_t movementMapOffset     = ( ((uintptr_t) mMovementMap)     - ((uintptr_t) mMapData) ) / sizeof(tile_t);
	ptrdiff_t charMapOffset         = ( ((uintptr_t) mCharMap)         - ((uintptr_t) mMapData) ) / sizeof(tile_t);
	ptrdiff_t actorMapOffset        = ( ((uintptr_t) mActorMap)        - ((uintptr_t) mMapData) ) / sizeof(tile_t);

	GLOG_REQUIRE(animatedTileMapOffset - tileMapOffSet == movementMapOffset - animatedTileMapOffset
				 && charMapOffset - movementMapOffset == actorMapOffset - charMapOffset ,
				 "Map setup is invalid offset - mismatch");

	return GLOG_SUCCESS;
}