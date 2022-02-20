#include "StateStack.h"

StateStack::StateStack()
{
	mStatesPtrArray = (IState**) calloc( INITIAL_STATES_STACK_SIZE, sizeof(IState*) );
}

StateStack::~StateStack()
{
	free(mStatesPtrArray);
}

void StateStack::push(IState* newState)
{
	mStatesPtrArray[mStatesReadHead++] = newState;
}

IState* StateStack::pop()
{
	return mStatesPtrArray[mStatesReadHead--];
}

void StateStack::update(float dt)
{
	mStatesPtrArray[mStatesReadHead]->tick(this, dt);
}
