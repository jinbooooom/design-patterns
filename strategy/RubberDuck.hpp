#ifndef RUBBERDUCK_HPP
#define RUBBERDUCK_HPP

#include "Duck.hpp"

class RubberDuck : public Duck
{
public:
    RubberDuck();

    virtual void display() override;
};

#endif