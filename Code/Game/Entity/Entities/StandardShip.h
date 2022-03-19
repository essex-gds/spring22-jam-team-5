#ifndef BAWL_STANDARDSHIP_H
#define BAWL_STANDARDSHIP_H

#include "StateStack.h"

#include "Entity.h"
#include "EntityWithHealth.h"
#include "Bullet.h"

#include "SDL.h"
#include "Timer.h"

class StandardShip : public EntityWithHealth
{
public:
	StandardShip(StateBall* stateBallPtr ,double x, double y);
	virtual ~StandardShip();

	void update(StateBall *stateBallPtr, float dt, std::vector<Entity *> &fellows) override;

protected:

	Timer    mShootTimer;
	Display* mDisplayPtr;
	double   mVSpeed;
	double   mHSpeed;
	bool     mCanShoot;
};


#endif //BAWL_STANDARDSHIP_H
