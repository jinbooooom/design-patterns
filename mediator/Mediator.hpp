#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include "Colleague.hpp"
#include <list>
class Mediator
{
public:
    virtual ~Mediator() = default;
    virtual void registerColleague(Colleague *colleague) = 0;
    virtual void relay(Colleague *colleague) = 0;
};

#endif