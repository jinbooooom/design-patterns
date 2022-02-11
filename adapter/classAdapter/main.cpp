#include "ClassAdapter.hpp"

#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<Target> newTarget = std::make_unique<ClassAdapter>();
    newTarget->request();
    newTarget->process();

    return 0;
}