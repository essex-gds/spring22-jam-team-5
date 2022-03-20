#ifndef BAWL_ENTITYWITHHEALTH_H
#define BAWL_ENTITYWITHHEALTH_H

#include "Entity.h"

#include "ColourShift.h"

class EntityWithHealth : public Entity
{

public:
	HAS_ID("HEALTH-")
	inline EntityWithHealth(Sprite* pSprite)
		: Entity(pSprite)
	{}

	inline int64_t getHealth() { return mHealth; }
	inline void setHealth( double health )
	{
		if (health < mHealth)
		{
			mComponents.push_back(new ColourShift(this,255,0,0, 100,0.05,true));
		}
		mHealth = health;

	}

	inline void update(StateBall *stateBallPtr, float dt, std::vector<Entity *> &fellows) override
	{
		Entity::update(stateBallPtr,dt,fellows);
		if(mHealth < 1)
		{
			fellows.erase(std::remove(fellows.begin(), fellows.end(), this), fellows.end());
			delete this;
		}
	}

protected:
	int64_t mHealth;
};


#endif // BAWL_ENTITYWITHHEALTH_H
