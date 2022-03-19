//
// Created by talldie on 19/03/2022.
//

#include "ShipSpawnerEntity.h"

void ShipSpawnerEntity::update(StateBall* stateBallPtr, float dt, std::vector<Entity*> &fellows)
{
	mRemainingTime -= dt;

	if(mRemainingTime < 0)
	{
		auto wave = mWaves.front();

	}

	Entity::update(stateBallPtr, dt, fellows);
}

void ShipSpawnerEntity::addWave(ShipWave& wave)
{
	mWaves.push_back(wave);
}
