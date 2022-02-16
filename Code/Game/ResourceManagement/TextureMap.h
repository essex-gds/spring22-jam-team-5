#ifndef BAWL_TEXTURE_MAP_H
#define BAWL_TEXTURE_MAP_H

#include <SDL.h>
#include <gLog.h>

#include <map>
#include <cstddef>
#include <cstring>

#include "Display.h"
#include "Types.h"
#include "FileReader.h"

struct TextureEntry
{
	SDL_Surface* mSurface;
	SDL_Texture* mTexture;
	uint64_t     mReferenceCount;
};

class TextureMap
{
public:

	static int init(Display* display);

	static hash_t requestTexture(const char* texHandle);

	static void releaseTexture(hash_t hash);

	static TextureEntry getEntry(hash_t hash);

	static SDL_Texture* getTexture(hash_t hash);

protected:

	static hash_t nHash(size_t strSize, const char* pStr);

	static SDL_Texture* makeTexture(SDL_Surface* fName);

	static inline std::map<hash_t, TextureEntry> mEntryMap;
	static inline Display* sActiveDisplay;
};


#endif //BAWL_TEXTURE_MAP_H
