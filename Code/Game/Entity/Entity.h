#ifndef BAWL_ENTITY_H
#define BAWL_ENTITY_H

#include <vector>

class Entity
{
public:
	Entity();

	virtual ~Entity();

	virtual void update(float dt, std::vector<Entity>& fellows);
};

#endif // BAWL_ENTITY_H
