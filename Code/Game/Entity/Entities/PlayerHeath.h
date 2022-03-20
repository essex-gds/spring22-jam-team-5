#ifndef BAWL_PLAYERHEATH_H
#define BAWL_PLAYERHEATH_H

#include "TileMapEnum.h"

#include "Entity.h"
#include "EntityWithHealth.h"

class Player;

class PlayerHeath : public Entity
{
public:
	PlayerHeath(StateBall* stateBallPtr, EntityWithHealth* player);
	~PlayerHeath();

	void update(StateBall *stateBallPtr, float dt, std::vector<Entity *> &fellows) override;

protected:
	EntityWithHealth* mPlayer;
};


#endif // BAWL_PLAYERHEATH_H
