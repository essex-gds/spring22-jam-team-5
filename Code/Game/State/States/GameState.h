#ifndef BAWL_GAMESTATE_H
#define BAWL_GAMESTATE_H

#include <vector>

#include "Audio.h"
#include "TileMapEnum.h"

#include "IState.h"
#include "ShipSpawnerEntity.h"
#include "EntityUpdateState.h"

class GameState : public IState
{
	static inline bool sGameOver = false;
	static inline bool sGameWin = false;
public:
	void enter(StateStack* stack, StateBall* stateBallPtr, IState* from) override;

	void exit(StateStack* stack, StateBall* stateBallPtr, IState* to) override;

	void tick(StateStack* stack, StateBall* stateBallPtr, float dt) override;

	static inline void gameOver()
	{
		sGameOver = true;
	}
	static inline void gameWin()
	{
		sGameWin = true;
	}

protected:
	Level*  mLevel;
	Camera mCamera;


	///////////////////////////////
	/// pre-made waves for ease ///
	///////////////////////////////
};


#endif // BAWL_GAMESTATE_H
