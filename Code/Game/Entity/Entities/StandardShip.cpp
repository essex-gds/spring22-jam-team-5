#include "StandardShip.h"

StandardShip::StandardShip(StateBall* stateBallPtr, double x, double y)
	: EntityWithHealth(Sprite::create(PLAYER_TEXTURE,x,y,64,64))
	,	mShootTimer(1.5,[&](IComponent*){
		mCanShoot = true;
		mShootTimer.reset();
	})
{
	mSprite->mFlip = SDL_FLIP_HORIZONTAL;
	mDisplayPtr = stateBallPtr->mDisplayPtr;
	mDisplayPtr->addSprite(mSprite);
	setHealth(2);

	mXVelocity = -0.3       ;
}

StandardShip::~StandardShip()
{
	mDisplayPtr->removeSprite(mSprite);
	free(mSprite);
}

void StandardShip::update(StateBall* stateBallPtr, float dt, std::vector<Entity*> &fellows)
{
	Entity::update(stateBallPtr, dt, fellows);
	mShootTimer.update(*this, dt);

	if(mCanShoot)
	{
		mCanShoot = false;
		auto* b = new Bullet(stateBallPtr, mX, mY,this);
		b->setXDir(-1);
		fellows.push_back(b);
	}

	if(mHealth < 1)
	{
		fellows.erase(std::remove(fellows.begin(), fellows.end(), this), fellows.end());
		delete this;
	}
}
