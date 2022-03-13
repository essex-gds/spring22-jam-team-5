#ifndef BAWL_ENTITY_H
#define BAWL_ENTITY_H

#include <vector>

#include "Display.h"

class Entity
{
public:
	Entity(Sprite* sprite);

	Entity(Sprite* sprite, double xVelocity, double yVelocity);

	virtual ~Entity();

	virtual void update(float dt, std::vector<Entity*>& fellows);

	static std::vector<Entity*> fellowsWithinRange(double x, double y, double range, std::vector<Entity*>& fellows);

	static std::vector<Entity*> fellowsWithinBox(double x1, double y1, double x2, double y2,
						     std::vector<Entity*>& fellows);

private:

	double & mX;
	double & mY;
	double & mWidth;
	double & mHeight;
	double   mXVelocity;
	double   mYVelocity;
	Sprite * mSprite;

};

#endif // BAWL_ENTITY_H
