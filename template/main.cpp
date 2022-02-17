#include "Tea.hpp"
#include "Coffee.hpp"

#include <memory>

int main()
{
    auto tea = std::make_unique<Tea>();
    auto coffee = std::make_unique<Coffee>();

    std::cout << "Making tea..." << std::endl;
    tea->prepareRecipe();

    std::cout << std::endl;

    std::cout << "Making coffee..." << std::endl;
    coffee->prepareRecipe();
}