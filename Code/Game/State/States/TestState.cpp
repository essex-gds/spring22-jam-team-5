#include "TestState.h"

static Sprite* s;

void TestState::enter(StateStack* stack, StateBall* stateBallPtr, IState* from)
{
	GLOG_INFO("TestState pushed");
	stateBallPtr->mDisplayPtr->showWindow();

	mLevel  = {};
	mCamera = {};

	Level* l = Level::create(100,50);
	mCamera.init(70,40);

	mCamera.mScrollEnabled = true;

	stateBallPtr->mLevel     = l;
	stateBallPtr->mCameraPtr = &mCamera;
	stateBallPtr->repack();

	memset(l->mOverMap,' ',l->mWidth * l->mHeight);
	memset(l->mCharMap,' ',l->mWidth * l->mHeight);

	s = Sprite::create(3);
	stateBallPtr->mDisplayPtr->addSprite(s);


	EntityUpdateState* es = new EntityUpdateState();


	es->addEntity( new Player(stateBallPtr));

	es->addEntity( new StandardShip(stateBallPtr, 1000,100));

	stack->push(es);

}

void TestState::exit(StateStack* stack, StateBall* stateBallPtr, IState* to)
{
	GLOG_INFO("TestState popped");
}

void TestState::tick(StateStack* stack, StateBall* stateBallPtr, float dt)
{

}
