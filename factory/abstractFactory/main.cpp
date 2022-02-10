
#include "ChicagoPizzaStore.hpp"
#include "NYPizzaStore.hpp"
#include "PizzaStore.hpp"
#include "Pizza.hpp"

#include <memory>

int main()
{

    auto chicagoStore = std::make_unique<ChicagoPizzaStore>();
    auto chicagoCheese = chicagoStore->orderPizza("cheese");
    auto chicagoPepperoni = chicagoStore->orderPizza("pepperoni");

    auto nyStore = std::make_unique<NYPizzaStore>();
    auto nyCheese = nyStore->orderPizza("cheese");
    auto nyPepperoni = nyStore->orderPizza("pepperoni");

    return 0;
}
