#include "Espresso.hpp"
#include "Mocha.hpp"
#include "Whip.hpp"
#include "HouseBlend.hpp"

#include <iostream>

int main()
{
    std::unique_ptr<Beverage> b2 = std::make_unique<Espresso>(); // 创建一个新对象 Espresso
    //std::cout << b2->getDescription() << " $" << b2->cost() << std::endl;

    // 实例 Espresso 并没有被析构，而是被 move 到实例 Mocha 里的 beverage。
    b2 = std::make_unique<Mocha>(std::move(b2)); // 创建一个新对象，第一个 Mocha，其成员 beverage 指向 Espresso
    b2 = std::make_unique<Mocha>(std::move(b2)); // 创建一个新对象，第二个 Mocha，其成员 beverage 指向第一个 Mocha
    b2 = std::make_unique<Whip>(std::move(b2));  // 创建一个新对象 Whip，其成员 beverage 指向第二个 Mocha
    //std::cout << b2->getDescription() << " $" << b2->cost() << std::endl;

    //std::unique_ptr<Beverage> b3 = std::make_unique<HouseBlend>();
    //b3 = std::make_unique<Mocha>(std::move(b3));
    //std::cout << b3->getDescription() << " $" << b3->cost() << std::endl;
}