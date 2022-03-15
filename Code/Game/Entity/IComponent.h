#ifndef BAWL_ICOMPONENT_H
#define BAWL_ICOMPONENT_H

class Entity;

class IComponent
{
public:
	virtual void update(Entity& host, double dt) = 0;
};

#endif // BAWL_ICOMPONENT_H
