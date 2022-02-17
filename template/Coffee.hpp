#ifndef COFFEE_HPP
#define COFFEE_HPP

#include "CaffeineBeverage.hpp"

#include <iostream>

class Coffee : public CaffeineBeverage
{
public:
    ~Coffee() {}

    void brew()
    {
        std::cout << "Dripping Coffee through filter" << std::endl;
    }

    void addCondiments()
    {
        std::cout << "Adding Sugar and Milk" << std::endl;
    }

    bool customerWantsCondiments()
    {
        char c;
        std::cout << "Would you like milk and sugar with your coffee (y/n)?" << std::endl;
        std::cin >> c;

        if (c == 'y')
            return true;
        else
            return false;
    }
};

#endif