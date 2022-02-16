#ifndef Bawl_CAMERA_H
#define Bawl_CAMERA_H


struct Camera
{
	// tile positions on map
	uint64_t mX;
	uint64_t mY;
	// sub pixel positions on (top-left) tile
	uint64_t mSubX;
	uint64_t mSubY;
	// count of tiles on one camera screen
	uint64_t mWidth;
	uint64_t mHeight;
};


#endif //Bawl_CAMERA_H
