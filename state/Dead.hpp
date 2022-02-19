#ifndef DEAD_HPP
#define DEAD_HPP

#include "ThreadContext.hpp"
#include "State.hpp"
#include <iostream>

class Dead : public State // 终止状态
{
public:
    Dead(ThreadContext *tc) : State(tc){};
    virtual ~Dead() = default;

    virtual void start() override
    {
        std::cout << "ERROR! 终止状态不能执行 start()!" << std::endl;
    }

    virtual void getCpu() override
    {
        std::cout << "ERROR! 终止状态不能获取时间片！" << std::endl;
    }

    virtual void lostCpu() override
    {
        std::cout << "ERROR! 终止状态无法使用完时间片！" << std::endl;
    }

    virtual void suspend() override
    {
        std::cout << "ERROR! 终止状态不能阻塞！" << std::endl;
    }

    virtual void resume() override
    {
        std::cout << "ERROR! 终止状态不能变为就绪！" << std::endl;
    }

    virtual void stop() override
    {
        std::cout << "ERROR! 终止状态不能再次终止！" << std::endl;
    }
};

#endif