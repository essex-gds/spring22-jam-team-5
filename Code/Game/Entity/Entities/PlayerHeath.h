#ifndef BAWL_PLAYERHEATH_H
#define BAWL_PLAYERHEATH_H

#include "TileMapEnum.h"

#include "Entity.h"
#include "EntityWithHealth.h"

class Player;

class PlayerHeath : public Entity
{
public:
	HAS_ID("PLAYER")
	PlayerHeath(StateBall* stateBallPtr, Player* player);
	~PlayerHeath();

	void update(StateBall *stateBallPtr, float dt, std::vector<Entity *> &fellows) override;

protected:
	Player* mPlayer;
	double mStartingWidth;
};


#endif // BAWL_PLAYERHEATH_H
