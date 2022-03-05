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

	memset(mTileTextures, 0, 256 * sizeof(hash_t) );

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
		for (uint64_t y = 0; y < mCameraPtr->mHeight; y++)
		{
			for (uint64_t x = 0; x < mCameraPtr->mWidth; x++)
			{
				size_t pos = y * mLevelPtr->mWidth + mCameraPtr->mX + x;

				// if pos isn't valid dont draw
				if( mLevelPtr->mSize > pos && pos >= 0 )
				{
					hash_t hash = mLevelPtr->mTileMap[pos];
					TextureEntry entry = TextureMap::getEntry(mTileTextures[hash]);

					uint64_t pixelsPerTileWidth = mWindowWidth / mCameraPtr->mWidth;
					uint64_t pixelsPerTileHeight = mWindowHeight / mCameraPtr->mHeight;

					SDL_Rect dst;
					dst.x = (int32_t) ( x * pixelsPerTileWidth  );
					dst.y = (int32_t) ( y * pixelsPerTileHeight );
					dst.w = (int32_t) pixelsPerTileWidth;
					dst.h = (int32_t) pixelsPerTileHeight;

					SDL_Rect src = {0, 0, entry.mSurface->w, entry.mSurface->h};

					SDL_Texture *tex = entry.mTexture;

					GLOG_INFO("x: %d, y: %d ", dst.x, dst.y);

					SDL_RenderCopy(mRenderer, tex, &src, &dst);
				}
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


