#include "MainMenuState.h"

void MainMenuState::enter(StateStack* stack, StateBall* stateBallPtr, IState* from)
{
	stateBallPtr->mDisplayPtr->showWindow();
	mLevel  = {};
	mCamera = {};
	mLevel = Level::create(70,50);
	mCamera.init(40,40);
	mCamera.mScrollEnabled = true;
	stateBallPtr->mLevel     = mLevel;
	stateBallPtr->mCameraPtr = &mCamera;
	stateBallPtr->repack();

	memset(mLevel->mOverMap,' ',mLevel->mWidth * mLevel->mHeight);
	memset(mLevel->mCharMap,' ',mLevel->mWidth * mLevel->mHeight);
	auto* message = NString::create("LIBERATION");

	auto* opts = new std::vector<NString*>();
	opts->push_back( NString::create(" PLAY ") );
	opts->push_back( NString::create(" EXIT ") );


	auto* menu = new TextChoiceState(0,0,message, *opts, 0, [opts, stack](auto i, auto dir)
	{
		if(i == 0)
		{
			free(opts);
			stack->push(new GameState());
		}
	});

	stack->push(menu);
}

void MainMenuState::exit(StateStack* stack, StateBall* stateBallPtr, IState* to)
{

}

void MainMenuState::tick(StateStack* stack, StateBall* stateBallPtr, float dt)
{

}
