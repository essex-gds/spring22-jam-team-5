#ifndef BAWL_STATEENTRY_H
#define BAWL_STATEENTRY_H

#include "Display.h"
#include "Camera.h"
#include "Level.h"
#include "IState.h"

class IState;

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

class StateStack
{
public:
	StateStack();

	~StateStack();

	void push(IState* newState);

	IState* pop();

	void update(float dt);

private:

	const size_t INITIAL_STATES_STACK_SIZE = 4;

	size_t  mStatesArraySize;

	IState** mStatesPtrArray;

	size_t  mStatesReadHead;
};

#endif // BAWL_STATEENTRY_H
