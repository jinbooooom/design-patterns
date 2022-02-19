#ifndef INITIAL_HPP
#define INITIAL_HPP

#include "ThreadContext.hpp"
#include "State.hpp"
#include <iostream>

class Initial : public State // 初始状态
{
public:
    Initial(ThreadContext *tc) : State(tc){};
    virtual ~Initial() = default;

    virtual void start() override
    {
        std::cout << "线程创建成功，当前是初始状态，执行 start() 成功。切换到就绪状态" << std::endl;
        mThreadContext->setState(mThreadContext->getRunnableState());
    }

    virtual void getCpu() override
    {
        std::cout << "ERROR! 线程不是就绪状态，无法获取时间片，不能进入运行状态！" << std::endl;
    }

    virtual void lostCpu() override
    {
        std::cout << "ERROR! 线程不是运行状态，无法使用完时间片，不能进入就绪状态！" << std::endl;
    }

    virtual void suspend() override
    {
        std::cout << "ERROR! 线程不是运行状态，无法进入阻塞！" << std::endl;
    }

    virtual void resume() override
    {
        std::cout << "ERROR! 线程不是阻塞状态，无法重新进入就绪！" << std::endl;
    }

    virtual void stop() override
    {
        std::cout << "ERROR! 线程还未进入运行状态，还没有处理任务，不能进入终止状态！" << std::endl;
    }
};

#endif