//
// Created by talldie on 11/02/2022.
//

#include "FileReader.h"

SDL_Surface* readTexture(const char* fName)
{
	size_t rootPart = strlen(fName);
	size_t newPart  = strlen(textureRoot());
	char* fNameBuff = (char*) alloca( rootPart + newPart );
	memset(fNameBuff, 0, rootPart + newPart);
	strcat(fNameBuff, textureRoot() );
	strcat(fNameBuff, fName  );

	SDL_Surface* surface = SDL_LoadBMP(fNameBuff);

	if(surface != nullptr)
	{
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));
	}
	return surface;
}
