#ifndef PEPPERONI_PIZZA_HPP
#define PEPPERONI_PIZZA_HPP

#include "Pizza.hpp"

class PepperoniPizza : public Pizza
{
public:
    PepperoniPizza()
    {
        name = "Pepperoni pizza";
        dough = "Thin crust dough";
        sauce = "Marinara sauce";
        toppings.push_back("Grated reggiano cheese");
        toppings.push_back("Sliced pepperoni");
        toppings.push_back("Garlic");
        toppings.push_back("Onion");
        toppings.push_back("Mushrooms");
        toppings.push_back("Red pepper");
    }
};

#endif
