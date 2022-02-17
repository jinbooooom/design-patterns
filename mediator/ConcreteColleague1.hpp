#ifndef CONCRETE_COLLEAGUE_1_HPP
#define CONCRETE_COLLEAGUE_1_HPP

#include "Colleague.hpp"
#include "Mediator.hpp"
#include <iostream>

class ConcreteColleague1 : public Colleague
{
public:
    void receive() override
    {
        std::cout << "ConcreteColleague1 receive message." << std::endl;
    }
    
    void send() override
    {
        std::cout << "ConcreteColleague1 send message." << std::endl;
        mMediator->relay(this);
    }
};

#endif