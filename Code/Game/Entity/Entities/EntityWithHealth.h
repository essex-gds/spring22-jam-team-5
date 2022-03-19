#ifndef BAWL_ENTITYWITHHEALTH_H
#define BAWL_ENTITYWITHHEALTH_H

#include "Entity.h"

class EntityWithHealth : public Entity
{

public:
	HAS_ID("HEALTH-")
	inline EntityWithHealth(Sprite* pSprite)
		: Entity(pSprite)
	{}

	inline int64_t getHealth() { return mHealth; }
	inline void setHealth( double health ) { mHealth = health; }

protected:
	int64_t mHealth;
};


#endif // BAWL_ENTITYWITHHEALTH_H
