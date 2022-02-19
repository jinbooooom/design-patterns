#include "ThreadContext.hpp"
#include "Initial.hpp"
#include "Runnable.hpp"
#include "Running.hpp"
#include "Blocked.hpp"
#include "Dead.hpp"
#include <memory>

ThreadContext::ThreadContext()
    : mInitial(std::make_shared<Initial>(this)),
      mRunnable(std::make_shared<Runnable>(this)),
      mRunning(std::make_shared<Running>(this)),
      mBlocked(std::make_shared<Blocked>(this)),
      mDead(std::make_shared<Dead>(this)),
      mState(mInitial)
{
}

ThreadContext::~ThreadContext()
{
}

void ThreadContext::setState(std::shared_ptr<State> s)
{
    mState = s;
}

std::shared_ptr<State> ThreadContext::getState() const
{
    return mState;
}

std::shared_ptr<State> ThreadContext::getInitialState() const
{
    return mInitial;
}

std::shared_ptr<State> ThreadContext::getRunnableState() const
{
    return mRunnable;
}

std::shared_ptr<State> ThreadContext::getRunningState() const
{
    return mRunning;
}

std::shared_ptr<State> ThreadContext::getBlockedState() const
{
    return mBlocked;
}

std::shared_ptr<State> ThreadContext::getDeadState() const
{
    return mDead;
}

void ThreadContext::start()
{
    mState->start();
}

void ThreadContext::getCpu()
{
    mState->getCpu();
}

void ThreadContext::lostCpu()
{
    mState->lostCpu();
}

void ThreadContext::suspend()
{
    mState->suspend();
}

void ThreadContext::resume()
{
    mState->resume();
}

void ThreadContext::stop()
{
    mState->stop();
}
