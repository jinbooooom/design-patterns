#ifndef RED_HPP
#define RED_HPP

#include "Color.hpp"

class Red : public Color
{
public:
    virtual std::string getColor() override
    {
        return std::string("red");
    }
};

#endif