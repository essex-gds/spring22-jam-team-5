#ifndef BAWL_DISPLAY_H
#define BAWL_DISPLAY_H

#include <SDL.h>
#include <gLog.h>

#include <stdexcept>

#include "Types.h"
#include "Level.h"
#include "Camera.h"

class Display
{
public:

	Display();

	virtual ~Display();

	int init();

	int createWindow(int32_t width, int32_t height, const char* title);

	void showWindow();

	void hideWindow();

	void setTexture(uint8_t index, hash_t tex);

	void clearDisplay();

	void drawDisplay();

	void drawTileMap();

	void drawAnimatedTileMap();

	void drawCharMap();

	void drawActorMap();

	void drawOverSprite();

	void drawFX();

	void drawColorMask();

	void drawShaders();

	SDL_Renderer* getRenderer();

protected:

	SDL_Renderer* mRenderer;
	SDL_Window*   mWindow;

	int32_t mWindowWidth;
	int32_t mWindowHeight;

	Level*  mLevelPtr;
	Camera* mCameraPtr;

	hash_t mTileTextures[256];

	uint32_t mRendererFlags;
	uint32_t mWindowFlags;

};


#endif //PROJECTROOT_DISPLAY_H
