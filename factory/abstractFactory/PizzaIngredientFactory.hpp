#ifndef PIZZA_INGREDIENT_FACTORY_HPP
#define PIZZA_INGREDIENT_FACTORY_HPP

#include "Dough.hpp"
#include "Sauce.hpp"

#include <memory>

class PizzaIngredientFactory
{
public:
    virtual std::unique_ptr<Dough> createDough() = 0;
    virtual std::unique_ptr<Sauce> createSauce() = 0;
};

#endif