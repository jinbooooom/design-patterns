#ifndef CLASS_ADAPTER_HPP
#define CLASS_ADAPTER_HPP

#include "Target.hpp"
#include "Adaptee.hpp"

#include <memory>

class ClassAdapter : public Adaptee, public Target
{
public:
    void request() override
    {
        specificRequest();
    }

    void process() override
    {
        int data = specificProcess1();
        specificProcess2(data);
    }
};




#endif