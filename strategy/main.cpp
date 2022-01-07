#include "MallardDuck.hpp"
#include "RedHeadDuck.hpp"
#include "DecoyDuck.hpp"
#include "RubberDuck.hpp"

#include "FlyWithWings.hpp"
#include "MuteQuack.hpp"

#include <iostream>

int main()
{
    MallardDuck mallard;
    mallard.display();
    mallard.swim();
    mallard.performQuack();
    mallard.performFly();

    std::cout << std::endl;

    RedHeadDuck redHead;
    redHead.display();
    redHead.swim();
    redHead.performQuack();
    redHead.performFly();

    std::cout << std::endl;

    DecoyDuck decoy;
    decoy.display();
    decoy.swim();
    decoy.performQuack();
    decoy.performFly();

    std::cout << std::endl;

    RubberDuck rubberDuckie;
    rubberDuckie.display();
    rubberDuckie.swim();
    rubberDuckie.performQuack();
    rubberDuckie.performFly();

    // 现在让 rubberDuckie 不能叫, 但可以飞。
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
