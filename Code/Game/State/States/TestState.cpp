#include "TestState.h"

void TestState::enter(StateBall* stateBallPtr, IState* from)
{
	GLOG_INFO("TestState pushed");
	stateBallPtr->mDisplayPtr->showWindow();

	mLevel  = {};
	mCamera = {};

	Level* l = Level::create(32,32);
	mCamera.init(16,16);

	mCamera.mScrollEnabled = true;

	stateBallPtr->mLevel     = l;
	stateBallPtr->mCameraPtr = &mCamera;

	hash_t hast =TextureMap::requestTexture("TEST_TEXTURE.bmp");
	stateBallPtr->mDisplayPtr->setTexture(1, hast);

	l->mTileMap[15] = 1;
	l->mTileMap[30] = 1;
	l->mTileMap[60] = 1;

	stateBallPtr->repack();
}

void TestState::exit(StateStack* stack, IState* to)
{
	GLOG_INFO("TestState popped");
}

void TestState::tick(StateStack* stack, float dt)
{
	if( GameHandler::getControlState()->keyboardState[SDL_SCANCODE_W] )
	{
		mCamera.mSubY += 50 * dt;
	}

	if( GameHandler::getControlState()->keyboardState[SDL_SCANCODE_A] )
	{
		mCamera.mSubX -= 50 * dt;
	}

	if( GameHandler::getControlState()->keyboardState[SDL_SCANCODE_S])
	{
		mCamera.mSubY -= 50 * dt;
	}

	if( GameHandler::getControlState()->keyboardState[SDL_SCANCODE_D] )
	{
		mCamera.mSubX += 50 * dt;
	}
}
