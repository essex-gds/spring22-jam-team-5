#ifndef BAWL_BOSSSHIP_H
#define BAWL_BOSSSHIP_H

#include <cstdlib>
#include <ctime>

#include "Display.h"
#include "TileMapEnum.h"

#include "EntityWithHealth.h"
#include "Bullet.h"

#include "Timer.h"
#include "Pointer.h"



class BossShip : public EntityWithHealth
{
public:

	BossShip(StateBall* stateBallPtr, double x, double y);

	~BossShip();

	void update(StateBall *stateBallPtr, float dt, std::vector<Entity *> &fellows) override;

protected:

	enum Phase
	{
		PHASE_NORM,
		PHASE_ROT,
		PHASE_UNROT,
		PHASE_DASH,
		PHASE_SHOOT,
		PHASE_MEGA_SHOOT,
		PHASE_SPAWN,
		PHASE_SPAWN_DONE,
	};
	int phase;

	Display* mDisplayPtr;

	Timer mBulletTimer;
	Timer mMoveTimer;
	Timer mPhaseTimer;

	Pointer playerPointer;

	bool mCanShoot = false;
	bool mCanHit;

};


#endif // BAWL_BOSSSHIP_H
