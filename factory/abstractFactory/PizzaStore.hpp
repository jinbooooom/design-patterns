#ifndef PIZZASTORE_HPP
#define PIZZASTORE_HPP

#include "Pizza.hpp"

#include <memory>

class PizzaStore
{
public:
    virtual std::unique_ptr<Pizza> orderPizza(std::string type) final // 禁用子类重写
    {
        auto pizza = createPizza(type);
        if (pizza != nullptr)
        {
            std::cout << "\n--- Making a " + pizza->getName() + " ---\n \n";

            /**
             * 下面四个函数是做披萨的通用步骤，长期不变。
             * 准备、烘烤、切片、装盒.
             * 由于 pizza 是抽象的，这些操作并不知道是哪些具体类参与进来，这就是解耦。
            */
            pizza->prepare();
            pizza->bake();
            pizza->cut();
            pizza->box();
        }
        return pizza;
    }
    
    /**
     * 工厂方法将实例（披萨）的创建，推迟到具体工厂（子类）去完成
    */
    virtual std::unique_ptr<Pizza> createPizza(std::string type) = 0;
};

#endif