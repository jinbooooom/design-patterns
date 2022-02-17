#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include "Component.hpp"

#include <iostream>
#include <list>

class Composite : public Component
{
private:
    std::list<Component *> mChildren;

public:
    void add(Component *c) override
    {
        std::cout << "insert to Composite" << std::endl;
        mChildren.push_back(c);
    }

    virtual ~Composite() = default;

    void remove(Component *c) override
    {
        for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
        {
            if (c == *it)
            {
                std::cout << "remove" << std::endl;
                it = mChildren.erase(it);
                break;
            }
        }
    }

    void operation() override
    {
        for (const auto &x : mChildren)
        {
            x->operation();
        }
    }
};

#endif