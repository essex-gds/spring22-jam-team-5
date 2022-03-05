#include "Camera.h"

void Camera::init(uint64_t width, uint64_t height)
{
	mWidth  = width;
	mHeight = height;

	mX    = 0;
	mY    = 0;
	mSubX = 0;
	mSubY = 0;
}
