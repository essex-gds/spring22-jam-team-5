#include "Bullet.h"

Bullet::Bullet(StateBall* stateBallPtr, double x, double y, Entity* parent)
	: Entity        (Sprite::create(TILE_CIRC, x, y, 16, 16))
	, mStateBallPtr (stateBallPtr)
	, mXDir         (0)
	, mYDir         (0)
	, mParent       (parent)
	, mDMG          (1)
{
	mStateBallPtr->mDisplayPtr->addSprite(mSprite);

	if(Entity::cmpID(parent->getID(), StandardShip::mID))
	{
		bad = true;
	}
	else
	{
		bad = false;
	}
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

		if(
			Entity::cmpID(e->getID(),EntityWithHealth::mID)
		        || (Entity::cmpID(e->getID(), Player::mID) && bad)
		        || (Entity::cmpID(e->getID(), StandardShip::mID) && !bad)
		        || (Entity::cmpID(e->getID(), SeekerShip::mID)   && !bad)
		        || (Entity::cmpID(e->getID(), RunnerShip::mID)   && !bad)
			|| (Entity::cmpID(e->getID(), BossShip::mID)     && !bad)
		  )
		{
			EntityWithHealth* ent = static_cast<EntityWithHealth*>(e);
			ent->setHealth(ent->getHealth() - mDMG);
			fellows.erase( std::remove(fellows.begin(), fellows.end(), this), fellows.end() );
			delete this;
			return;
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
