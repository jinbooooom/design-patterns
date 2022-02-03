#ifndef TV_HPP
#define TV_HPP

#include <iostream>

class Tv
{
private:
    std::string mName = "TV";

public:
    Tv(std::string name)
        : mName(name)
    {
    }

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