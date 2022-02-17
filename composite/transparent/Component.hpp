#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Component
{
public:
    virtual ~Component() = default;

    virtual void add(Component *c) = 0;
    virtual void remove(Component *c) = 0;
    virtual void operation() = 0;
};

#endif