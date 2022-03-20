#ifndef BAWL_POINTER_H
#define BAWL_POINTER_H

#include <cmath>

#include "IComponent.h"
#include "Entity.h"

class Pointer : public IComponent
{
public:
	Pointer() = default;
	Pointer(Entity* host, Entity* target);
	void update(Entity &host, double dt) override;

	double getXVel();
	double getYVel();
	double getAngle();

protected:

	void calcVect();

	Entity* mHost;
	Entity* mTarget;

	double mXVel;
	double mYVel;
	double mAngle;
};


#endif // BAWL_POINTER_H
