//
// Created by talldie on 20/03/2022.
//

#include "RunnerShip.h"

RunnerShip::RunnerShip(StateBall* stateBallPtr, double x, double y)
	: EntityWithHealth(Sprite::create(TILE_RUNNER, x,y, 32, 32))
{


	mHealth = 2;
	mDisplayPtr = stateBallPtr->mDisplayPtr;
	mDisplayPtr->addSprite(mSprite);

	mXVelocity = -0.1;
	mYVelocity = 0;

	mBulletTimer = Timer(1,[&](IComponent* a){
		mCanShoot = true;
		mBulletTimer.reset();
	});
	mCanShoot = true;

	if(mY < mDisplayPtr->getHeight() /2)
	{
		mSprite->mFlip = SDL_FLIP_VERTICAL;
	}
}

RunnerShip::~RunnerShip()
{
	mDisplayPtr->removeSprite(mSprite);
	free(mSprite);
}

void RunnerShip::update(StateBall* stateBallPtr, float dt, std::vector<Entity*> &fellows)
{
	mBulletTimer.update(*this,dt);
	if(mCanShoot)
	{
		mCanShoot = false;
		Bullet* bullet = new Bullet(stateBallPtr, mX, mY, this);
		bullet->setYDir(-1);
		if(mY < mDisplayPtr->getHeight() /2)
		{
			bullet->setYDir(1);
		}
		fellows.push_back(bullet);
	}

	if(mX < 0 -32)
	{
		fellows.erase( std::remove(fellows.begin(), fellows.end(), this), fellows.end() );
		delete this;
		return;
	}

	EntityWithHealth::update(stateBallPtr, dt, fellows);
}
