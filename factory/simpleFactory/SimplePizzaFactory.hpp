#ifndef SIMPLE_PIZZA_FACTORY_HPP
#define SIMPLE_PIZZA_FACTORY_HPP

#include "PizzaStore.hpp"
#include "Pizza.hpp"
#include "CheesePizza.hpp"
#include "PepperoniPizza.hpp"

#include <memory>
#include <string>

class SimplePizzaFactory
{
public:
    /**
     * 在简单工厂模式中创建实例的方法通常为静态（static）方法，因此简单工厂模式（Simple Factory Pattern）
     * 又叫作静态工厂方法模式（Static Factory Method Pattern）。它的优点是不需要创建简单工厂对象就可以创建产品。
     * 在 《head first 设计模式》，认为静态工厂方法有缺点，静态方法不能重写，不能通过继承来改变创建方法的行为（P115）
    */
    //static std::unique_ptr<Pizza> createPizza(std::string type)
    std::unique_ptr<Pizza> createPizza(std::string type)
    {
        std::unique_ptr<Pizza> pizza = nullptr;

        if (type == "cheese")
        {
            pizza = std::make_unique<CheesePizza>(); // 奶酪披萨
        }
        else if (type == "pepperoni")
        {
            pizza = std::make_unique<PepperoniPizza>(); // 意大利香肠披萨
        }
        return pizza;
    }
};

#endif