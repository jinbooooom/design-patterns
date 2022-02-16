#ifndef YELLOW_HPP
#define YELLOW_HPP

#include "Color.hpp"

class Yellow : public Color
{
public:
    virtual std::string getColor() override
    {
        return std::string("yellow");
    }
};

#endif