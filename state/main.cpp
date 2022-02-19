
#include "ThreadContext.hpp"

#include <memory>

int main()
{
    auto threadContext = std::make_unique<ThreadContext>();
    threadContext->start();
    threadContext->getCpu();
    threadContext->lostCpu();
    threadContext->getCpu();
    threadContext->suspend();
    threadContext->resume();
    threadContext->getCpu();
    threadContext->resume(); // ERROR! 这是一个错误的状态切换，用于测试异常
    threadContext->stop();
    threadContext->stop(); // ERROR! 终止的线程，不能做任何操作

    return 0;
}