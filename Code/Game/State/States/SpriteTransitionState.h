#ifndef BAWL_SPRITETRANSITIONSTATE_H
#define BAWL_SPRITETRANSITIONSTATE_H

#include "IState.h"
#include "Display.h"

class SpriteTransitionState : public IState
{
public:

	typedef void (*TransitionFinishedCallBack_t)(Sprite* spritePtr);

	SpriteTransitionState(Sprite* spritePtr, int32_t dstX, int32_t dstY, uint32_t speed, TransitionFinishedCallBack_t transitionFinishedCallBack);
	void enter(StateStack* stack, StateBall* stateBallPtr, IState* from) override;
	void exit(StateStack* stack, StateBall* stateBallPtr, IState* to )   override;
	void tick(StateStack* stack, StateBall* stateBallPtr, float dt)      override;

protected:

	Sprite*                       mSpritePtr;
	double                        mDX;
	double                        mDY;
	uint32_t                      mSpeed;
	TransitionFinishedCallBack_t  mTransitionFinishedCallBack;

};


#endif // BAWL_SPRITETRANSITIONSTATE_H
