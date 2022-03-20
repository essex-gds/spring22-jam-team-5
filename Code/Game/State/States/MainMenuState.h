#ifndef BAWL_MAINMENUSTATE_H
#define BAWL_MAINMENUSTATE_H

#include "IState.h"

#include "TextChoiceState.h"

#include "GameState.h"

class MainMenuState : public IState
{
public:
	         MainMenuState() = default;
	virtual ~MainMenuState() = default;

	virtual void enter( StateStack* stack, StateBall* stateBallPtr, IState* from ) override;
	virtual void exit(  StateStack* stack,  StateBall* stateBallPtr, IState* to  ) override;
	virtual void tick(  StateStack* stack,  StateBall* stateBallPtr, float dt    ) override;

	inline virtual bool isTransparent() { return false; }

protected:
	Level* mLevel;
	Camera mCamera;
};


#endif // BAWL_MAINMENUSTATE_H
