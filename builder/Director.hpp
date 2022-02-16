#ifndef DIRECTOR_HPP
#define DIRECTOR_HPP

#include "Builder.hpp"

class Director
{
private:
    std::shared_ptr<Builder> mBuilder;

public:
    Director(std::shared_ptr<Builder> builder) : mBuilder(builder){};

    std::shared_ptr<ComputerProduct> construct()
    {
        std::cout << "start construct computer product" << std::endl;
        mBuilder->buildHost();
        mBuilder->buildMonitor();
        std::cout << "finish construct computer product" << std::endl;
        return mBuilder->getResult();
    }
};

#endif