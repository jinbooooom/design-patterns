
#include "Director.hpp"
#include "LenovoBuilder.hpp"
#include "HuaweiBuilder.hpp"

int main()
{
    std::shared_ptr<Builder> builder = std::make_shared<LenovoBuilder>();
    std::shared_ptr<Director> director = std::make_shared<Director>(builder);
    std::shared_ptr<ComputerProduct> pc = director->construct();
    pc->show();

    std::cout << "-----------" << std::endl;

    builder = std::make_shared<HuaweiBuilder>();
    director = std::make_shared<Director>(builder);
    pc = director->construct();
    pc->show();

    return 0;
}