
#include "Singleton.hpp"

#include <iostream>

int main()
{
    std::cout << "start main()" << std::endl;

    Singleton *Singleton = Singleton::getInstance();

    std::cout << "end main()" << std::endl;

    return 0;
}

