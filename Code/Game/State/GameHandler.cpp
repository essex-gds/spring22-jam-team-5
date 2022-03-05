#include "GameHandler.h"

GameHandler::GameHandler()
{
	mStateStack = {};
	mCloseRequested = false;

	sControlState.keyboardState = SDL_GetKeyboardState(nullptr);
}

GameHandler::~GameHandler()
{

}

void GameHandler::enter()
{
	// Init
	mDisplay.init();
	mDisplay.createWindow(800,800,"Bawl");
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
		mStateStack.update(0);
		render();
		updateSDL();
	}
}

void GameHandler::leave()
{

}

void GameHandler::render()
{

}

void GameHandler::updateSDL()
{
	SDL_Event event;

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
}

ControlState* GameHandler::getControlState()
{
	return &sControlState;
}
