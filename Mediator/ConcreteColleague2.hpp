#ifndef CONCRETE_COLLEAGUE_2_HPP
#define CONCRETE_COLLEAGUE_2_HPP

#include "Colleague.hpp"
#include "Mediator.hpp"
#include <iostream>

class ConcreteColleague2 : public Colleague
{
public:
    void receive() override
    {
        std::cout << "ConcreteColleague2 receive message." << std::endl;
    }
    
    void send() override
    {
        std::cout << "ConcreteColleague2 send message." << std::endl;
        mMediator->relay(this);
    }
};

#endif