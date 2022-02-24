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
	virtual void enter(StateBall* stateBallPtr, IState* from) = 0;
	virtual void exit(IState* to ) = 0;
	virtual void tick(StateStack* stack, float dt) = 0;

    inline virtual bool isTransparent() { return mIsTransparent; }
private:
    bool       mIsTransparent;
	StateBall* mStateBall;
};

#endif // BAWL_ISTATE_H
