#include <TextureMap.h>
#include "Display.h"

Display::Display()
{
	mLevelPtr  = nullptr;
	mCameraPtr = nullptr;

	mRendererFlags = 0;
	mWindowFlags   = 0;

	mRendererFlags |= SDL_RENDERER_ACCELERATED;
	mWindowFlags   |= SDL_WINDOW_HIDDEN;

}

Display::~Display()
{

}

int Display::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		GLOG_INFO("Couldn't initialize SDL video: %s\n",SDL_GetError());
	}

	return GLOG_SUCCESS;
}

int Display::createWindow(int32_t width, int32_t height, const char* title)
{
	mWindowWidth = width;
	mWindowHeight = height;

	mWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				   mWindowWidth, mWindowHeight, mWindowFlags);

	// -1 indicates best fit for whatever reason
	mRenderer = SDL_CreateRenderer(mWindow,-1, mRendererFlags);

	return GLOG_SUCCESS;
}

void Display::showWindow()
{
	SDL_ShowWindow(mWindow);
	mWindowFlags |=  SDL_WINDOW_SHOWN;
	mWindowFlags &= ~SDL_WINDOW_HIDDEN;
}

void Display::hideWindow()
{
	SDL_HideWindow(mWindow);
	mWindowFlags |= SDL_WINDOW_HIDDEN;
	mWindowFlags &= ~SDL_WINDOW_SHOWN;
}

void Display::setTexture(uint8_t index, hash_t tex)
{
	mTileTextures[index] = tex;
}

void Display::clearDisplay()
{
	SDL_RenderClear(mRenderer);
}

void Display::drawDisplay()
{
	clearDisplay();
	drawTileMap();
	drawAnimatedTileMap();
	drawActorMap();
	drawCharMap();
	drawOverSprite();
	drawFX();
	drawFX();
	drawColorMask();
	drawShaders();
	SDL_RenderPresent(mRenderer);
}

void Display::drawTileMap()
{
	if(mCameraPtr)
	{
		uint64_t lineWidth    = mCameraPtr->mX + mCameraPtr->mWidth;
		uint64_t columnHeight = mCameraPtr->mY + mCameraPtr->mHeight;

		for (uint64_t i = mCameraPtr->mY; i < columnHeight; i++)
		{
			for (uint64_t j = mCameraPtr->mX; j < lineWidth; j++)
			{

				size_t pos  = i * mLevelPtr->mWidth + j;
				hash_t hash = mLevelPtr->mTileMap[pos];
				TextureEntry entry = TextureMap::getEntry(mTileTextures[hash]);

				uint64_t pixelsPerTileWidth  = mWindowWidth  /  mCameraPtr->mWidth;
				uint64_t pixelsPerTileHeight = mWindowHeight /  mCameraPtr->mHeight;

				SDL_Rect dst;
				dst.x = (int32_t) ((j - mCameraPtr->mX) * pixelsPerTileWidth);
				dst.y = (int32_t) ((i - mCameraPtr->mY) * pixelsPerTileHeight);
				dst.w = pixelsPerTileWidth;
				dst.h = pixelsPerTileHeight;

				SDL_Rect src = {0, 0, entry.mSurface->w, entry.mSurface->h};

				SDL_Texture *tex = entry.mTexture;

				SDL_RenderCopy(mRenderer, tex, &src, &dst);
			}
		}
	}
}

void Display::drawAnimatedTileMap()
{

}

void Display::drawCharMap()
{

}

void Display::drawActorMap()
{

}

void Display::drawOverSprite()
{

}

void Display::drawFX()
{

}

void Display::drawColorMask()
{

}

void Display::drawShaders()
{

}

SDL_Renderer* Display::getRenderer()
{
	return mRenderer;
}

void Display::setLevel(Level *levelPtr)
{
	this->mLevelPtr = levelPtr;
}

void Display::setCamera(Camera *cameraPtr)
{
	this->mCameraPtr = cameraPtr;
}


