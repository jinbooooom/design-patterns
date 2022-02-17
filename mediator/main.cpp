#include "ConcreteColleague1.hpp"
#include "ConcreteColleague2.hpp"
#include "ConcreteColleague3.hpp"
#include "ConcreteMediator.hpp"

#include "iostream"

int main()
{
    Mediator *md = new ConcreteMediator();
    Colleague *c1 = new ConcreteColleague1();
    Colleague *c2 = new ConcreteColleague2();
    Colleague *c3 = new ConcreteColleague3();

    md->registerColleague(c1);
    md->registerColleague(c2);
    md->registerColleague(c3);

    c1->send();
    std::cout << std::endl;
    c2->send();
    std::cout << std::endl;
    c3->send();

    delete md;
    delete c1;
    delete c2;
    delete c3;

    return 0;
}