#ifndef MALLARDDUCK_HPP
#define MALLARDDUCK_HPP

#include "Duck.hpp"

class MallardDuck : public Duck
{
public:
    MallardDuck();

    virtual void display() override;
};

#endif