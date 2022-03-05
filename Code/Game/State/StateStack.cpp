#include "StateStack.h"

StateStack::StateStack()
{
	mStatesPtrArray  = (IState**) calloc( INITIAL_STATES_STACK_SIZE, sizeof(IState*) );
	mStatesArraySize = INITIAL_STATES_STACK_SIZE;
	mStatesWriteHead = 0;

	mStateBall = {};
}

StateStack::~StateStack()
{
	free(mStatesPtrArray);
}

void StateStack::push(IState* newState)
{
	IState* topState = nullptr;

	if(mStatesWriteHead)
	{
		topState = mStatesPtrArray[mStatesWriteHead - 1];
	}

	mStatesPtrArray[mStatesWriteHead] = newState;
	mStatesPtrArray[mStatesWriteHead]->enter(&mStateBall, topState);
	mStatesWriteHead+=1;
}

void StateStack::pop()
{
	if(mStatesWriteHead)
	{
		IState* topState     = mStatesPtrArray[--mStatesWriteHead];
		IState* nextTopState = nullptr;

		if (mStatesWriteHead)
		{
			nextTopState = mStatesPtrArray[mStatesWriteHead];
		}

		topState->exit(this, nextTopState);

		free(topState);
	}
}

void StateStack::update(float dt)
{
	if(mStatesWriteHead) // mStatesWriteHead > 0 to stop underflow ( also it means no values on stack )
	{
		size_t  readHead = mStatesWriteHead-1;
		IState* current = nullptr;
		bool currentIsTransparent;
		do
		{
			current = mStatesPtrArray[readHead];
			currentIsTransparent = current->isTransparent();
			current->tick(this, dt);
			readHead--;
		}
		while ( currentIsTransparent && readHead > 0);
	}
}
