#ifndef BAWL_GAMEHANDLER_H
#define BAWL_GAMEHANDLER_H

#include "SDL.h"

#include "Display.h"
#include "TextureMap.h"
#include "StateStack.h"
#include "EntryState.h"

struct ControlState
{
	int32_t      mKeyboardSize;
	const Uint8* mKeyboardHeld;
	      Uint8* mKeyboardPressed;
	      Uint8* mKeyboardReleased;
};

class GameHandler
{
public:

	GameHandler();

	~GameHandler();

	void enter();

	void updateLoop();

	void leave();

	void render();

	void updateSDL();

	static ControlState* getControlState();

private:

	static inline ControlState sControlState;

	Display    mDisplay;

	StateStack mStateStack;

	bool       mCloseRequested;
};

#endif // BAWL_GAMEHANDLER_H
