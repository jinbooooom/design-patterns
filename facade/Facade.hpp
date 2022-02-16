#ifndef FACADE_HPP
#define FACADE_HPP

#include "Module1.hpp"
#include "Module2.hpp"
#include "Module3.hpp"

#include <memory>

class Facade
{
private:
    Module1 m1;
    Module2 m2;
    Module3 m3;

public:
    void method()
    {
        m1.process();
        m2.process();
        m3.process();
    }
};

#endif