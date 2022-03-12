#include "TextChoiceState.h"

TextChoiceState::TextChoiceState(uint32_t offsetX, uint32_t offsetY, NString* msg, TextChoiceState::Options options,
                                 uint8_t textMode, TextChoiceState::OptionCallback optionCallback)
				 : mOffsetX        (offsetX)
				 , mOffsetY        (offsetY)
				 , mMsg            (msg)
				 , mOptions        (options)
				 , mTextMode       (textMode)
				 , mOptionCallback (optionCallback)
{
	if(!mOptions.empty())
	{
		mSelected = 0;
	}
	else
	{
		mSelected = -1;
	}
}

TextChoiceState::~TextChoiceState()
{

}

void TextChoiceState::enter(StateStack* stack, StateBall* stateBallPtr, IState* from)
{
	GLOG_INFO("TextChoiceState pushed");
}

void TextChoiceState::exit(StateStack* stack, StateBall* stateBallPtr, IState* to)
{
	GLOG_INFO("TextChoiceState popped");
}

void TextChoiceState::tick(StateStack* stack, StateBall* stateBallPtr, float dt)
{
	uint32_t x = 0;
	uint32_t y = 0;

	DisplayOption(stateBallPtr, x,y,mOffsetX,mOffsetY, mMsg);

	y+=2;

	for( uint8_t i = 0; i < (uint8_t) mOptions.size(); i++ )
	{
		NString* msg = mOptions[i];

		if( i == mSelected)
		{
			msg->mStr[0] = '>';
			msg->mStr[msg->mLen-1] = '<';
		}
		else
		{
			msg->mStr[0] = ' ';
			msg->mStr[msg->mLen-1] = ' ';
		}

		x = 1; // indent menu entries by one
		y++;
		DisplayOption(stateBallPtr, x, y, mOffsetX, mOffsetY, msg);
	}

	if(  GameHandler::getControlState()->mKeyboardReleased[SDL_SCANCODE_S]
	     || GameHandler::getControlState()->mKeyboardReleased[SDL_SCANCODE_DOWN])
	{
		if( mSelected >= mOptions.size()-1)
		{
			mSelected = 0;
		}
		else
		{
			mSelected++;
		}
	}

	if(  GameHandler::getControlState()->mKeyboardReleased[SDL_SCANCODE_W]
	     || GameHandler::getControlState()->mKeyboardReleased[SDL_SCANCODE_UP])
	{
		if( mSelected > 0)
		{
			mSelected--;
		}
		else
		{
			mSelected = mOptions.size()-1;
		}
	}

	if(  GameHandler::getControlState()->mKeyboardReleased[SDL_SCANCODE_BACKSPACE]
	  || GameHandler::getControlState()->mKeyboardReleased[SDL_SCANCODE_D        ]
	  || GameHandler::getControlState()->mKeyboardReleased[SDL_SCANCODE_RIGHT    ])
	{
		mOptionCallback(mSelected,1);
	}

	if(  GameHandler::getControlState()->mKeyboardReleased[SDL_SCANCODE_RETURN]
	  || GameHandler::getControlState()->mKeyboardReleased[SDL_SCANCODE_A     ]
	  || GameHandler::getControlState()->mKeyboardReleased[SDL_SCANCODE_LEFT  ])
	{
		mOptionCallback(mSelected,-1);
	}
}

void TextChoiceState::DisplayOption(const StateBall* stateBallPtr, uint32_t& x, uint32_t& y,
				    const uint32_t offsetX, const uint32_t offsetY, const NString* msg)
{
	for( size_t i = 0; i < msg->mLen; i++)
	{
		uint8_t mode = mTextMode;
		size_t pos = (  ( y + offsetY ) * stateBallPtr->mLevel->mWidth  ) + ( x + offsetX );

		switch (msg->mStr[i])
		{
			case '\n':
				y++;
				x=0;
				break;

			default:
				stateBallPtr->mLevel->mCharMap[ pos ] = msg->mStr[i];
				x++;
				break;
		}
	}
}
