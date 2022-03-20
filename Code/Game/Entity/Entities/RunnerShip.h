#ifndef BAWL_RUNNERSHIP_H
#define BAWL_RUNNERSHIP_H

#include "Display.h"
#include "TileMapEnum.h"

#include "Entity.h"
#include "EntityWithHealth.h"
#include "Bullet.h"

#include "Timer.h"

class RunnerShip : public EntityWithHealth
{
public:
	HAS_ID("BAD----");
	RunnerShip(StateBall* stateBallPtr, double x, double y);
	~RunnerShip();

	void update(StateBall *stateBallPtr, float dt, std::vector<Entity *> &fellows) override;

protected:

	Display* mDisplayPtr;

	Timer mBulletTimer;

	bool mCanShoot = false;
};


#endif // BAWL_RUNNERSHIP_H
