#ifndef LEAF_HPP
#define HEAF_HPP

#include "Component.hpp"

#include <string>
#include <iostream>

class Leaf : public Component
{
private:
    std::string mValue;

public:
    Leaf(std::string v) : mValue(v) {}

    virtual ~Leaf() = default;

    void operation() override
    {
        std::cout << "Leaf: " << mValue << " has been visited." << std::endl;
    }
};

#endif