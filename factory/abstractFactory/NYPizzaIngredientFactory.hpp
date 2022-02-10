#ifndef NY_PIZZA_INGREDIENT_FACTORY_HPP
#define NY_PIZZA_INGREDIENT_FACTORY_HPP

#include "PizzaIngredientFactory.hpp"
#include "NYStyleDough.hpp"
#include "NYStyleSauce.hpp"

class NYPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    std::unique_ptr<Dough> createDough() override
    {
        std::unique_ptr<Dough> dough = std::make_unique<NYStyleDough>();
        return dough;
    }

    std::unique_ptr<Sauce> createSauce() override
    {
        std::unique_ptr<Sauce> sauce = std::make_unique<NYStyleSauce>();
        return sauce;
    }
};

#endif