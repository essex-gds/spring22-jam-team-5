#ifndef BAWL_ENTITYUPDATESTATE_H
#define BAWL_ENTITYUPDATESTATE_H

#include <vector>

#include "Entity.h"
#include "IState.h"

class EntityUpdateState : public IState
{
public:
	             EntityUpdateState();
	virtual     ~EntityUpdateState();
	virtual void enter(StateStack* stack, StateBall* stateBallPtr, IState* from) override;
	virtual void exit(StateStack* stack, StateBall* stateBallPtr, IState* to )   override;
	virtual void tick(StateStack* stack, StateBall* stateBallPtr, float dt)      override;
	inline  bool isTransparent() override { return true; }

	void addEntity(Entity* e);
private:
	std::vector<Entity*> mEntities;
};


#endif // BAWL_ENTITYUPDATESTATE_H
