#ifndef MY_LOG_HPP
#define MY_LOG_HPP

#include <iostream>

#if 1
#define showfunc std::cout << __func__ << ":" << __LINE__ << std::endl;
#else
#define showfunc
#endif

#endif