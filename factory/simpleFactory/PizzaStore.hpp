#ifndef PIZZASTORE_HPP
#define PIZZASTORE_HPP

#include "Pizza.hpp"
#include "SimplePizzaFactory.hpp"

#include <memory>

class PizzaStore
{
private:
    std::unique_ptr<SimplePizzaFactory> mFactory;

public:
    PizzaStore(std::unique_ptr<SimplePizzaFactory> factory) : mFactory(std::move(factory)){};

    virtual std::unique_ptr<Pizza> orderPizza(std::string type) final // 禁用子类重写
    {
        auto pizza = mFactory->createPizza(type);
        if (pizza != nullptr)
        {
            std::cout << "\n--- Making a " + pizza->getName() + " ---\n \n";

            /**
             * 下面四个函数是做披萨的通用步骤，长期不变。
             * 准备、烘烤、切片、装盒
            */
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
        }
        return pizza;
    }
};

#endif