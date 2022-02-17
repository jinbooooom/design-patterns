#ifndef TEA_HPP
#define TEA_HPP

#include "CaffeineBeverage.hpp"

#include <iostream>

class Tea : public CaffeineBeverage
{
public:
    ~Tea() {}

    void brew()
    {
        std::cout << "Steeping the tea" << std::endl;
    }

    void addCondiments()
    {
        std::cout << "Adding Lemon" << std::endl;
    }

    bool customerWantsCondiments()
    {
        char c;
        std::cout << "Would you like lemon with your tea (y/n)?" << std::endl;
        std::cin >> c;

        if (c == 'y')
            return true;
        else
            return false;
    }
};

#endif