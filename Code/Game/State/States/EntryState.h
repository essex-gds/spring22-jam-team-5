#ifndef BAWL_ENTRYSTATE_H
#define BAWL_ENTRYSTATE_H

#include "gLog.h"

#include "Display.h"
#include "IState.h"
#include "TestState.h"

class EntryState : public IState
{
public:
	EntryState(Display* display);
	void enter(StateBall* stateBallPtr, IState* from) override;
	void exit(StateStack* stack, IState* to )         override;
	void tick(StateStack* stack, float dt)            override;

private:
	Display* mDisplayPtr;
};


#endif // BAWL_ENTRYSTATE_H
