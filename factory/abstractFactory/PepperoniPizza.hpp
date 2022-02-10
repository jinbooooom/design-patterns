#ifndef PEPPERONI_PIZZA_HPP
#define PEPPERONI_PIZZA_HPP

#include "Pizza.hpp"
#include "PizzaIngredientFactory.hpp"

#include <memory>

class PepperoniPizza : public Pizza
{
protected:
    std::unique_ptr<PizzaIngredientFactory> mIngredientFactory;

public:
    PepperoniPizza(std::unique_ptr<PizzaIngredientFactory> ingredientFactory)
        : mIngredientFactory(std::move(ingredientFactory)){};

    void prepare() override
    {
        std::cout << "now preparing PepperoniPizza..." << std::endl;
        dough = mIngredientFactory->createDough();
        std::cout << "Add " << dough->DoughProduct() << std::endl;
        sauce = mIngredientFactory->createSauce();
        std::cout << "Add " << sauce->SauceProduct() << std::endl;
    }
};

#endif