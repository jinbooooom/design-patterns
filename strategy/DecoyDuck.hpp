#ifndef DECOYDUCK_HPP
#define DECOYDUCK_HPP

#include "Duck.hpp"

class DecoyDuck : public Duck
{
public:
    DecoyDuck();

    virtual void display() override;
};

#endif