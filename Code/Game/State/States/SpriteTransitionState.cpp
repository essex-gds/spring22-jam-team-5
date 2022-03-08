//
// Created by talldie on 07/03/2022.
//

#include "SpriteTransitionState.h"

SpriteTransitionState::SpriteTransitionState(Sprite* spritePtr, int32_t dstX, int32_t dstY, uint32_t speed, TransitionFinishedCallBack_t transitionFinishedCallBack)
: IState()
{
	mSpritePtr = spritePtr;
	mSpeed     = speed;
	mTransitionFinishedCallBack = transitionFinishedCallBack;
	mDX = dstX - mSpritePtr->mX;
	mDY = dstY - mSpritePtr->mY;
}

void SpriteTransitionState::enter(StateStack* stack, StateBall* stateBallPtr, IState* from)
{

}

void SpriteTransitionState::exit(StateStack* stack, StateBall* stateBallPtr, IState* to)
{
	if(mTransitionFinishedCallBack)
	{
		// notify transition has ended
		mTransitionFinishedCallBack(mSpritePtr);
	}
}

void SpriteTransitionState::tick(StateStack* stack, StateBall* stateBallPtr, float dt)
{
	mSpritePtr->mX += mDX * dt;
	mSpritePtr->mY += mDY * dt;
}
