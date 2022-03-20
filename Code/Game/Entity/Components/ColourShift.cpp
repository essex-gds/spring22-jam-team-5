//
// Created by talldie on 20/03/2022.
//

#include "ColourShift.h"

ColourShift::ColourShift(Entity* entity, uint8_t r, uint8_t g, uint8_t b, double speed, double duration, bool revert)

	: mTarget    (entity)
	, mRFrom     (mTarget->getSprite()->mRShift)
	, mGFrom     (mTarget->getSprite()->mGShift)
	, mBFrom     (mTarget->getSprite()->mBShift)
	, mRCurr     (mRFrom)
	, mGCurr     (mGFrom)
	, mBCurr     (mBFrom)
	, mRTo       (r)
	, mGTo       (g)
	, mBTo       (b)
	, mSpeed     (speed)
	, mDuration  (duration)
	, mRevert    (revert)
	, mReverting (false)
{}

void ColourShift::update(Entity &host, double dt)
{
	mDuration-=dt;
	if( mDuration > 0 )
	{
		if (!mReverting)
		{
			if (mTarget->getSprite()->mRShift != mRTo)
			{
				mRCurr += ( mRFrom - mRTo ) * dt * mSpeed;
				mTarget->getSprite()->mRShift = mRCurr;
			}

			if (mTarget->getSprite()->mGShift != mGTo)
			{
				mGCurr += ( mGFrom - mGTo ) * dt * mSpeed;
				mTarget->getSprite()->mGShift = mGCurr;
			}

			if (mTarget->getSprite()->mBShift != mBTo)
			{
				mRCurr += ( mBFrom - mBTo ) * dt * mSpeed;
				mTarget->getSprite()->mBShift = mBCurr;
			}
		}
	}
	else
	{
		mTarget->getSprite()->mRShift = mRFrom;
		mTarget->getSprite()->mGShift = mGFrom;
		mTarget->getSprite()->mBShift = mBFrom;
		host.removeComponent(this);
	}
}


