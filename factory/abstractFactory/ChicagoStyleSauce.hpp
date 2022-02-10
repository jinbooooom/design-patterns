#ifndef CHICAGO_STYLE_SAUCE_HPP
#define CHICAGO_STYLE_SAUCE_HPP

#include "Sauce.hpp"

class ChicagoStyleSauce : public Sauce
{
public:
    std::string SauceProduct() override
    {
        return "Chicago style sauce";
    }
};

#endif
