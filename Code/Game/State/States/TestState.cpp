#include "TestState.h"

void TestState::enter(StateBall* stateBallPtr, IState* from)
{
	GLOG_INFO("TestState pushed");
	stateBallPtr->mDisplayPtr->showWindow();

	mLevel  = {};
	mCamera = {};

	mLevel.init(640,480);
	mCamera.init(16,16);

	stateBallPtr->mLevel     = &mLevel;
	stateBallPtr->mCameraPtr = &mCamera;

}

void TestState::exit(StateStack* stack, IState* to)
{
	GLOG_INFO("TestState popped");
}

void TestState::tick(StateStack* stack, float dt)
{
	if( GameHandler::getControlState()->keyboardState[SDL_SCANCODE_W] )
	{
		printf("W-DOWN\n");
	}

	if( GameHandler::getControlState()->keyboardState[SDL_SCANCODE_A] )
	{
		printf("A-DOWN\n");
	}

	if( GameHandler::getControlState()->keyboardState[SDL_SCANCODE_S] )
	{
		printf("S-DOWN\n");
	}

	if( GameHandler::getControlState()->keyboardState[SDL_SCANCODE_D] )
	{
		printf("D-DOWN\n");
	}
}
