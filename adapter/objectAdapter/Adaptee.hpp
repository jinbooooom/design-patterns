#ifndef ADAPTEE_HPP
#define ADAPTEE_HPP

#include <iostream>

// 老接口都封装都这里，客户端想用这些接口的功能，但是不方便直接调用这些接口
class Adaptee
{
public:
    void specificRequest() // old interface
    {
        std::cout << "call old interface" << std::endl;
    }

    // old interface，在新接口里函数 process 高度封装，一次性调用 specificProcess1 和 specificProcess2
    int specificProcess1()
    {
        int data = 5;
        std::cout << "produce data = " << data << std::endl;
        return data;
    }

    void specificProcess2(int data)
    {
        std::cout << "process data = " << data << std::endl;
    }
};

#endif