#ifndef BLOCKED_HPP
#define BLOCKED_HPP

#include "ThreadContext.hpp"
#include "State.hpp"
#include <iostream>

class Blocked : public State // 阻塞状态
{
public:
    Blocked(ThreadContext *tc) : State(tc){};
    virtual ~Blocked() = default;

    virtual void start() override
    {
        std::cout << "ERROR! 阻塞状态不能执行 start()!" << std::endl;
    }

    virtual void getCpu() override
    {
        std::cout << "ERROR! 当前是阻塞状态，不要再获取时间片了！" << std::endl;
    }

    virtual void lostCpu() override
    {
        std::cout << "ERROR! 线程不是运行状态，无法使用完时间片，不能进入就绪状态！" << std::endl;
    }

    virtual void suspend() override
    {
        std::cout << "当前已经是阻塞状态，等待用户输入。" << std::endl;
    }

    virtual void resume() override
    {
        std::cout << "当前是阻塞状态，用户输入完毕，切换到就绪状态。" << std::endl;
        mThreadContext->setState(mThreadContext->getRunnableState());
    }

    virtual void stop() override
    {
        std::cout << "ERROR! 当前是阻塞状态，无法进入终止状态!" << std::endl;
    }
};

#endif