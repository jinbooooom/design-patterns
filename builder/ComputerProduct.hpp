#ifndef COMPUTER_PRODUCT_HPP
#define COMPUTER_PRODUCT_HPP

#include "Host.hpp"
#include "Monitor.hpp"

#include <iostream>

class ComputerProduct
{
private:
    Host mHost;       // 电脑主机
    Monitor mMonitor; // 显示器

public:
    void setHost(const std::string &host) { mHost.setHost(host); }
    void setMonitor(const std::string &monitor) { mMonitor.setMonitor(monitor); }

    void show()
    {
        std::cout << "Host = " << mHost << "Monitor = " << mMonitor;
    }
};

#endif