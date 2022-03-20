#ifndef BAWL_SHIPSPAWNERENTITY_H
#define BAWL_SHIPSPAWNERENTITY_H

#include <vector>
#include <deque>

#include "Entity.h"
#include "StandardShip.h"
#include "SeekerShip.h"
#include "RunnerShip.h"
#include "FatShip.h"
#include "BossShip.h"

enum ShipKind
{
	SHIP_NONE     = 0x0,
	SHIP_STANDARD,
	SHIP_SEEKER,
	SHIP_FAT,
	SHIP_RUNNER,
	SHIP_BOSS,
	SHIP_END      = 0xFF
};


struct ShipWave
{
	std::vector<ShipKind> mShipsToSpawn;
	double mTimeToNextWave;
};

class ShipSpawnerEntity : public Entity
{
public:
	inline ShipSpawnerEntity() : Entity(Sprite::create(-1,-1000,-1000,0,0)){ mWaves = {}; }

	virtual void update(StateBall *stateBallPtr, float dt, std::vector<Entity *> &fellows) override;

	void addWave(ShipWave* wave);
protected:
	std::deque<ShipWave*> mWaves;
	double mTimeToNextWave;
	double mRemainingTime;
};


#endif // BAWL_SHIPSPAWNERENTITY_H
