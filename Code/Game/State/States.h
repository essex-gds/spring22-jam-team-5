#ifndef BAWL_STATEENTRY_H
#define BAWL_STATEENTRY_H

#include "Display.h"
#include "Camera.h"
#include "Level.h"

/***
 * StateBall is just a loose group of things to pass around
 * useful things like a display or level or camera should be bundled with it
 * give it to a state, pass it around to things that change state
 * like a football
 */
struct StateBall
{
	Display* mDisplay;
	Level*   mLevel;
	Camera*  mCamera;
};

class IState
{
public:
	IState();
	virtual ~IState();
	virtual enter(StateBall* stateBallPtr, IState* from) = 0;
	virtual exit(IState* to ) = 0;
	virtual tick(StateStack* stack, float dt) = 0;
private:
	StateBall* mStateBall;
};

class StateStack
{
public:
protected:
private:
};

#endif // BAWL_STATEENTRY_H
