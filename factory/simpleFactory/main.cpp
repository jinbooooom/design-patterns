#include "PizzaStore.hpp"
#include "Pizza.hpp"
#include "SimplePizzaFactory.hpp"

#include <memory>

int main()
{
    auto factory = std::make_unique<SimplePizzaFactory>();
    auto store = std::make_unique<PizzaStore>(std::move(factory));

    auto cheesePizza = store->orderPizza("cheese");
    auto pepperoniPizza = store->orderPizza("pepperoni");

    return 0;
}
