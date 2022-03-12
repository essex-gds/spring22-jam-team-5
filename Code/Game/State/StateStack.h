#ifndef BAWL_STATEENTRY_H
#define BAWL_STATEENTRY_H

#include <vector>

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
	Display* mDisplayPtr;
	Level*   mLevel;
	Camera*  mCameraPtr;

	void repack();
};

class StateStack
{
public:
	StateStack();

	~StateStack();

	void push(IState* newState);

	void pop();

	IState* top();

	void update(float dt);

private:

	static inline const size_t INITIAL_STATES_STACK_SIZE = 4;

	std::vector<IState*> mStatesPtrArray;

	StateBall mStateBall;
};

#endif // BAWL_STATEENTRY_H
