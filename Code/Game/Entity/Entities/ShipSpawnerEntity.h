#ifndef BAWL_SHIPSPAWNERENTITY_H
#define BAWL_SHIPSPAWNERENTITY_H

#include <vector>

#include "Entity.h"

struct ShipWave
{
	enum ShipKind
	{
		SHIP_NONE     = 0x0,
		SHIP_STANDARD,

		SHIP_END      = 0xFF
	};

	std::vector<ShipKind> mShipsToSpawn;
	double mTimeToNextWave;
};

class ShipSpawnerEntity : public Entity
{

	virtual void update(StateBall *stateBallPtr, float dt, std::vector<Entity *> &fellows) override;

	void addWave(ShipWave& wave);
protected:
	std::vector<ShipWave> mWaves;
	double mTimeToNextWave;
	double mRemainingTime;
};


#endif // BAWL_SHIPSPAWNERENTITY_H
