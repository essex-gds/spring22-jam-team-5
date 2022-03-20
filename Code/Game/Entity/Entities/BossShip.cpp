#include "BossShip.h"

BossShip::BossShip(StateBall* stateBallPtr, double x, double y)
	: EntityWithHealth( Sprite::create(TILE_BOSS, x,y, 66*1.5, 95*1.5))
{
	mDisplayPtr = stateBallPtr->mDisplayPtr;
	mDisplayPtr->addSprite(mSprite);
	phase = PHASE_ROT;

	mHealth = 100;
	mYVelocity = 0;
	mXVelocity = -0;

	mPhaseTimer = Timer(10, [&](auto ptr){});

	mBulletTimer = Timer(0.5,[&](IComponent* a){
		mCanShoot = true;
		mBulletTimer.reset();
	});
}

BossShip::~BossShip()
{
	mDisplayPtr->removeSprite(mSprite);
	free(mSprite);
}

void BossShip::update(StateBall* stateBallPtr, float dt, std::vector<Entity*> &fellows)
{
	if(mX < - 100)
	{
		float rad = (float)rand() / (float)INT32_MAX;
		mX = mDisplayPtr->getWidth() + 100;
		mY =  mDisplayPtr->getHeight() * rad;
	}

	auto x = mX;
	auto y = mY;
	srand(time(NULL));
	int pick =  ((float)rand() / (float)INT32_MAX) * 5u;
	

#include <cstdlib>
	switch (phase)
	{
		case PHASE_NORM:
			switch (pick)
			{
				case 1:
					phase = PHASE_ROT;
					break;
				case 2:
					phase = PHASE_MEGA_SHOOT;
					mPhaseTimer = Timer(4, [&](auto* ptr)
					{
						phase = PHASE_NORM;
					});
					break;

				case 3:
					phase = PHASE_SHOOT;
					mPhaseTimer = Timer(4, [&](auto* ptr)
					{
						phase = PHASE_NORM;
					});
					break;

				case 4:
					phase = PHASE_SPAWN;
					mPhaseTimer = Timer(2, [&](auto* ptr)
					{
						phase = PHASE_ROT;
					});
					break;
			}
			break;

		case PHASE_ROT:
			if(mSprite->mAngle + 90 > 0)
			{
				mSprite->mAngle -= dt * 35;
			}
			else
			{
				phase = PHASE_DASH;
				mXVelocity = -4.5;
				mPhaseTimer = Timer(8, [&](auto* ptr)
				{
					phase = PHASE_UNROT;
					mPhaseTimer.reset();
				});
			}
			break;

		case PHASE_UNROT:
			if(mSprite->mAngle < 0)
			{
				mSprite->mAngle += dt * 35;
			}
			else
			{
				phase = PHASE_NORM;
				mXVelocity = -0.1;
			}
			break;

		case PHASE_SHOOT:
			mBulletTimer.update(*this,dt);

			if(mCanShoot)
			{
				mCanShoot = false;
				Bullet* bullet = new Bullet(stateBallPtr, x, y, this);
				bullet->setXDir(-1);
				fellows.push_back(bullet);

				bullet = new Bullet(stateBallPtr, x, y - 16, this);
				bullet->setXDir(-1);
				bullet->setYDir(-.3);
				fellows.push_back(bullet);

				bullet = new Bullet(stateBallPtr, x, y + 16, this);
				bullet->setXDir(-1);
				bullet->setYDir(.3);
				fellows.push_back(bullet);

				bullet = new Bullet(stateBallPtr, x+ mSprite->mWidth, y, this);
				bullet->setXDir(1);
				fellows.push_back(bullet);

				bullet = new Bullet(stateBallPtr, x+ mSprite->mWidth, y - 16, this);
				bullet->setXDir(1);
				bullet->setYDir(-.3);
				fellows.push_back(bullet);

				bullet = new Bullet(stateBallPtr, x+ mSprite->mWidth, y + 16, this);
				bullet->setXDir(1);
				bullet->setYDir(.3);
				fellows.push_back(bullet);
			}
			break;

		case PHASE_MEGA_SHOOT:
			mBulletTimer.update(*this, dt);

			if(mCanShoot)
			{
				mCanShoot = false;
				Bullet* bullet = new Bullet(stateBallPtr, x, y, this);
				bullet->setXDir(-1);
				fellows.push_back(bullet);

				bullet = new Bullet(stateBallPtr, x, y - 16, this);
				bullet->setXDir(-1);
				bullet->setYDir(-.15);
				fellows.push_back(bullet);

				bullet = new Bullet(stateBallPtr, x, y - 30, this);
				bullet->setXDir(-1);
				bullet->setYDir(-.3);
				fellows.push_back(bullet);

				bullet = new Bullet(stateBallPtr, x, y + 16, this);
				bullet->setXDir(-1);
				bullet->setYDir(.15);
				fellows.push_back(bullet);

				bullet = new Bullet(stateBallPtr, x, y + 30, this);
				bullet->setXDir(-1);
				bullet->setYDir(.3);
				fellows.push_back(bullet);


				bullet = new Bullet(stateBallPtr, x + mSprite->mWidth, y, this);
				bullet->setXDir(1);
				fellows.push_back(bullet);

				bullet = new Bullet(stateBallPtr, x + mSprite->mWidth, y - 16, this);
				bullet->setXDir(1);
				bullet->setYDir(-.15);
				fellows.push_back(bullet);

				bullet = new Bullet(stateBallPtr, x + mSprite->mWidth, y - 30, this);
				bullet->setXDir(1);
				bullet->setYDir(-.3);
				fellows.push_back(bullet);

				bullet = new Bullet(stateBallPtr, x + mSprite->mWidth, y + 16, this);
				bullet->setXDir(1);
				bullet->setYDir(.15);
				fellows.push_back(bullet);

				bullet = new Bullet(stateBallPtr, x + mSprite->mWidth, y + 30, this);
				bullet->setXDir(1);
				bullet->setYDir(.3);
				fellows.push_back(bullet);

			}

			break;

		case PHASE_SPAWN:
			phase = PHASE_SPAWN_DONE;
			fellows.push_back( new SeekerShip(stateBallPtr, mX,mY - mSprite->mHeight/2));
			fellows.push_back( new SeekerShip(stateBallPtr, mX,mY + mSprite->mHeight/2));
			break;

	}

	if( mX < ( mDisplayPtr->getWidth() - mDisplayPtr->getWidth()/3 ) && phase != PHASE_DASH)
	{
		mXVelocity = 0.5;
	}
	else if (phase != PHASE_DASH)
	{
		mXVelocity = -0.1;
	}

	if( mY < mDisplayPtr->getHeight()/2 && phase != PHASE_DASH)
	{
		mYVelocity = 0.1;
	}
	else if (phase != PHASE_DASH)
	{
		mYVelocity = -0.1;
	}


	auto fels = Entity::fellowsWithinRange(mX, mY, mSprite->mWidth, fellows);
	fels.erase(std::remove(fels.begin(), fels.end(), this), fels.end());
	bool playerHit = false;
	if(!fels.empty())
	{
		for(auto* e : fels)
		{
			if(Entity::cmpID(e->getID(), Player::mID))
			{
				playerHit = true;
				if(mCanHit)
				{
					auto player =(EntityWithHealth*) e;
					player->setHealth(player->getHealth() - 3);
					mCanHit = false;
				}
			}
		}
	}
	if(!playerHit)
	{
		mCanHit = true;
	}

	mPhaseTimer.update(*this,dt);

	if(mHealth < 0)
	{
		GameState::gameWin();
	}

	EntityWithHealth::update(stateBallPtr, dt, fellows);
}
