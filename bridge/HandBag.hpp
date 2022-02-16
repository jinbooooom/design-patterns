#ifndef HAND_BAG_HPP
#define HAND_BAG_HPP

#include "Bag.hpp"

class HandBag : public Bag // 挎包
{
public:
    HandBag(std::unique_ptr<Color> color) : Bag(std::move(color)) {}

    virtual std::string buyBag() override
    {
        return mColor->getColor() + std::string(" HandBag");
    }
};

#endif