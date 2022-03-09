#ifndef BAWL_SPRITETRANSITIONSTATE_H
#define BAWL_SPRITETRANSITIONSTATE_H

#include <functional>

#include "IState.h"
#include "Display.h"

class SpriteTransitionState : public IState
{
public:

	SpriteTransitionState(Sprite* spritePtr, double dstX, double dstY, double speed, std::function<void(Sprite*)> completedCallBack);
	void enter(StateStack* stack, StateBall* stateBallPtr, IState* from) override;
	void exit(StateStack* stack, StateBall* stateBallPtr, IState* to )   override;
	void tick(StateStack* stack, StateBall* stateBallPtr, float dt)      override;

protected:

	Sprite*                       mSpritePtr;
	double                        mDX;
	double                        mDY;
	double                        mDstX;
	double                        mDstY;
	double                       mSpeed;
	std::function<void(Sprite*)> mCompletedCallBack;

};


#endif // BAWL_SPRITETRANSITIONSTATE_H
