#include "TextureMap.h"

int TextureMap::init(Display* display)
{
	sActiveDisplay = display;

	mEntryMap = {};

	TextureEntry missingEntry = {};

	const char* missingFileTexture = "MISSING_TEXTURE.bmp";

	missingEntry.mSurface        = readTexture(missingFileTexture);
	missingEntry.mTexture        = makeTexture(missingEntry.mSurface);
	missingEntry.mReferenceCount = INT64_MAX; // never getting rid of this bad boy

	mEntryMap.insert( {0L, missingEntry} ); // set to default texture

	return GLOG_SUCCESS;
}

hash_t TextureMap::requestTexture(const char* texHandle)
{
	hash_t hash = nHash(strlen(texHandle), texHandle);

	if (mEntryMap.find(hash) == mEntryMap.end())
	{
		GLOG_INFO("TexHandle requested but no present %s", texHandle);
		SDL_Surface* sur =  readTexture(texHandle);

		TextureEntry newEntry = {};

		if (sur != nullptr)
		{
			// entry texture will be made a draw time if it doesn't exist
			// keeps things simpler as that will be done in the display part of the code
			// but might come at a bit of a runtime cost
			newEntry.mSurface        = readTexture(texHandle);
			newEntry.mTexture        = makeTexture(sur);
			newEntry.mReferenceCount = 1;

			mEntryMap.insert( {hash, newEntry} );
		}
		else
		{
			GLOG_INFO("Texture not located");
		}
	}
	return hash;
}

void TextureMap::releaseTexture(hash_t hash)
{
	auto it = mEntryMap.find(hash);
	if( it != mEntryMap.end())
	{
		if( --it->second.mReferenceCount < 1)
		{
			mEntryMap.erase(it);
		}
	}
}

TextureEntry TextureMap::getEntry(hash_t hash)
{
	TextureEntry ret = {};
	auto it = mEntryMap.find(hash);
	if( it != mEntryMap.end())
	{
		ret = it->second;
	}
	else
	{       //load the missing texture
		ret = mEntryMap.find(0L)->second;
	}

	return ret;
}

SDL_Texture* TextureMap::getTexture(hash_t hash)
{
	SDL_Texture* ret = nullptr;
	auto it = mEntryMap.find(hash);
	if( it != mEntryMap.end())
	{
		ret = it->second.mTexture;
	}
	else
	{       //load the missing texture
		ret = mEntryMap.find(0L)->second.mTexture;
	}

	return ret;
}

hash_t TextureMap::nHash(size_t strSize, const char* pStr)
{
	size_t hash = 5381;
	while (strSize--)  // for every char of the string
		hash = ((hash << 5) + hash) + *pStr++;  // modify the hash
	return hash;
}

SDL_Texture* TextureMap::makeTexture(SDL_Surface* surface)
{
	SDL_Texture* tex = SDL_CreateTextureFromSurface(sActiveDisplay->getRenderer(), surface);
	return tex;
}