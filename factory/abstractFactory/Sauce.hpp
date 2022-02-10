#ifndef SAUCE_HPP
#define SAUCE_HPP

#include <string>

class Sauce
{
public:
    /**
     * 返回一个字符串，就当是用原料工厂创建了一个制作披萨需要的原料之一 Sauce（调味汁）
    */
    virtual std::string SauceProduct() = 0;
};

#endif