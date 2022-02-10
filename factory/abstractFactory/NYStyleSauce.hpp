#ifndef NY_STYLE_SAUCE_HPP
#define NY_STYLE_SAUCE_HPP

#include "Sauce.hpp"

class NYStyleSauce : public Sauce
{
public:
    std::string SauceProduct() override
    {
        return "NY stype sauce";
    }
};

#endif
