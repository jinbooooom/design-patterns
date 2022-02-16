
#include "HandBag.hpp"
#include "WalletBag.hpp"
#include "Red.hpp"
#include "Yellow.hpp"

int main()
{
    std::unique_ptr<Color> color = std::make_unique<Red>();
    std::unique_ptr<Bag> bag = std::make_unique<HandBag>(std::move(color));
    std::cout << "buy: " << bag->buyBag() << std::endl; 

    std::cout << "-----------" << std::endl;

    color = std::make_unique<Yellow>();
    bag = std::make_unique<WalletBag>(std::move(color));
    std::cout << "buy: " << bag->buyBag() << std::endl; 

    return 0;
}