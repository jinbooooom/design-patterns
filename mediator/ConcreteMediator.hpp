#ifndef CONCRETE_MEDIATOR_HPP
#define CONCRETE_MEDIATOR_HPP

#include "Mediator.hpp"
#include <list>
#include <algorithm>

class ConcreteMediator : public Mediator
{
private:
    std::list<Colleague *> mColleagues;

public:
    void registerColleague(Colleague *colleague) override
    {
        if (mColleagues.end() == std::find(mColleagues.begin(), mColleagues.end(), colleague))
        {
            mColleagues.push_back(colleague);
            colleague->setMediator(this);
        }
    }

    void relay(Colleague *colleague) override
    {
        for (const auto &x : mColleagues)
        {
            if (x != colleague)
            {
                x->receive();
            }
        }
    }
};

#endif