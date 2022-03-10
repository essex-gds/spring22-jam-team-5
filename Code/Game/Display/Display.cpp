#include "Display.h"

Display::Display()
{
	mLevelPtr  = nullptr;
	mCameraPtr = nullptr;

	mRendererFlags = 0;
	mWindowFlags   = 0;

	mRendererFlags |= SDL_RENDERER_ACCELERATED;
	mWindowFlags   |= SDL_WINDOW_HIDDEN;

	mSprites = {};

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

void Display::clearDisplay()
{
	SDL_RenderClear(mRenderer);
}

void Display::drawDisplay()
{
	clearDisplay();

	drawTileMap(mLevelPtr->mTileMap);
	drawTileMap(mLevelPtr->mOverTileMap);

	drawSprites(mSprites);

	drawTileMap(mLevelPtr->mOverMap);
	drawTileMap(mLevelPtr->mCharMap);

	drawSprites(mOverSprites);

	drawFX();
	drawColorMask();
	drawShaders();
	SDL_RenderPresent(mRenderer);
}

void Display::drawTileMap(tile_t* map)
{
	// JANK AF
	// my recommendations, until i get around to reworking this to be less shit:
	// 1. do not let the camera ever make it to the edge of the screen
	// 2. do NOT let the camera ever make it to the edge of the screen

	if(mCameraPtr)
	{
		// pre-camera processing
		uint64_t pixelsPerTileWidth = mWindowWidth / mCameraPtr->mWidth;
		uint64_t pixelsPerTileHeight = mWindowHeight / mCameraPtr->mHeight;

		// scrolling
		if(mCameraPtr->mScrollEnabled)
		{

			// X
			if (mCameraPtr->mSubX > (float) pixelsPerTileWidth)
			{
				printf("W-RIGHT\n");
				mCameraPtr->mSubX -= (float) pixelsPerTileWidth;
				mCameraPtr->mX++;
			}

			if (mCameraPtr->mSubX < 0 && mCameraPtr->mSubX < ( 1 - (float) pixelsPerTileWidth ))
			{
				printf("W-LEFT\n");
				mCameraPtr->mSubX += (float) pixelsPerTileWidth;
				mCameraPtr->mX--;
			}

			// Y
			if (mCameraPtr->mSubY > (float) pixelsPerTileHeight)
			{
				printf("W-DOWN\n");
				mCameraPtr->mSubY -= (float) pixelsPerTileWidth;
				mCameraPtr->mY++;
			}

			if (mCameraPtr->mSubY < 0 && mCameraPtr->mSubY < ( 1 - (float) pixelsPerTileHeight ))
			{
				printf("W-UP\n");
				mCameraPtr->mSubY += (float) pixelsPerTileWidth;
				mCameraPtr->mY--;
			}
		}

		// draw the map
		for (int64_t y = 0; y < mCameraPtr->mHeight+2; y++)
		{
			for (int64_t x = 0; x < mCameraPtr->mWidth+2; x++)
			{

				size_t pos = ( ( mCameraPtr->mY + y ) * mLevelPtr->mWidth ) + ( mCameraPtr->mX + x );

				// if pos isn't valid dont draw
				if( mLevelPtr->mSize > pos && pos >= 0 )
				{
					hash_t hash = map[pos];
					TextureEntry entry = TextureMap::getEntry(mTileTextures[hash]);

					SDL_Rect dst;
					dst.x = (int32_t) ( x  * pixelsPerTileWidth );
					dst.y = (int32_t) ( y  * pixelsPerTileHeight );
					dst.w = (int32_t) pixelsPerTileWidth;
					dst.h = (int32_t) pixelsPerTileHeight;

					if(mCameraPtr -> mScrollEnabled)
					{
						dst.x -= (int32_t) mCameraPtr->mSubX;
						dst.y -= (int32_t) mCameraPtr->mSubY;
					}

					SDL_Rect src = {0, 0, entry.mSurface->w, entry.mSurface->h};

					SDL_Texture *tex = entry.mTexture;
					SDL_RenderCopy(mRenderer, tex, &src, &dst);
				}
			}
		}
	}
}

void Display::drawSprites(std::vector<Sprite*>& sprites)
{
	for(auto & sprite : sprites)
	{
		TextureEntry tex = TextureMap::getEntry(mTileTextures[sprite->mTileIndex]);

		SDL_Rect src;
		src.x = 0;
		src.y = 0;
		src.w = tex.mSurface->w;
		src.h = tex.mSurface->h;

		SDL_Rect dst;
		dst.x = (int32_t) sprite->mX;
		dst.y = (int32_t) sprite->mY;
		dst.w = (int32_t) sprite->mWidth;
		dst.h = (int32_t) sprite->mHeight;

		SDL_RenderCopy(mRenderer, tex.mTexture, &src, &dst);
	}
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

void Display::setTexture(uint8_t index, hash_t tex)
{
	mTileTextures[index] = tex;
}

void Display::addSprite(Sprite* s)
{
	mSprites.push_back(s);
}

void Display::addOverSprite(Sprite* s)
{
	mOverSprites.push_back(s);
}
