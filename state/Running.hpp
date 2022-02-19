#ifndef RUNNING_HPP
#define RUNNING_HPP

#include "ThreadContext.hpp"
#include "State.hpp"
#include <iostream>

class Running : public State // 运行状态
{
public:
    Running(ThreadContext *tc) : State(tc) {};
    virtual ~Running() = default;

    virtual void start() override
    {
        std::cout << "ERROR! 运行状态不能执行 start()!" << std::endl;
    }

    virtual void getCpu() override
    {
        std::cout << "ERROR! 当前是运行状态，已经获取过时间片，不要再获取了！" << std::endl;
    }

    virtual void lostCpu() override
    {
        std::cout << "当前是运行状态，时间片用尽，切换到就绪状态！" << std::endl;
        mThreadContext->setState(mThreadContext->getRunnableState());
    }

    virtual void suspend() override
    {
        std::cout << "当前是运行状态，等待用户输入，切换到阻塞状态。" << std::endl;
        mThreadContext->setState(mThreadContext->getBlockedState());
    }

    virtual void resume() override
    {
        std::cout << "ERROR! 当前是运行状态，已经被唤醒，无法再次被唤醒。" << std::endl;
    }

    virtual void stop() override
    {
        std::cout << "当前是运行状态，任务处理完成，进入终止状态。" << std::endl;
        mThreadContext->setState(mThreadContext->getDeadState());
    }
};

#endif