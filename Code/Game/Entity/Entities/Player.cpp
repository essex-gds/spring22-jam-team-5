#include "Player.h"

Player::Player(Display* displayPtr)
	: Entity    ( (Sprite*) malloc(sizeof(Sprite) ) )
	, mDisplayPtr  (displayPtr)
{
	mSprite->mTileIndex = PLAYER_TEXTURE;
	mSprite->mWidth = 64;
	mSprite->mHeight = 64;

	mDisplayPtr->addSprite(mSprite);

	mVSpeed = 200;
	mHSpeed = 100;
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
		mY += mVSpeed * dt;
	}

	if(GameHandler::getControlState()->mKeyboardHeld[SDL_SCANCODE_W])
	{
		mY -= mVSpeed * dt;
	}

	if(GameHandler::getControlState()->mKeyboardHeld[SDL_SCANCODE_A])
	{
		mX -= mHSpeed * dt;
	}

	if(GameHandler::getControlState()->mKeyboardHeld[SDL_SCANCODE_D])
	{
		mX += mHSpeed * dt;
	}

	if(GameHandler::getControlState()->mKeyboardHeld[SDL_SCANCODE_SPACE])
	{
		double x = mX + mWidth;
		double y= mY + mHeight/2;
		Bullet* bullet = new Bullet(stateBallPtr, x, y);
		bullet->setXDir(1);
		fellows.push_back(bullet);

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
