#include "Player.h"

Player::Player(StateBall* stateBallPtr)
	: EntityWithHealth    (Sprite::create(TILE_PLAYER,64,64,64,64))
{
	mSprite->mTileIndex = PLAYER_TEXTURE;
	mSprite->mWidth = 64;
	mSprite->mHeight = 64;

	mDisplayPtr->addSprite(mSprite);

	mVSpeed = 100;
	mHSpeed = 100;

	mCanShoot    = false;
	mMultiShoot  = 0;
	mBulletTimer = Timer(0.3,[&](IComponent* a){
		mCanShoot = true;
		mBulletTimer.reset();
	});
}

Player::~Player()
{
	mDisplayPtr->removeSprite(mSprite);
	free(mSprite);
}

void Player::update(StateBall* stateBallPtr, float dt, std::vector<Entity*> &fellows)
{
	if(GameHandler::getControlState()->mKeyboardHeld[SDL_SCANCODE_S])
	{
		mYVelocity += mVSpeed * dt;
	}

	if(GameHandler::getControlState()->mKeyboardHeld[SDL_SCANCODE_W])
	{
		mYVelocity -= mVSpeed * dt;
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
		double y= mY + mHeight/2;

		Bullet* bullet = new Bullet(stateBallPtr, x, y);
		bullet->setXDir(1);
		fellows.push_back(bullet);

		if(mMultiShoot == 1)
		{
			bullet = new Bullet(stateBallPtr, x, y);
			bullet->setXDir(1);
			bullet->setYDir(.25);
			fellows.push_back(bullet);

			bullet = new Bullet(stateBallPtr, x, y);
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
