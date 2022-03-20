#include "ShipSpawnerEntity.h"

void ShipSpawnerEntity::update(StateBall* stateBallPtr, float dt, std::vector<Entity*> &fellows)
{
	mRemainingTime -= dt;

	if(mRemainingTime < 0)
	{
		auto wave = mWaves.front();
		if(mWaves.size() && wave)
		{
			double y = stateBallPtr->mDisplayPtr->getTileHeight()*3;
			double x = stateBallPtr->mDisplayPtr->getWidth() + 100;

			for(auto& s : wave->mShipsToSpawn)
			{
				switch (s)
				{
					case SHIP_STANDARD:
						fellows.push_back(new StandardShip(stateBallPtr,x,y));
						break;

					case SHIP_SEEKER:
						fellows.push_back(new SeekerShip(stateBallPtr,x,y));
						break;

					case SHIP_RUNNER:
						fellows.push_back(new RunnerShip(stateBallPtr, x, y));
						break;

					case SHIP_BOSS:
						fellows.push_back(new BossShip(stateBallPtr, x,y));
						break;

					case SHIP_NONE:
					default:
						break;
				}
				y += stateBallPtr->mDisplayPtr->getTileHeight() * 2;
			}
			mTimeToNextWave = wave->mTimeToNextWave;
			mRemainingTime =  mTimeToNextWave;
			free(wave);
			mWaves.pop_front();
		}
	}
}

void ShipSpawnerEntity::addWave(ShipWave* wave)
{
	mWaves.push_back(wave);
}
