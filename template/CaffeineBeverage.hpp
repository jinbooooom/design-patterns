#ifndef CAFFEINE_BEVERAGE_HPP
#define CAFFEINE_BEVERAGE_HPP

#include <iostream>

class CaffeineBeverage // 咖啡因饮料
{
public:
    virtual ~CaffeineBeverage() {}

    void prepareRecipe() // 准备食谱
    {
        boilWater();                   // 把水煮沸
        brew();                        // 用沸水冲泡具体饮料
        pourInCup();                   // 把饮料倒进杯子
        if (customerWantsCondiments()) // 根据用户需求加入调味品
            addCondiments();
    }

    /**
     * 这两个方法对于咖啡和茶有不同的实现
    */
    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    void boilWater()
    {
        std::cout << "Boiling water" << std::endl;
    }

    void pourInCup()
    {
        std::cout << "Pouring into cup" << std::endl;
    }

    /**
     * 钩子 hook 的存在，可以让子类有能力对算法的不同点进行挂钩。要不要挂钩，由子类说了算。
     * 这是一个钩子，子类可以覆盖这个方法，以此来决定自己是否需要执行某一部分算法。
    */
    virtual bool customerWantsCondiments() 
    {
        return true;
    }
};

#endif