#ifndef CHICAGO_STYLE_DOUGH_HPP
#define CHICAGO_STYLE_DOUGH_HPP

#include "Dough.hpp"

class ChicagoStyleDough : public Dough
{
public:
    std::string DoughProduct() override
    {
        return "Chicago style Dough";
    }
};

#endif