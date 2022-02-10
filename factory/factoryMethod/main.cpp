#include "NYPizzaStore.hpp"
#include "ChicagoPizzaStore.hpp"
#include "PizzaStore.hpp"
#include "Pizza.hpp"

int main()
{
    auto nyStore = std::make_unique<NYPizzaStore>();
    auto chicagoStore = std::make_unique<ChicagoPizzaStore>();

    auto nyCheese = nyStore->orderPizza("cheese");
    auto chicagoCheese = chicagoStore->orderPizza("cheese");

    return 0;
}
