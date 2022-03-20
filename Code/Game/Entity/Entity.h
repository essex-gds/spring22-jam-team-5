#ifndef BAWL_ENTITY_H
#define BAWL_ENTITY_H

#include <vector>
#include <math.h>

#include "Display.h"
#include "StateStack.h"
#include "IComponent.h"

class Entity
{
public:

	HAS_ID("BASE---");

	/***
	 * Super dangerous do not use unless you have to and remember to set sprite ASAP
	 */
	Entity();

	Entity(Sprite* sprite);

	Entity(Sprite* sprite, double xVelocity, double yVelocity);

	virtual ~Entity();

	virtual void update(StateBall* stateBallPtr, float dt, std::vector<Entity*>& fellows);

	virtual void addComponent(IComponent* component);

	virtual void removeComponent(IComponent* component);

	virtual Sprite* getSprite();

	virtual double getX();

	virtual double getY();

	static std::vector<Entity*> fellowsWithinRange(double x, double y, double range, std::vector<Entity*>& fellows);

	static std::vector<Entity*> fellowsWithinBox(double x1, double y1, double x2, double y2,
						     std::vector<Entity*>& fellows);

	static inline bool cmpID(ID& a, ID& b) { return (uint64_t) a == (uint64_t) b; };
protected:

	double & mX;
	double & mY;
	double & mWidth;
	double & mHeight;
	double   mXVelocity;
	double   mYVelocity;
	Sprite * mSprite;

	std::vector<IComponent*> mComponents;
};

#endif // BAWL_ENTITY_H
