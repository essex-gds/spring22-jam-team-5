#ifndef BAWL_FILEREADER_H
#define BAWL_FILEREADER_H

#include <SDL.h>

#include <cstring>

#if BUILD_DEBUG
	constexpr const char* textureRoot() { return "../../../Assets/Textures/"; }
#else
	constexpr const char* textureRoot() { return  "Assets/Textures/"; }
#endif

SDL_Surface* readTexture(const char* fName);

#endif //BAWL_FILEREADER_H
