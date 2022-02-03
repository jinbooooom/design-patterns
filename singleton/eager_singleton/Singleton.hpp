#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include "mylog.hpp"

/**
 * 饿汉模式
*/
class Singleton
{
private:
    static Singleton *sInstance;

protected:
    Singleton() { showfunc; };
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    virtual ~Singleton()
    {
        showfunc;
        sInstance = nullptr;
    };

public:
    static Singleton *getInstance()
    {
        showfunc;
        return sInstance;
    }

    class Garbo
    {
    public:
        ~Garbo()
        {
            if (Singleton::sInstance)
            {
                showfunc;
                delete Singleton::sInstance;
            }
        }
    };

    static Garbo garbo;
};

// 在 main 函数之前就完成对单例的初始化
Singleton *Singleton::sInstance = new Singleton();
// 在程序结束时自动析构单例，因为单例模式的构造和析构函数是 protected， 在 main 函数里无法访问
Singleton::Garbo garbo;

#endif
