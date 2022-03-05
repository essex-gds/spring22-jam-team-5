#ifndef BAWL_TESTSTATE_H
#define BAWL_TESTSTATE_H

#include "GameHandler.h"
#include "IState.h"

class TestState : public IState
{
public:
	void enter(StateBall* stateBallPtr, IState* from) override;
	void exit(StateStack* stack, IState* to )         override;
	void tick(StateStack* stack, float dt)            override;
private:
	Level  mLevel;
	Camera mCamera;
};


#endif //BAWL_TESTSTATE_H
