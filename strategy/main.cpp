#include "MallardDuck.hpp"
#include "RedHeadDuck.hpp"
#include "DecoyDuck.hpp"
#include "RubberDuck.hpp"

#include "FlyWithWings.hpp"
#include "MuteQuack.hpp"

#include <iostream>

int main()
{
    /**
     * 每一只鸭子的 FlyBehavior 和 QuackBehavior 可能相同也可能不同，
     * 在构造鸭子的时候，在构造函数里为具体的鸭子初始化 FlyBehavior 和 QuackBehavior 行为。
    */
    MallardDuck mallard; // 绿头鸭
    mallard.display();
    mallard.swim();
    mallard.performQuack();
    mallard.performFly();

    std::cout << std::endl;

    RedHeadDuck redHead; // 红头鸭
    redHead.display();
    redHead.swim();
    redHead.performQuack();
    redHead.performFly();

    std::cout << std::endl;

    DecoyDuck decoy; // 诱饵鸭，木头假鸭，不会飞，也不会叫
    decoy.display();
    decoy.swim();
    decoy.performQuack();
    decoy.performFly();

    std::cout << std::endl;

    RubberDuck rubberDuckie; // 橡皮鸭，会吱吱叫，但不会飞
    rubberDuckie.display();
    rubberDuckie.swim();
    rubberDuckie.performQuack();
    rubberDuckie.performFly();

    // 现在重新设置行为，让 rubberDuckie 不能叫, 但可以飞。
    rubberDuckie.setQuackBehavior(std::make_unique<MuteQuack>());
    rubberDuckie.setFlyBehavior(std::make_unique<FlyWithWings>());

    std::cout << "after rubberDuckie set behavior" << std::endl;
    rubberDuckie.display();
    rubberDuckie.swim();
    rubberDuckie.performQuack();
    rubberDuckie.performFly();

    std::cout << std::endl;

    return 0;
}
