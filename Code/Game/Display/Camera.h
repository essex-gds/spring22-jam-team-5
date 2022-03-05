#ifndef Bawl_CAMERA_H
#define Bawl_CAMERA_H

#include "cstdint"

struct Camera
{
	void init(uint64_t width, uint64_t height);

	// tile positions on map
	uint64_t mX;
	uint64_t mY;
	// sub pixel positions on (top-left) tile
	float  mSubX;
	float  mSubY;
	// count of tiles on one camera screen
	uint64_t mWidth;
	uint64_t mHeight;

	bool mScrollEnabled;
};


#endif //Bawl_CAMERA_H
