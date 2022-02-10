#ifndef NY_STYLE_DOUGH_HPP
#define NY_STYLE_DOUGH_HPP

#include "Dough.hpp"

class NYStyleDough : public Dough
{
public:
    std::string DoughProduct() override
    {
        return "NY style dough";
    }
};

#endif
