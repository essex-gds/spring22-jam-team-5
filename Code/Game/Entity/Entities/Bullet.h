#ifndef BAWL_BULLET_H
#define BAWL_BULLET_H

#include "TileMapEnum.h"

#include "Entity.h"
#include "EntityWithHealth.h"
#include "Player.h"

class Bullet : public Entity
{
public:
	HAS_ID("BULLET-");

		 Bullet(StateBall* stateBallPtr, double x, double y, Entity* parent);
	virtual ~Bullet();

	virtual void update(StateBall *stateBallPtr, float dt, std::vector<Entity *> &fellows) override;

	void setXDir(double xDir);

	void setYDir(double yDir);

protected:

	static inline double sBulletSpeed = 800;

	double     mXDir;
	double     mYDir;
	double     mDMG;
	Entity*      mParent;
	StateBall* mStateBallPtr;
};
#endif // BAWL_BULLET_H
