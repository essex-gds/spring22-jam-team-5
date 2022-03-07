#include "TestState.h"

static Sprite* s;

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
	stateBallPtr->repack();


	hash_t hash =TextureMap::requestTexture("BLANK_TEXTURE.bmp");
	stateBallPtr->mDisplayPtr->setTexture(0, hash);

	hash =TextureMap::requestTexture("TEST_TEXTURE.bmp");
	stateBallPtr->mDisplayPtr->setTexture(1, hash);

	hash =TextureMap::requestTexture("CIRC_TEXTURE.bmp");
	stateBallPtr->mDisplayPtr->setTexture(3, hash);

	s = (Sprite*) malloc(sizeof(Sprite));

	s->mTileIndex = 3;
	s->mWidth =  96;
	s->mHeight = 96;
	s->mX = 0;
	s->mY = 0;

	stateBallPtr->mDisplayPtr->addSprite(s);

	memset(l->mTileMap,-1,l->mWidth * l->mHeight);

}

void TestState::exit(StateStack* stack, IState* to)
{
	GLOG_INFO("TestState popped");
}

void TestState::tick(StateStack* stack, float dt)
{
	s->mX += 10 * dt;
}
