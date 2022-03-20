//
// Created by talldie on 20/03/2022.
//

#include "PlayerHeath.h"

PlayerHeath::PlayerHeath(StateBall* stateBallPtr , EntityWithHealth* player)
	: Entity(Sprite::create(TILE_BLUE,0,0,32, player->getHealth() * 10 ))
{
	stateBallPtr->mDisplayPtr->addSprite(mSprite);
}

PlayerHeath::~PlayerHeath()
{

}

void PlayerHeath::update(StateBall* stateBallPtr, float dt, std::vector<Entity*> &fellows)
{
	mWidth = mPlayer->getHealth() * 10;
	Entity::update(stateBallPtr, dt, fellows);
}
