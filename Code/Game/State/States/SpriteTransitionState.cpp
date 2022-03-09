//
// Created by talldie on 07/03/2022.
//

#include "SpriteTransitionState.h"

SpriteTransitionState::SpriteTransitionState(Sprite* spritePtr, double dstX, double dstY, double speed, std::function<void(Sprite*)> completedCallBack)
: IState()
{
	mCompletedCallBack = completedCallBack;

	mSpritePtr = spritePtr;
	mSpeed     = speed;
	mDX        = dstX - mSpritePtr->mX;
	mDY        = dstY - mSpritePtr->mY;
	mDstX      = std::abs(mDX);
	mDstY      = std::abs(mDX);
}

void SpriteTransitionState::enter(StateStack* stack, StateBall* stateBallPtr, IState* from)
{
	GLOG_INFO("SpriteTransitionState pushed");
}

void SpriteTransitionState::exit(StateStack* stack, StateBall* stateBallPtr, IState* to)
{
	GLOG_INFO("SpriteTransitionState popped");
	if(mCompletedCallBack)
	{
		// notify transition has ended
		mCompletedCallBack(mSpritePtr);
	}
}

void SpriteTransitionState::tick(StateStack* stack, StateBall* stateBallPtr, float dt)
{
	double dX = mDX * mSpeed  * dt;
	double dY = mDY * mSpeed  * dt;

	if( mDstX >= 0 || mDstY >= 0 )
	{
		mSpritePtr->mX += dX;
		mSpritePtr->mY += dY;

		mDstX -= std::abs(dX);
		mDstY -= std::abs(dY);
	}
	else
	{
		if( this == stack->top()) // pop when it's safe to do so
		{                         // not the best system as it can get buried
			stack->pop();     // just don't bury it in a ton of states I guess?
		}                         // _EWA_REVISIT_ : do it better!
	}
}
