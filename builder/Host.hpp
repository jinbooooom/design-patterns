#ifndef HOST_HPP
#define HOST_HPP

#include <string>
#include <iostream>

class Host
{
private:
    std::string mHost;

public:
    Host() : mHost("unknown host"){};

    void setHost(const std::string &host) { mHost = host; };

    friend std::ostream &operator<<(std::ostream &o, const Host &host)
    {
        o << host.mHost << std::endl;
        return o;
    }
};

#endif