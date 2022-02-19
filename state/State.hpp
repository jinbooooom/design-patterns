#ifndef STATE_HPP
#define STATE_HPP

class ThreadContext; // 声明

class State
{
protected:
    ThreadContext *mThreadContext;
public:
    State(ThreadContext *threadContext) : mThreadContext(threadContext) {};
    virtual ~State() = default;

    virtual void start() = 0;
    virtual void getCpu() = 0;
    virtual void lostCpu() = 0;
    virtual void suspend() = 0;
    virtual void resume() = 0;
    virtual void stop() = 0;
};

#endif