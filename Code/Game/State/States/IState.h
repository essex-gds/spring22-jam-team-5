#ifndef BAWL_ISTATE_H
#define BAWL_ISTATE_H

#include <StateStack.h>


class IState
{
public:
	IState()          = default;
	virtual ~IState() = default;
	virtual void enter(StateBall* stateBallPtr, IState* from) = 0;
	virtual void exit(IState* to ) = 0;
	virtual void tick(StateStack* stack, float dt) = 0;
private:
	StateBall* mStateBall;
};

#endif // BAWL_ISTATE_H
