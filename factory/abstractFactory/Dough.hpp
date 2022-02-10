#ifndef DOUGH_HPP
#define DOUGH_HPP

#include <string>

class Dough
{
public:
    /**
     * 返回一个字符串，就当是用原料工厂创建了一个制作披萨需要的原料之一 Dough（面团）
    */
    virtual std::string DoughProduct() = 0;
    //virtual std::string DoughString() { return std::string("no dough\n"); };
};

#endif