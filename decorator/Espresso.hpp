#ifndef ESPRESSO_HPP
#define ESPRESSO_HPP

#include "Beverage.hpp"

class Espresso : public Beverage
{
public:
    std::string getDescription()
    {
        return "Espresso"; // 浓咖啡
    }

    double cost()
    {
        return 1.99;
    }
};

#endif