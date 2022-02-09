#ifndef HOUSEBLEND_HPP
#define HOUSEBLEND_HPP

#include "Beverage.hpp"

class HouseBlend : public Beverage
{
public:
    std::string getDescription()
    {
        return "House Blend Coffee"; // 家庭混合咖啡
    }

    double cost()
    {
        return .89;
    }
};

#endif