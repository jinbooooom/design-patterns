#ifndef CHICAGO_PIZZA_STORE_HPP
#define CHICAGO_PIZZA_STORE_HPP

#include "PizzaStore.hpp"
#include "ChicagoPizzaIngredientFactory.hpp"
#include "CheesePizza.hpp"
#include "PepperoniPizza.hpp"

#include <memory>

class ChicagoPizzaStore : public PizzaStore
{
public:
    std::unique_ptr<Pizza> createPizza(std::string type)
    {
        std::unique_ptr<Pizza> pizza = nullptr;
        auto ingredientFactory = std::make_unique<ChicagoPizzaIngredientFactory>();

        if (type == "cheese")
        {
            pizza = std::make_unique<CheesePizza>(std::move(ingredientFactory));
            pizza->setName(std::string("Chicago Style Cheese Pizza"));
        }
        else if (type == "pepperoni")
        {
            pizza = std::make_unique<PepperoniPizza>(std::move(ingredientFactory));
            pizza->setName(std::string("Chicago Style Pepperoni Pizza"));
        }
        return pizza;
    }
};

#endif