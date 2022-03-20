#include "Pointer.h"

Pointer::Pointer(Entity* host, Entity* target)
	: mHost   (host)
	, mTarget (target)
	, mXVel   (0)
	, mYVel   (0)
{
	calcVect();
}

void Pointer::update(Entity &host, double dt)
{
	if(mTarget && mHost)
	{
		calcVect();
	}
}

double Pointer::getXVel()
{
	return mXVel;
}

double Pointer::getYVel()
{
	return mYVel;
}

double Pointer::getAngle()
{
	return mAngle;
}

void Pointer::calcVect()
{
	double tarX = mTarget->getX();
	double tarY = mTarget->getY();

	double hostX = mHost->getX();
	double hostY = mHost->getY();

	mXVel = tarX-hostX;
	mYVel = tarY-hostY;

	double len = std::sqrt( (mXVel*mXVel) + (mYVel*mYVel) );
	const double halfC = 180. / M_PI;
	mAngle = std::atan( mYVel / mXVel ) * halfC;

	mXVel /= len;
	mYVel /= len;
}
