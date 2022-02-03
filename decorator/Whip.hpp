#ifndef WHIP_HPP
#define WHIP_HPP

#include "CondimentDecorator.hpp"

class Whip : public CondimentDecorator
{
public:
    Whip(std::unique_ptr<Beverage> b)
        : CondimentDecorator(std::move(b))
    {
        mylog;
    }

    virtual ~Whip()
    {
        mylog;
    }

    std::string getDescription()
    {
        return beverage->getDescription() + ", Whip";
    }

    double cost()
    {
        return .10 + beverage->cost();
    }
};

#endif