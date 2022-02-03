#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <mutex>

#include "mylog.hpp"

/**
 * 懒汉模式，加同步锁
*/
class Singleton
{
private:
    static Singleton *sInstance;
    static std::mutex sMutex;

        protected : Singleton()
    {
        showfunc;
    };
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
        std::lock_guard<std::mutex> lock(sMutex);
        if (nullptr == sInstance)
        {
            sInstance = new Singleton();
        }
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

// 需要的时候才被初始化
Singleton *Singleton::sInstance = nullptr;
// 在程序结束时自动析构单例，因为单例模式的构造和析构函数是 protected， 在 main 函数里无法访问
Singleton::Garbo garbo;
std::mutex Singleton::sMutex;

#endif
