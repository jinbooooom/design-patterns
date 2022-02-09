#ifndef BEVERAGE_HPP
#define BEVERAGE_HPP

#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

#if 1
#define mylog fprintf(stdout, "%s\n", __func__);
#else
#define mylog
#endif

class Beverage
{
public:
    virtual std::string getDescription()
    {
        return "Unkown Beverage";
    }

    virtual double cost() = 0;
    
    Beverage()
    {
        mylog;
    }

    virtual ~Beverage()
    {
        mylog;
    };
};

#endif