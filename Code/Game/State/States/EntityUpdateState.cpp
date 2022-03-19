#include "EntityUpdateState.h"

EntityUpdateState::EntityUpdateState()
{
	mEntities = {};
}

EntityUpdateState::~EntityUpdateState()
{

}

void EntityUpdateState::enter(StateStack* stack, StateBall* stateBallPtr, IState* from)
{

}

void EntityUpdateState::exit(StateStack* stack, StateBall* stateBallPtr, IState* to)
{

}

void EntityUpdateState::tick(StateStack* stack, StateBall* stateBallPtr, float dt)
{
	auto entities = mEntities;
	for(auto e : entities)
	{
			e->update(stateBallPtr, dt,mEntities);
	}
}

void EntityUpdateState::addEntity(Entity* e)
{
	mEntities.push_back(e);
}
