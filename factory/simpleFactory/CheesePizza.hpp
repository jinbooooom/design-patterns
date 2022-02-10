#ifndef CHEESE_PIZZA_HPP
#define CHEESE_PIZZA_HPP

#include "Pizza.hpp"

class CheesePizza : public Pizza
{
public:
    CheesePizza()
    {
        name = "Cheese pizza";
        dough = "Thin crust dough";
        sauce = "Marinara sauce";
        toppings.push_back("Gratted reggiano cheese");
    }
};

#endif