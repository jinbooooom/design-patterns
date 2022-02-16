#ifndef BUILDER_HPP
#define BUILDER_HPP

#include "ComputerProduct.hpp"

#include <memory>

class Builder
{
protected:
    std::shared_ptr<ComputerProduct> mComputerProduct;

public:
    Builder() : mComputerProduct(std::make_shared<ComputerProduct>()){};

    virtual void buildHost() = 0;
    virtual void buildMonitor() = 0;
    std::shared_ptr<ComputerProduct> getResult() { return mComputerProduct; };
};

#endif