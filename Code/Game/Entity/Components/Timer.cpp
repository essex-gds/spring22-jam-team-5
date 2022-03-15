#include "Timer.h"

Timer::Timer()
	: IComponent  ()
	  , mDuration   (0)
	  , mRemaining  (0)
	  , mCallback   (nullptr)
{}

Timer::Timer(double time, Timer::TimerCallback_t callback)
	: IComponent  ()
	, mDuration   (time)
	, mRemaining  (mDuration)
	, mCallback   (callback)
{}

void Timer::update(Entity &host, double dt)
{
	if(mDuration != 0)
	{
		mRemaining -= dt;

		if (mRemaining < 0)
		{
			if (mCallback != nullptr)
			{
				mCallback(this);
			}
		}
	}
}

void Timer::setDuration(double duration)
{
	mDuration = duration;
}

void Timer::reset()
{
	mRemaining = mDuration;
}
