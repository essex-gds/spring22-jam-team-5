#ifndef BAWL_TEXTCHOICESTATE_H
#define BAWL_TEXTCHOICESTATE_H

#include <vector>
#include <functional>

#include "IState.h"

class TextChoiceState : public IState
{
	typedef std::vector<NString*>&        Options;
	typedef std::function<void(uint8_t)>& OptionCallback;

public:
	             TextChoiceState(uint32_t  offsetX, uint32_t  offsetY, NString* msg, Options options,
				     OptionCallback optionCallback, uint8_t textMode);
	virtual     ~TextChoiceState();
	virtual void enter(StateStack* stack, StateBall* stateBallPtr, IState* from) override;
	virtual void exit(StateStack* stack, StateBall* stateBallPtr, IState* to )   override;
	virtual void tick(StateStack* stack, StateBall* stateBallPtr, float dt)      override;

private:
	uint32_t       mOffsetX;
	uint32_t       mOffsetY;
	NString*       mMsg;
	Options        mOptions;
	OptionCallback mOptionCallback;
	uint8_t        mTextMode;
};


#endif // BAWL_TEXTCHOICESTATE_H