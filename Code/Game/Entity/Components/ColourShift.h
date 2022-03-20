#ifndef BAWL_COLOURSHIFT_H
#define BAWL_COLOURSHIFT_H

#include "Display.h"

#include "Entity.h"

#include "IComponent.h"

class ColourShift : public IComponent
{
public:
	ColourShift(Entity* entity, uint8_t r, uint8_t g, uint8_t b, double speed, double duration, bool revert);

	void update(Entity &host, double dt) override;

protected:
	Entity* mTarget;

	bool  mRevert;
	bool  mReverting;
	double mSpeed;
	double mDuration;

	uint8_t mRFrom;
	uint8_t mGFrom;
	uint8_t mBFrom;

	float mRCurr;
	float mGCurr;
	float mBCurr;

	uint8_t mRTo;
	uint8_t mGTo;
	uint8_t mBTo;
};


#endif // BAWL_COLOURSHIFT_H
