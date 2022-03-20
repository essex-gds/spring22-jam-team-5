#ifndef BAWL_GAMESTATE_H
#define BAWL_GAMESTATE_H

#include <vector>

#include "TileMapEnum.h"

#include "IState.h"
#include "ShipSpawnerEntity.h"
#include "EntityUpdateState.h"

class GameState : public IState
{
public:
	void enter(StateStack* stack, StateBall* stateBallPtr, IState* from) override;

	void exit(StateStack* stack, StateBall* stateBallPtr, IState* to) override;

	void tick(StateStack* stack, StateBall* stateBallPtr, float dt) override;

protected:
	Level*  mLevel;
	Camera mCamera;

	///////////////////////////////
	/// pre-made waves for ease ///
	///////////////////////////////
};


#endif // BAWL_GAMESTATE_H
