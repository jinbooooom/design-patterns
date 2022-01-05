#ifndef REDHEADDUCK_HPP
#define REDHEADDUCK_HPP

#include "Duck.hpp"

class RedHeadDuck : public Duck
{
public:
    RedHeadDuck();

    virtual void display() override;
};

#endif