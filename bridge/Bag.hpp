#ifndef BAG_HPP
#define BAG_HPP

#include "Color.hpp"

#include <memory>

class Bag
{
protected:
    std::unique_ptr<Color> mColor;

public:
    Bag(std::unique_ptr<Color> color) : mColor(std::move(color)){};
    virtual std::string buyBag() = 0;
};

#endif