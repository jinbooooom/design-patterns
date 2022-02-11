#include "ObjectAdapter.hpp"

#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<Adaptee> oldAdaptee = std::make_unique<Adaptee>();
    std::unique_ptr<Target> newTarget = std::make_unique<ObjectAdapter>(std::move(oldAdaptee));
    newTarget->request();
    newTarget->process();

    return 0;
}