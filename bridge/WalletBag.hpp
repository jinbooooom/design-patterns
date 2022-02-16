#ifndef WALLET_BAG_HPP
#define WALLET_BAG_HPP

#include "Bag.hpp"

class WalletBag : public Bag // 钱包
{
public:
    WalletBag(std::unique_ptr<Color> color) : Bag(std::move(color)) {}

    virtual std::string buyBag() override
    {
        return mColor->getColor() + std::string(" WalletBag");
    }
};

#endif