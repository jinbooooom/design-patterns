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

    void add(Component *c) override {}

    void remove(Component *c) override {}

    void operation() override
    {
        std::cout << "Leaf: " << mValue << " has been visited." << std::endl;
    }
};

#endif