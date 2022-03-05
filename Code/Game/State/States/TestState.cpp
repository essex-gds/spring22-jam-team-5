#include "TestState.h"

void TestState::enter(StateBall* stateBallPtr, IState* from)
{
	GLOG_INFO("TestState pushed");
	stateBallPtr->mDisplayPtr->showWindow();

	mLevel  = {};
	mCamera = {};

	mLevel.init(32,32);
	mCamera.init(16,16);

	stateBallPtr->mLevel     = &mLevel;
	stateBallPtr->mCameraPtr = &mCamera;

	hash_t hast =TextureMap::requestTexture("TEST_TEXTURE.bmp");
	stateBallPtr->mDisplayPtr->setTexture(1, hast);

	mLevel.mTileMap[15] = 1;
	mLevel.mTileMap[30] = 1;
	mLevel.mTileMap[60] = 1;

	stateBallPtr->repack();
}

void TestState::exit(StateStack* stack, IState* to)
{
	GLOG_INFO("TestState popped");
}

void TestState::tick(StateStack* stack, float dt)
{
	printf("%f \n", mCamera.mSubX);
	printf("%f \n", mCamera.mSubY);

	if( GameHandler::getControlState()->keyboardState[SDL_SCANCODE_W] )
	{
		mCamera.mSubY += 20 * dt;
	}

	if( GameHandler::getControlState()->keyboardState[SDL_SCANCODE_A] )
	{
		mCamera.mSubX -= 20 * dt;
	}

	if( GameHandler::getControlState()->keyboardState[SDL_SCANCODE_S])
	{
		mCamera.mSubY -= 20 * dt;
	}

	if( GameHandler::getControlState()->keyboardState[SDL_SCANCODE_D] )
	{
		mCamera.mSubX += 20 * dt;
	}
}
