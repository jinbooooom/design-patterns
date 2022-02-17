#ifndef CONCRETE_COLLEAGUE_3_HPP
#define CONCRETE_COLLEAGUE_3_HPP

#include "Colleague.hpp"
#include "Mediator.hpp"
#include <iostream>

class ConcreteColleague3 : public Colleague
{
public:
    void receive() override
    {
        std::cout << "ConcreteColleague3 receive message." << std::endl;
    }
    
    void send() override
    {
        std::cout << "ConcreteColleague3 send message." << std::endl;
        mMediator->relay(this);
    }
};

#endif