#ifndef RUNNABLE_HPP
#define RUNNABLE_HPP

#include "ThreadContext.hpp"
#include "State.hpp"
#include <iostream>

class Runnable : public State // 就绪状态
{
public:
    Runnable(ThreadContext *tc) : State(tc) {};
    virtual ~Runnable() = default;

    virtual void start() override
    {
        std::cout << "ERROR! 就绪状态不能执行 start()!" << std::endl;
    }

    virtual void getCpu() override
    {
        std::cout << "当前是就绪状态，获取时间片成功，切换到运行状态。" << std::endl;
        mThreadContext->setState(mThreadContext->getRunningState());
    }

    virtual void lostCpu() override
    {
        std::cout << "ERROR! 线程不是运行状态，无法使用完时间片，不能进入就绪状态！" << std::endl;
    }

    virtual void suspend() override
    {
        std::cout << "ERROR! 当前是就绪状态，无法进入阻塞状态!" << std::endl;
    }

    virtual void resume() override
    {
        std::cout << "ERROR! 当前是就绪状态，无法被唤醒，重新进入就绪状态!" << std::endl;
    }

    virtual void stop() override
    {
        std::cout << "ERROR! 当前是就绪状态，无法进入终止状态!" << std::endl;
    }
};

#endif