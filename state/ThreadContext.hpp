#ifndef THREAD_CONTEXT_HPP
#define THREAD_CONTEXT_HPP

#include "State.hpp"

#include <memory>

class ThreadContext
{
private:
    std::shared_ptr<State> mInitial;
    std::shared_ptr<State> mRunnable;
    std::shared_ptr<State> mRunning;
    std::shared_ptr<State> mBlocked;
    std::shared_ptr<State> mDead;

    std::shared_ptr<State> mState;

public:
    ThreadContext();

    virtual ~ThreadContext();

    void setState(std::shared_ptr<State> s);

    std::shared_ptr<State> getState() const;

    std::shared_ptr<State> getInitialState() const;

    std::shared_ptr<State> getRunnableState() const;

    std::shared_ptr<State> getRunningState() const;

    std::shared_ptr<State> getBlockedState() const;

    std::shared_ptr<State> getDeadState() const;

    void start();

    void getCpu();

    void lostCpu();

    void suspend();

    void resume();

    void stop();
};

#endif