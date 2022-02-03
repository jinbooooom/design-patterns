#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <mutex>
#include <thread>
#include <atomic>

#include "mylog.hpp"

/**
 * 懒汉模式，双检锁（DCLP, Double-Checked Locking Pattern）
*/
class Singleton
{
private:
    //static Singleton *sInstance;
    static std::atomic<Singleton *> sInstance;
    static std::mutex sMutex;

protected:
    Singleton()
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
        Singleton *tmp = sInstance.load(std::memory_order_relaxed);
        std::atomic_thread_fence(std::memory_order_acquire); //获取内存fence
        if (nullptr == tmp)
        {
            std::lock_guard<std::mutex> lock(sMutex);
            tmp = sInstance.load(std::memory_order_relaxed);
            if (nullptr == tmp)
            {
                tmp = new Singleton;
                std::atomic_thread_fence(std::memory_order_release); //释放内存fence
                sInstance.store(tmp, std::memory_order_relaxed);
            }
        }
        return tmp;
    }

    /**
     * C++ 20 引入方法 barrier()，设置内存屏障
    */
    // static Singleton *getInstance()
    // {
    //     showfunc;
    //     if (nullptr == sInstance)
    //     {
    //         std::lock_guard<std::mutex> lock(sMutex);
    //         if (nullptr == sInstance)
    //         {
    //             Singleton *tmp = new Singleton();
    //             barrier();
    //             sInstance = tmp;
    //         }
    //     }
    //     return sInstance;
    // }

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

// 需要的时候才被初始化, 且是原子性的。
std::atomic<Singleton *> Singleton::sInstance(nullptr);
// 在程序结束时自动析构单例，因为单例模式的构造和析构函数是 protected， 在 main 函数里无法访问
Singleton::Garbo garbo;
std::mutex Singleton::sMutex;

#endif
