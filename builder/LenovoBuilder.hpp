#ifndef LENOVO_BUILDER_HPP
#define LENOVO_BUILDER_HPP

#include "Builder.hpp"

class LenovoBuilder : public Builder
{
public:
    void buildHost() override
    {
        std::cout << "build Lenovo host" << std::endl;
        mComputerProduct->setHost("Lenovo host");
    }

    void buildMonitor() override
    {
        std::cout << "build Lenovo monitor" << std::endl;
        mComputerProduct->setMonitor("Lenovo monitor");
    }
};

#endif