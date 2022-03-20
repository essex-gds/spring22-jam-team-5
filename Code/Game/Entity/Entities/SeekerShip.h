#ifndef BAWL_SEEKERSHIP_H
#define BAWL_SEEKERSHIP_H

#include "Display.h"
#include "TileMapEnum.h"

#include "EntityWithHealth.h"
#include "Player.h"

#include "Pointer.h"

class SeekerShip : public EntityWithHealth
{
public:
	HAS_ID("BAD----");

	SeekerShip(StateBall* stateBallPtr, double x, double y);

	~SeekerShip();

	void update(StateBall *stateBallPtr, float dt, std::vector<Entity *> &fellows) override;

protected:

	Display* mDisplayPtr;
	Pointer  mPlayerPoint;
	bool     mSeeking;
};


#endif // BAWL_SEEKERSHIP_H
