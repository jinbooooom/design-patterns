#ifndef CHEESE_PIZZA_HPP
#define CHEESE_PIZZA_HPP

#include "Pizza.hpp"
#include "PizzaIngredientFactory.hpp"

#include <memory>

class CheesePizza : public Pizza
{
protected:
    std::unique_ptr<PizzaIngredientFactory> mIngredientFactory;

public:
    CheesePizza(std::unique_ptr<PizzaIngredientFactory> ingredientFactory)
        : mIngredientFactory(std::move(ingredientFactory)){};

    void prepare() override
    {
        std::cout << "now preparing CheesePizza..." << std::endl;
        dough = mIngredientFactory->createDough();
        std::cout << "Add " << dough->DoughProduct() << std::endl;
        sauce = mIngredientFactory->createSauce();
        std::cout << "Add " << sauce->SauceProduct() << std::endl;
    }
};

#endif