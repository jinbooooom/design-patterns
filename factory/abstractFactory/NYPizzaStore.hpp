#ifndef NY_PIZZA_STORE_HPP
#define NY_PIZZA_STORE_HPP

#include "PizzaStore.hpp"
#include "NYPizzaIngredientFactory.hpp"
#include "CheesePizza.hpp"
#include "PepperoniPizza.hpp"

#include <memory>

class NYPizzaStore : public PizzaStore
{
public:
    std::unique_ptr<Pizza> createPizza(std::string type)
    {
        std::unique_ptr<Pizza> pizza = nullptr;
        auto ingredientFactory = std::make_unique<NYPizzaIngredientFactory>();

        if (type == "cheese")
        {
            pizza = std::make_unique<CheesePizza>(std::move(ingredientFactory));
            pizza->setName(std::string("NY Style Cheese Pizza"));
        }
        else if (type == "pepperoni")
        {
            pizza = std::make_unique<PepperoniPizza>(std::move(ingredientFactory));
            pizza->setName(std::string("NY Style Pepperoni Pizza"));
        }
        return pizza;
    }
};

#endif