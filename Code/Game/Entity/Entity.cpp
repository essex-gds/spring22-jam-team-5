#include "Entity.h"

Entity::Entity(Sprite* sprite)
	: mX          (sprite->mX)
	, mY          (sprite->mY)
	, mWidth      (sprite->mWidth)
	, mHeight     (sprite->mHeight)
	, mSprite     (sprite)
	, mComponents ()
	, mXVelocity  (0)
	, mYVelocity  (0)
{}

Entity::Entity(Sprite* sprite, double xVelocity, double yVelocity)
	:Entity(sprite)
{
	mXVelocity = xVelocity;
	mYVelocity = yVelocity;
}

Entity::~Entity()
{

}

void Entity::update(StateBall* stateBallPtr, float dt, std::vector<Entity*>& fellows)
{
	mX += mXVelocity;
	mY += mYVelocity;

	auto components = mComponents;
	for( auto& c : components)
	{
		c->update(*this,dt);
	}
}

void Entity::addComponent(IComponent* component)
{
	mComponents.push_back(component);
}

void Entity::removeComponent(IComponent* component)
{
	mComponents.erase(std::remove(mComponents.begin(), mComponents.end(), component), mComponents.end());
}

std::vector<Entity*> Entity::fellowsWithinRange(double x, double y, double range, std::vector<Entity*>& fellows)
{
	std::vector<Entity*> withinRange = fellows;

	for(auto& e : fellows)
	{
		auto dist = std::sqrt( std::pow( e->mX - x, 2 ) + std::pow(e->mY - y, 2) );
		if(dist > range)
		{
			withinRange.erase(std::remove(withinRange.begin(), withinRange.end(), e), withinRange.end() );
		}
	}

	return withinRange;
}

std::vector<Entity*> Entity::fellowsWithinBox(double x1, double y1, double x2, double y2, std::vector<Entity*>& fellows)
{
	double max = std::max( std::abs( x1 - x2 ), std::abs( y1 - y2 ) );
	double minX = std::min( x1, x2 );
	double minY = std::min( y1, y2 );
	std::vector<Entity*> withinRange = fellowsWithinRange(minX, minY, max, fellows);
	return withinRange;
}
