#include "Bullet.h"

Bullet::Bullet(StateBall* stateBallPtr, double x, double y, void* parent)
	: Entity        (Sprite::create(TILE_CIRC, x, y, 16, 16))
	, mStateBallPtr (stateBallPtr)
	, mXDir         (0)
	, mYDir         (0)
	, mParent       (parent)
	, mDMG          (1)
{
	mStateBallPtr->mDisplayPtr->addSprite(mSprite);
}

Bullet::~Bullet()
{
	mStateBallPtr->mDisplayPtr->removeSprite(mSprite);
	free(mSprite);
}

void Bullet::update(StateBall* stateBallPtr, float dt, std::vector<Entity*> &fellows)
{
	mXVelocity = sBulletSpeed * mXDir * dt;
	mYVelocity = sBulletSpeed * mYDir * dt;
	Entity::update(stateBallPtr, dt, fellows);

	// delete when it goes of screen
	if (  mX > stateBallPtr->mDisplayPtr->getWidth()
	   || mY > stateBallPtr->mDisplayPtr->getHeight()
	   || mX < 0
	   || mY < 0
	   )
	{
		fellows.erase(std::remove(fellows.begin(), fellows.end(), this), fellows.end());
		delete this;
		return;
	}

	auto withInRange = Entity::fellowsWithinRange(mX,mY, 32, fellows);

	withInRange.erase(std::remove(withInRange.begin(), withInRange.end(), this), withInRange.end());
	withInRange.erase(std::remove(withInRange.begin(), withInRange.end(), mParent), withInRange.end());

	for(auto& e : withInRange)
	{
		if(Entity::cmpID(e->getID(),EntityWithHealth::mID))
		{
			EntityWithHealth* ent = static_cast<EntityWithHealth*>(e);
			ent->setHealth(ent->getHealth() - mDMG);
			fellows.erase( std::remove(fellows.begin(), fellows.end(), this), fellows.end() );
			delete this;
		}
	}
}

void Bullet::setXDir(double xDir)
{
	mXDir = xDir;
}

void Bullet::setYDir(double yDir)
{
	mYDir = yDir;
}
