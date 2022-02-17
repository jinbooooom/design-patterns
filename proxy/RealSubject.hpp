#ifndef REAL_SUBJECT_HPP
#define REAL_SUBJECT_HPP

#include "Subject.hpp"

#include <iostream>

class RealSubject : public Subject
{
public:
    void request() override
    {
        std::cout << "Call the real subject method RealSubject::request()" << std::endl;
    }

    int requestAdd(int x, int y) override
    {
        int sum = x + y;
        std::cout << "Call the real subject method RealSubject::requestAdd(int, int)" << std::endl
                  << x << " + " << y << " = " << sum << std::endl;
        return sum;
    }
};

#endif