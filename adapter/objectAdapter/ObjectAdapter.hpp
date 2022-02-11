#ifndef OBJECT_ADAPTER_HPP
#define OBJECT_ADAPTER_HPP

#include "Target.hpp"
#include "Adaptee.hpp"

#include <memory>

class ObjectAdapter : public Target
{
private:
    std::unique_ptr<Adaptee> mAdaptee;

public:
    ObjectAdapter(std::unique_ptr<Adaptee> adaptee) : mAdaptee(std::move(adaptee)){};

    void request() override
    {
        mAdaptee->specificRequest();
    }

    void process() override
    {
        int data = mAdaptee->specificProcess1();
        mAdaptee->specificProcess2(data);
    }
};

#endif