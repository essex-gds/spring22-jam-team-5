#include "TextChoiceState.h"

TextChoiceState::TextChoiceState(uint32_t offsetX, uint32_t offsetY, NString* msg, TextChoiceState::Options options,
                                 TextChoiceState::OptionCallback optionCallback, uint8_t textMode)
				 : mOffsetX        (offsetX)
				 , mOffsetY        (offsetY)
				 , mMsg            (msg)
				 , mOptions        (options)
				 , mOptionCallback (optionCallback)
				 , mTextMode       (textMode)
{
}

TextChoiceState::~TextChoiceState()
{

}

void TextChoiceState::enter(StateStack* stack, StateBall* stateBallPtr, IState* from)
{

}

void TextChoiceState::exit(StateStack* stack, StateBall* stateBallPtr, IState* to)
{

}

void TextChoiceState::tick(StateStack* stack, StateBall* stateBallPtr, float dt)
{
	uint32_t x = 0;
	uint32_t y = 0;


	for( size_t i = 0; i < mMsg->len; i++)
	{
		uint8_t mode = mTextMode;
		size_t pos = (  ( y + mOffsetY ) * stateBallPtr->mLevel->mWidth  ) + ( x +mOffsetX );

		switch (mMsg->str[i])
		{
			case '\n':
				y++;
				x=0;
				break;

			default:
				stateBallPtr->mLevel->mCharMap[ pos ] = mMsg->str[i];
				x++;
				break;
		}
	}
}
