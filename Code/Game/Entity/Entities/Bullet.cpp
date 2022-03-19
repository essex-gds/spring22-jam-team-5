#include "Bullet.h"

Bullet::Bullet(StateBall* stateBallPtr, double x, double y, void* parent)
	: Entity        (Sprite::create(TILE_CIRC, x, y, 16, 16))
	, mStateBallPtr (stateBallPtr)
	, mXDir         (0)
	, mYDir         (0)
{
	mSprite->mTileIndex = tileMap::CIRC_TEXTURE;
	mSprite->mX = x;
	mSprite->mY = y;
	mSprite->mWidth = 16;
	mSprite->mHeight= 16;
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
	   && mY > stateBallPtr->mDisplayPtr->getHeight() )
	{
		fellows.erase(std::remove(fellows.begin(), fellows.end(), this), fellows.end());
		delete this;
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
