#ifndef PROXY_HPP
#define PROXY_HPP

#include "Subject.hpp"
#include "RealSubject.hpp"

#include <memory>

class Proxy : public Subject
{
private:
    std::unique_ptr<Subject> subject; // 代理具有对真实主题的引用

public:
    void request() override
    {
        if (nullptr == subject)
        {
            std::cout << "create proxy" << std::endl;
            subject = std::make_unique<RealSubject>();
        }

        std::cout << "Call the proxy method Proxy::request()" << std::endl;
        subject->request();
    }

    int requestAdd(int x, int y) override
    {
        if (nullptr == subject)
        {
            std::cout << "create proxy" << std::endl;
            subject = std::make_unique<RealSubject>();
        }

        std::cout << "Call the proxy method Proxy::requestAdd(int, int)" << std::endl;
        return subject->requestAdd(x, y);
    }
};

#endif