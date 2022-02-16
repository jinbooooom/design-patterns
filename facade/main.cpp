
#include "Facade.hpp"

int main()
{
    auto facade = std::make_unique<Facade>();
    facade->method();

    return 0;
}