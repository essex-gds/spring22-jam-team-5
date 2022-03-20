//
// Created by talldie on 19/03/2022.
//

#include "SeekerShip.h"

SeekerShip::SeekerShip(StateBall* stateBallPtr, double x, double y)
	: EntityWithHealth(Sprite::create(TILE_SEEKER, x,y,32,64))
{
	mSeeking = false;
	mHealth = 3;
	mDisplayPtr = stateBallPtr->mDisplayPtr;
	mDisplayPtr->addSprite(mSprite);

	mXVelocity = -0.2;
	mYVelocity =  0;
}

SeekerShip::~SeekerShip()
{
	mDisplayPtr->removeSprite(mSprite);
	free(mSprite);
}


void SeekerShip::update(StateBall* stateBallPtr, float dt, std::vector<Entity*> &fellows)
{
	auto fels = Entity::fellowsWithinRange(mX,mY,460, fellows);

	if (!mSeeking)
	{
		for (auto &e: fels)
		{
			if (Entity::cmpID(e->getID(), Player::mID))
			{
				mPlayerPoint = Pointer(this, e);
				mSprite->mTileIndex = TILE_SEEKER_ACTIVE;
				mSeeking = true;
			}
		}
	}
	else
	{
		mPlayerPoint.update(*this,dt);
		mXVelocity = mPlayerPoint.getXVel();
		mYVelocity = mPlayerPoint.getYVel();
		mSprite->mAngle = mPlayerPoint.getAngle();
	}

	EntityWithHealth::update(stateBallPtr, dt, fellows);
}
