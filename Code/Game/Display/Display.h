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
	static Sprite* create(uint8_t tileIndex, double x, double y, double width, double height);

	static Sprite* create(uint8_t tileIndex);

	uint8_t          mTileIndex;
	double           mX;
	double           mY;
	double           mWidth;
	double           mHeight;
	double           mAngle;
	SDL_RendererFlip mFlip;
	uint8_t          mAlpha;
	uint8_t          mRShift;
	uint8_t          mBShift;
	uint8_t          mGShift;
};

struct Sound
{
	static struct Sound* create(const char* path);

	Uint32 wav_length;
	Uint8 *wav_buffer;
	SDL_AudioSpec wav_spec;
};

// variable declarations
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play

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

	void addSprite( Sprite* s );

	void removeSprite( Sprite* s );

	void addOverSprite( Sprite* s );

	void removeOverSprite( Sprite* s );


	SDL_Renderer* getRenderer();

	void setLevel(Level*  levelPtr);

	void setCamera(Camera* cameraPtr);

	void setTexture(uint8_t index, hash_t tex);

	int32_t getWidth();

	int32_t getHeight();

	uint64_t getTilesPerWidth();

	uint64_t getTilesPerHeight();

	uint64_t getTilesWidth();

	uint64_t getTileHeight();

	static void loadAudioData(void *userdata, Uint8 *stream, int len);

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
