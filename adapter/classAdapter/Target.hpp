#ifndef TARGET_HPP
#define TARGET_HPP

// 最新的接口都封装都这里，客户端只调用这里的接口
class Target
{
public:
    virtual void request() = 0; // new interface
    virtual void process() = 0; // new interface
};

#endif