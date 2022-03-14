#ifndef BAWL_BULLET_H
#define BAWL_BULLET_H

#include "Entity.h"

class Bullet : public Entity
{
public:
	HAS_ID("BULLET-");
		 Bullet(double x, double y);
	virtual ~Bullet();

	virtual void update(StateBall *stateBallPtr, float dt, std::vector<Entity *> &fellows) override;


};


#endif // BAWL_BULLET_H
