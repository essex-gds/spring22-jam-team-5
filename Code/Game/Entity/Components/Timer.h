#ifndef BAWL_BULLETTIMER_H
#define BAWL_BULLETTIMER_H

#include <functional>

#include "IComponent.h"

class Timer : public IComponent
{
public:
	typedef std::function<void(IComponent*)> TimerCallback_t;

	Timer();

	Timer(double  time, TimerCallback_t callback);

	void update(Entity &host, double dt) override;

	void reset();

	void setDuration(double duration);

protected:
	double            mDuration;
	double            mRemaining;
	TimerCallback_t   mCallback;
};


#endif // BAWL_BULLETTIMER_H
