#include "Proxy.hpp"

#include <memory>

int main()
{
    auto proxy = std::make_unique<Proxy>();
    proxy->request();
    proxy->requestAdd(2, 3);
}
