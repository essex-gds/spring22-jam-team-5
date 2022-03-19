#include "Display.h"

Sprite* Sprite::create(uint8_t tileIndex, double x, double y, double width, double height)
{
	Sprite* ret = (Sprite*) malloc( sizeof(Sprite) );
	ret->mTileIndex  = tileIndex;
	ret->mX          = x;
	ret->mY          = y;
	ret->mWidth      = width;
	ret->mHeight     = height;
	ret->mAngle      = 0;
	ret->mFlip       = SDL_FLIP_NONE;
	ret->mAlpha      = 255;
	ret->mRShift     = 255;
	ret->mBShift     = 255;
	ret->mGShift     = 255;


	return ret;
}

Sprite* Sprite::create(uint8_t tileIndex)
{
	return create(tileIndex, 0, 0, 32, 32);
}

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

	SDL_SetRenderDrawBlendMode(mRenderer, SDL_BLENDMODE_ADD);

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
				mCameraPtr->mSubX -= (float) pixelsPerTileWidth;
				mCameraPtr->mX++;
			}

			if (mCameraPtr->mSubX < 0 && mCameraPtr->mSubX < ( 1 - (float) pixelsPerTileWidth ))
			{
				mCameraPtr->mSubX += (float) pixelsPerTileWidth;
				mCameraPtr->mX--;
			}

			// Y
			if (mCameraPtr->mSubY > (float) pixelsPerTileHeight)
			{
				mCameraPtr->mSubY -= (float) pixelsPerTileWidth;
				mCameraPtr->mY++;
			}

			if (mCameraPtr->mSubY < 0 && mCameraPtr->mSubY < ( 1 - (float) pixelsPerTileHeight ))
			{
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
		dst.x = (int32_t) sprite->mX - (sprite->mWidth/2);
		dst.y = (int32_t) sprite->mY - (sprite->mHeight/2);
		dst.w = (int32_t) sprite->mWidth;
		dst.h = (int32_t) sprite->mHeight;

		SDL_SetTextureAlphaMod(tex.mTexture, sprite->mAlpha);
		SDL_SetTextureColorMod(tex.mTexture, sprite->mRShift, sprite->mGShift, sprite->mBShift);

		SDL_RenderCopyEx(mRenderer, tex.mTexture, &src, &dst, sprite->mAngle, NULL, sprite->mFlip);

		SDL_SetTextureAlphaMod(tex.mTexture, UINT8_MAX);
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

void Display::addSprite(Sprite* s)
{
	mSprites.push_back(s);
}

void Display::removeSprite(Sprite* s)
{
	mSprites.erase(std::remove(mSprites.begin(), mSprites.end(), s), mSprites.end());
}

void Display::addOverSprite(Sprite* s)
{
	mOverSprites.push_back(s);
}

void Display::removeOverSprite(Sprite* s)
{
	mOverSprites.erase(std::remove(mOverSprites.begin(), mOverSprites.end(), s), mOverSprites.end());
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

int32_t Display::getWidth()
{
	return mWindowWidth;
}

int32_t Display::getHeight()
{
	return mWindowHeight;
}

uint64_t Display::getTilesPerWidth()
{
	return mCameraPtr->mWidth;
}

uint64_t Display::getTilesPerHeight()
{
	return mCameraPtr->mHeight;
}

uint64_t Display::getTilesWidth()
{
	return mWindowWidth / mCameraPtr->mWidth;
}

uint64_t Display::getTileHeight()
{
	return mWindowHeight / mCameraPtr->mHeight;
}
