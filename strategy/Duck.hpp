#ifndef DUCK_HPP
#define DUCK_HPP

#include "FlyBehavior.hpp"
#include "QuackBehavior.hpp"

#include <memory>
#include <iostream>

class Duck
{
public:
    std::unique_ptr<FlyBehavior> flyBehavior;
    std::unique_ptr<QuackBehavior> quackBehavior;

    Duck(std::unique_ptr<FlyBehavior> fb,
         std::unique_ptr<QuackBehavior> qb)
        : flyBehavior(std::move(fb)),
          quackBehavior(std::move(qb))
    {
    }

    virtual ~Duck()
    {
    }

    // 下面两个函数使用了多态
    void performFly()
    {
        flyBehavior->fly();
    }

    void performQuack()
    {
        quackBehavior->quack();
    }

    // 所有的鸭子都有 swim 方法
    void swim()
    {
        std::cout << "All ducks swim!" << std::endl;
    }

    // 每个鸭子有不同的外观，交给子类去实现
    virtual void display() = 0;

    void setFlyBehavior(std::unique_ptr<FlyBehavior> fb)
    {
        flyBehavior = std::move(fb);
    }

    void setQuackBehavior(std::unique_ptr<QuackBehavior> qb)
    {
        quackBehavior = std::move(qb);
    }
};

#endif