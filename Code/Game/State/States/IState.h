#ifndef BAWL_ISTATE_H
#define BAWL_ISTATE_H

#include <StateStack.h>

class StateStack;
struct StateBall;

class IState
{
public:
	IState()          = default;
	virtual ~IState() = default;

	virtual void enter( StateStack* stack, StateBall* stateBallPtr, IState* from ) = 0;
	virtual void exit(  StateStack* stack,  StateBall* stateBallPtr, IState* to  ) = 0;
	virtual void tick(  StateStack* stack,  StateBall* stateBallPtr, float dt    ) = 0;

	inline virtual bool isTransparent() { return false; }
private:
};

#endif // BAWL_ISTATE_H
