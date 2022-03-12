#ifndef BAWL_TEXTCHOICESTATE_H
#define BAWL_TEXTCHOICESTATE_H

#include <vector>
#include <functional>

#include "GameHandler.h"
#include "IState.h"

class TextChoiceState : public IState
{
	typedef std::vector<NString*>&        Options;
	typedef std::function<void(int8_t, int8_t)> OptionCallback;

public:
	             TextChoiceState(uint32_t  offsetX, uint32_t  offsetY, NString* msg, Options options,
				     uint8_t textMode, OptionCallback optionCallback);
	virtual     ~TextChoiceState();
	virtual void enter(StateStack* stack, StateBall* stateBallPtr, IState* from) override;
	virtual void exit(StateStack* stack, StateBall* stateBallPtr, IState* to )   override;
	virtual void tick(StateStack* stack, StateBall* stateBallPtr, float dt)      override;

	virtual void DisplayOption(const StateBall* stateBallPtr, uint32_t& x, uint32_t& y,
				   const uint32_t offsetX, const uint32_t offsetY, const NString* msg);

	inline bool isTransparent() override { return false; }
private:
	uint32_t       mOffsetX;
	uint32_t       mOffsetY;
	NString*       mMsg;
	Options        mOptions;
	OptionCallback mOptionCallback;
	uint8_t        mTextMode;

	int8_t         mSelected;
};


#endif // BAWL_TEXTCHOICESTATE_H