#ifndef BAWL_PLAYER_H
#define BAWL_PLAYER_H

#include "TileMapEnum.h"

#include "GameHandler.h"
#include "GameState.h"

#include "Entity.h"
#include "PlayerHeath.h"
#include "EntityWithHealth.h"
#include "Bullet.h"

#include "Timer.h"

class PlayerHealth;

class Player : public EntityWithHealth
{
public:
	HAS_ID("PLAYER")

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
	PlayerHeath* mPlayerHealth;
};


#endif // BAWL_PLAYER_H
