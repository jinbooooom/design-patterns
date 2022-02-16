#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Pizza
{
public:
    std::string name;
    std::string dough;                 // 面团
    std::string sauce;                 // 调味汁
    std::vector<std::string> toppings; // 披萨上覆盖的一层奶酪，花生、蘑菇、辣椒等小料，可能有多种搭配

    const std::string &getName() const;

    virtual void prepare() const;
    virtual void bake() const;
    virtual void cut() const;
    virtual void box() const;
    virtual ~Pizza() = default;
};

const std::string &Pizza::getName() const
{
    return this->name;
}

void Pizza::prepare() const
{
    std::cout << "Preparing " + getName() << std::endl;
    std::cout << "Tossing dough..." << std::endl;
    std::cout << "Adding sauce..." << std::endl;
    std::cout << "Adding toppings: " << std::endl;
    for (auto &topping : this->toppings)
    {
        std::cout << "  " + topping + "\n";
    }
}

void Pizza::bake() const 
{
    std::cout << "Baking for 25 min at 350 degrees " << std::endl;
}

void Pizza::cut() const
{
    std::cout << "Cut the pizza into diagonal slices " << std::endl;
}
void Pizza::box() const
{
    std::cout << "Boxing in official PizzaStore boxes" << std::endl;
}

#endif