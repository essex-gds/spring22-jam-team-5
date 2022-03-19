#ifndef BAWL_PLAYER_H
#define BAWL_PLAYER_H

#include "TileMapEnum.h"

#include "GameHandler.h"

#include "Entity.h"
#include "EntityWithHealth.h"
#include "Bullet.h"

#include "Timer.h"

class Player : public EntityWithHealth
{
public:

	Player(StateBall* stateBallPtr);

	virtual ~Player() override;

	virtual void update(StateBall *stateBallPtr, float dt, std::vector<Entity *> &fellows) override;

	double getHSpeed();

	void setHSpeed(double hSpeed);

	double getVSpeed();

	void setVSpeed(double vSpeed);

private:

	Display* mDisplayPtr;

	double   mVSpeed;
	double   mHSpeed;

	bool     mCanShoot;
	int      mMultiShoot;
	Timer    mBulletTimer;
};


#endif // BAWL_PLAYER_H
