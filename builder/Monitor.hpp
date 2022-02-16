#ifndef MONITOR_HPP
#define MONITOR_HPP

#include <string>

class Monitor
{
private:
    std::string mMonitor;

public:
    Monitor() : mMonitor("unknown monitor"){};

    void setMonitor(const std::string &monitor) { mMonitor = monitor; };

    friend std::ostream &operator<<(std::ostream &o, const Monitor &monitor)
    {
        o << monitor.mMonitor << std::endl;
        return o;
    }
};

#endif