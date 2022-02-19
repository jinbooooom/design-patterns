#ifndef PROXY_HPP
#define PROXY_HPP

#include "Subject.hpp"
#include "RealSubject.hpp"

#include <memory>

class Proxy : public Subject
{
private:
    std::unique_ptr<Subject> mSubject; // 代理具有对真实主题的引用

public:
    void request() override
    {
        if (nullptr == mSubject)
        {
            std::cout << "create proxy" << std::endl;
            mSubject = std::make_unique<RealSubject>();
        }

        std::cout << "Call the proxy method Proxy::request()" << std::endl;
        mSubject->request();
    }

    int requestAdd(int x, int y) override
    {
        if (nullptr == mSubject)
        {
            std::cout << "create proxy" << std::endl;
            mSubject = std::make_unique<RealSubject>();
        }

        std::cout << "Call the proxy method Proxy::requestAdd(int, int)" << std::endl;
        return mSubject->requestAdd(x, y);
    }
};

#endif