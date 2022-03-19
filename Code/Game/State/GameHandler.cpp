#include "GameHandler.h"

GameHandler::GameHandler()
{
	mStateStack = {};
	mCloseRequested = false;

	sControlState.mKeyboardHeld = SDL_GetKeyboardState(&sControlState.mKeyboardSize);

	sControlState.mKeyboardPressed  = (uint8_t*) calloc(1, sControlState.mKeyboardSize);
	sControlState.mKeyboardReleased = (uint8_t*) calloc(1, sControlState.mKeyboardSize);
}

GameHandler::~GameHandler()
{

}

void GameHandler::enter()
{
	// Init
	mDisplay.init();
	mDisplay.createWindow(1280,916,"Bawl");
	TextureMap::init(&mDisplay);

	// setup

	mStateStack.push( new EntryState(&mDisplay) );

	// game loop
	updateLoop();
	leave();
}

void GameHandler::updateLoop()
{
	uint64_t prevTime = SDL_GetTicks64();
	while (!mCloseRequested)
	{
		float dt = (float)( SDL_GetTicks64() - prevTime ) / 1000.0f;
		prevTime = SDL_GetTicks64();
		updateSDL();
		mStateStack.update(dt);
		render();
	}
}

void GameHandler::leave()
{

}

void GameHandler::render()
{
	mDisplay.drawDisplay();
}

void GameHandler::updateSDL()
{
	uint8_t* preUpdate = (uint8_t*) malloc(sControlState.mKeyboardSize);
	memcpy(preUpdate,sControlState.mKeyboardHeld,sControlState.mKeyboardSize);

	SDL_Event event;

	// poll ( & pump ) updates
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				mCloseRequested = true;
				break;
			default:
				break;
		}
	}

	// do input
	for( uint32_t i = 0; i < sControlState.mKeyboardSize; i++)
	{
		auto o = preUpdate[i];
		auto n = sControlState.mKeyboardHeld[i];

		if( !o && n )
		{
			sControlState.mKeyboardPressed[i] = i;
		}
		else
		{
			sControlState.mKeyboardPressed[i] = 0;
		}

		if( o && !n )
		{
			sControlState.mKeyboardReleased[i] = i;
		}
		else
		{
			sControlState.mKeyboardReleased[i] = 0;
		}
	}
}

ControlState* GameHandler::getControlState()
{
	return &sControlState;
}
