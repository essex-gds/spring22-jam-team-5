#include "Player.h"

Player::Player(StateBall* stateBallPtr)
	: EntityWithHealth    (Sprite::create(PLAYER_TEXTURE,64,64,64,64))
{
	mDisplayPtr = stateBallPtr->mDisplayPtr;
	mDisplayPtr->addSprite(mSprite);

	mVSpeed = 100;
	mHSpeed = 100;

	mCanShoot    = false;
	mMultiShoot  = 0;
	mBulletTimer = Timer(0.3,[&](IComponent* a){
		mCanShoot = true;
		mBulletTimer.reset();
	});

	setHealth(100);
	setHealth(100);
}

Player::~Player()
{
	mDisplayPtr->removeSprite(mSprite);
	free(mSprite);
}

void Player::update(StateBall* stateBallPtr, float dt, std::vector<Entity*> &fellows)
{
	stateBallPtr->mCameraPtr->mSubX += 12 * dt;

	if(GameHandler::getControlState()->mKeyboardHeld[SDL_SCANCODE_S])
	{
		if(mY + mHeight < stateBallPtr->mDisplayPtr->getHeight() - stateBallPtr->mDisplayPtr->getTileHeight())
		{
			mYVelocity += mVSpeed * dt;
		}
	}

	if(GameHandler::getControlState()->mKeyboardHeld[SDL_SCANCODE_W])
	{
		if(mY - mHeight > stateBallPtr->mDisplayPtr->getTileHeight()) // can't go over the top 2 tiles
		{
			mYVelocity -= mVSpeed * dt;
		}
	}

	if(GameHandler::getControlState()->mKeyboardHeld[SDL_SCANCODE_A])
	{
		mXVelocity -= mHSpeed * dt;
	}

	if(GameHandler::getControlState()->mKeyboardHeld[SDL_SCANCODE_D])
	{
		mXVelocity += mHSpeed * dt;
	}

	if(GameHandler::getControlState()->mKeyboardHeld[SDL_SCANCODE_SPACE]
	&& mCanShoot)
	{
		mCanShoot = false;
		double x = mX + mWidth;
		double y= mY;

		Bullet* bullet = new Bullet(stateBallPtr, x, y,this);
		bullet->setXDir(1);
		fellows.push_back(bullet);

		if(mMultiShoot == 1)
		{
			bullet = new Bullet(stateBallPtr, x, y,this);
			bullet->setXDir(1);
			bullet->setYDir(.25);
			fellows.push_back(bullet);

			bullet = new Bullet(stateBallPtr, x, y,this);
			bullet->setXDir(1);
			bullet->setYDir(-.25);
			fellows.push_back(bullet);
		}
	}

	mXVelocity *= 0.80;
	mYVelocity *= 0.80;

	mBulletTimer.update(*this, dt);

	Entity::update(stateBallPtr,dt, fellows);
}

double Player::getHSpeed()
{
	return mHSpeed;
}

void Player::setHSpeed(double hSpeed)
{
	mHSpeed = hSpeed;
}

double Player::getVSpeed()
{
	return mVSpeed;
}

void Player::setVSpeed(double vSpeed)
{
	mVSpeed = vSpeed;
}
