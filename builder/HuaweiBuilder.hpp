#ifndef HUAWEI_BUILDER_HPP
#define HUAWEI_BUILDER_HPP

#include "Builder.hpp"

class HuaweiBuilder : public Builder
{
public:
    void buildHost() override
    {
        std::cout << "build Huawei host" << std::endl;
        mComputerProduct->setHost("Huawei host");
    }

    void buildMonitor() override
    {
        std::cout << "build Huawei monitor" << std::endl;
        mComputerProduct->setMonitor("Huawei monitor");
    }
};

#endif