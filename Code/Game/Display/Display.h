#ifndef BAWL_DISPLAY_H
#define BAWL_DISPLAY_H

#include <SDL.h>
#include <gLog.h>

#include <stdexcept>
#include <vector>

#include "TextureMap.h"
#include "Types.h"
#include "Level.h"
#include "Camera.h"

struct Sprite
{
	uint8_t mTileIndex;
	double mX;
	double mY;
	double mWidth;
	double mHeight;
};

class Display
{
public:

	Display();

	virtual ~Display();

	int init();

	int createWindow(int32_t width, int32_t height, const char* title);

	void showWindow();

	void hideWindow();

	void clearDisplay();

	void drawDisplay();

	void drawTileMap(tile_t* map);

	void drawSprites(std::vector<Sprite*>& sprites);

	void drawFX();

	void drawColorMask();

	void drawShaders();

	SDL_Renderer* getRenderer();

	void setLevel(Level*  levelPtr);

	void setCamera(Camera* cameraPtr);

	void setTexture(uint8_t index, hash_t tex);

	void addSprite( Sprite* s );

	void removeSprite( Sprite* s );

	void addOverSprite( Sprite* s );

	void removeOverSprite( Sprite* s );

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

	std::vector<Sprite*> mSprites;
	std::vector<Sprite*> mOverSprites;

};


#endif // BAWL_DISPLAY_H
