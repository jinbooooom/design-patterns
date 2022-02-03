#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <iostream>

class Light
{
private:
    std::string mName = "light";

public:
    Light(std::string name) : mName(name) {}

    void on()
    {
        std::cout << mName << " is on" << std::endl;
    }

    void off()
    {
        std::cout << mName << " is off" << std::endl;
    }
};

#endif
