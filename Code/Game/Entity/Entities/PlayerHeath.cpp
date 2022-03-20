#include "PlayerHeath.h"

PlayerHeath::PlayerHeath(StateBall* stateBallPtr , Player* player)
	: Entity(Sprite::create(TILE_BLUE,0,0,0, 64 ))
{
	auto health = ((EntityWithHealth*)mPlayer)->getHealth();
	mWidth = health;
	mStartingWidth = mWidth;


	stateBallPtr->mDisplayPtr->addSprite(mSprite);
	mPlayer = player;
}

PlayerHeath::~PlayerHeath()
{

}

void PlayerHeath::update(StateBall* stateBallPtr, float dt, std::vector<Entity*> &fellows)
{

	auto health = ((EntityWithHealth*) mPlayer )->getHealth();
	mWidth = health * 10;

	mSprite->mBShift = (float )(  (float) mWidth / (float) mStartingWidth ) * 255.;


	Entity::update(stateBallPtr, dt, fellows);
}
