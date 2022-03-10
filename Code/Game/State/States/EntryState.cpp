#include "EntryState.h"

EntryState::EntryState(Display* display)
{
	mDisplayPtr = display;
}

void EntryState::enter(StateStack* stack, StateBall* stateBallPtr, IState* from)
{
	GLOG_INFO("EntryState pushed");
	if(from != nullptr)
	{
		GLOG_INFO("Entry has been called from an exising state, are you sure you wanted to do that?");
	}

	stateBallPtr->mDisplayPtr = mDisplayPtr;
	stateBallPtr->mDisplayPtr->showWindow();

	hash_t texHash;
	texHash = TextureMap::requestTexture("A.bmp");
	mDisplayPtr->setTexture('A',texHash);
	texHash = TextureMap::requestTexture("2A.bmp");
	mDisplayPtr->setTexture(2 * 'A',texHash);


}

void EntryState::exit(StateStack* stack, StateBall* stateBallPtr, IState* to)
{
	GLOG_INFO("EntryState popped");
	stack->push(new TestState());
}

void EntryState::tick(StateStack* stack, StateBall* stateBallPtr, float dt)
{
	stack->pop();
}


