#ifndef CHICAGO_PIZZA_INGREDIENT_FACTORY_HPP
#define CHICAGO_PIZZA_INGREDIENT_FACTORY_HPP

#include "PizzaIngredientFactory.hpp"
#include "ChicagoStyleDough.hpp"
#include "ChicagoStyleSauce.hpp"

class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    std::unique_ptr<Dough> createDough() override
    {
        std::unique_ptr<Dough> dough = std::make_unique<ChicagoStyleDough>();
        return dough;
    }

    std::unique_ptr<Sauce> createSauce() override
    {
        std::unique_ptr<Sauce> sauce = std::make_unique<ChicagoStyleSauce>();
        return sauce;
    }
};

#endif