#include <iostream>
#include <string>

#include "ConcreteHandler1.hpp"
#include "ConcreteHandler2.hpp"
#include "ConcreteHandler3.hpp"

int main()
{
    ConcreteHandler1 h1;
    ConcreteHandler2 h2;
    ConcreteHandler3 h3;

    h1.setNextChain(&h2);
    h2.setNextChain(&h3);

    Request req("{to Handler3 data}", RequestType::REQUEST_TYPE_3);
    h1.handle(req);

    req = Request("{harder process data}", RequestType::REQUEST_TYPE_4);
    h1.handle(req);
    
    return 0;
}