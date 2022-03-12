#include "StateStack.h"

void StateBall::repack()
{
	mDisplayPtr->setCamera(mCameraPtr);
	mDisplayPtr->setLevel(mLevel);
}

StateStack::StateStack()
{
	mStatesPtrArray  = {};
	mStateBall = {};
}

StateStack::~StateStack()
{

}

void StateStack::push(IState* newState)
{
	IState* topState = top();
	mStatesPtrArray.push_back(newState);
	newState->enter(this, &mStateBall, topState);
}

void StateStack::pop()
{
	IState* topState = top();
	mStatesPtrArray.pop_back();
	topState->exit(this,&mStateBall,top());
}

IState* StateStack::top()
{
	if(!mStatesPtrArray.empty())
	{

		return mStatesPtrArray.back();
	}
	else
	{
		return nullptr;
	}
}

void StateStack::update(float dt)
{
	std::vector<IState*> copyArr(mStatesPtrArray);

	for( size_t i = copyArr.size()-1; i >= 0; i--)
	{
		IState* current = copyArr[i];
		if(current != nullptr)
		{
			current->tick(this, &mStateBall, dt);
			if (!current->isTransparent())
			{
				break;
			}
		}
	}
}