#include "Composite.hpp"
#include "Leaf.hpp"

#include <memory>

int main()
{
    Component *c0 = new Composite();
    Component *c1 = new Composite();
    Component *leaf1 = new Leaf(std::string("leaf1"));
    Component *leaf2 = new Leaf(std::string("leaf2"));
    Component *leaf3 = new Leaf(std::string("leaf3"));
    Component *leaf4 = new Leaf(std::string("leaf4"));
    Component *leaf5 = new Leaf(std::string("leaf5"));

    c0->add(leaf1);
    c0->add(c1);
    c0->add(leaf2);
    c1->add(leaf3);
    c1->add(leaf4);
    c1->add(leaf5);

    std:: cout << "traverse c0 " << std::endl;
    c0->operation();
    std:: cout << "traverse c1 " << std::endl;
    c1->operation();

    delete c0;
    delete c1;
    delete leaf1;
    delete leaf2;
    delete leaf3;
    delete leaf4;
    delete leaf5;

    return 0;
}
