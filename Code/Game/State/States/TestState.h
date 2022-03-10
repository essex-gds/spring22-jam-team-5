#ifndef BAWL_TESTSTATE_H
#define BAWL_TESTSTATE_H

#include "GameHandler.h"
#include "IState.h"
#include "SpriteTransitionState.h"
#include "TextChoiceState.h"

class TestState : public IState
{
public:
	void enter(StateStack* stack, StateBall* stateBallPtr, IState* from) override;
	void exit(StateStack* stack, StateBall* stateBallPtr, IState* to )   override;
	void tick(StateStack* stack, StateBall* stateBallPtr, float dt)      override;
private:
	Level  mLevel;
	Camera mCamera;
};


#endif //BAWL_TESTSTATE_H
