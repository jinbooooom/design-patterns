## 单例模式

确保一个类仅存在一个实例（如任务管理器，内存池等），并提供了对此唯一实例的全局访问点。可以认为单例是一种更加优雅的全局变量。相对于全局变量，它还有其他优点：

1. 确保一个类只创建一个实例
2. 为对象分配和销毁提供控制
3. 支持线程安全地访问对象的全局状态
4. 避免污染全局名字空间

为了阻止客户自行分配、销毁、复制该类对象，将默认构造、析构、复制构造和赋值操作符都声明为私有（或者protected，为了方便子类继承）并且不实现（= delete）。

### 饿汉模式

单例实例在类装载时就构建，急切初始化。[源码](.//eager_singleton/Singleton.hpp)

程序输出如下所示，可以看到Singleton的构造在main()函数之前，这样就保证了线程安全。

```
Singleton:15
start main()
getInstance:27
end main()
~Garbo:38
~Singleton:20
```

线程安全性： 实例在类加载的时候即被实例化，因此线程安全。

是否懒加载： 没有延迟加载，如果长时间没用到这个实例，则会造成内存的浪费。

性能： 性能比较好

### 懒汉模式-同步锁

```
start main()
getInstance:32
Singleton:19
end main()
~Garbo:48
~Singleton:25
```

线程安全性： 线程安全

是否懒加载： 懒加载

性能： 每次调用`getinstance()`都需要加锁和释放，使得多线程执行退化为串行执行，性能差，不推荐使用。

【注意】

C++中`volatile`等于插入编译器级别屏障，因此并不能阻止CPU硬件级别导致的重排。Java里加`volatile`就可以。

### 懒汉模式-双检锁（DCLP）

双重检查锁模式是一种非常好的单例实现模式，解决了单例、性能、线程安全问题，双重检测锁模式看上去完美无缺，如果不加内存屏障也会出现问题。

```C++
sInstance = new Singleton();
```

可以被拆分为：

1. 用operator new在堆上非配一块内存
2. 用placement new在刚刚分配的内存上调用构造函数以构造对象
3. 将已分配内存的指针赋予instance

在此3步中，2和3和可以调换的。这取决于编译器的实现或者CPU动态调度换序（尤其在多处理器环境下）。一旦一个A线程先执行3后执行2，另一个线程B在A之行为3后（还未执行2进行构造）发现instance已经非空，便不加锁直接访问，势必造成问题。

对于编译器而言，为了提高速度可能将一个变量缓存到寄存器而不写回，也可能为了效率交换2条不相干的相邻指令。那么使用volatile看似可以完美解决问题，volatile作用如下：

1. 阻止编译器对volatile变量进行优化，每次读写必须从内存里获取。
2. 阻止编译器调整volatile变量的指令顺序。

看似万无一失其实不然。volatile只能阻止编译器调整顺序，却无法阻止CPU动态调度换序。

在某些编译器中使用volatile可以达到内存同步的效果。但必须记住，这不是volatitle的设计意图，也不能通用地达到内存同步的效果。volatitle的语义只是防止编译器“优化”掉对内存的读写而已。它的合适用法，目前主要是用来读写映射到内存地址上的IO操作。由于volatile 不能在多处理器的环境下确保多个线程看到同样顺序的数据变化，在今天的通用程序中，不应该再看到volatitle的出现。

多处理器环境下，每个处理器都有各自的高速缓存，但所有处理器共享内存空间。这种架构需要设计者精确定义一个处理器该如何向共享内存执行写操作，又何时执行读操作，并使这个过程对其他处理器可见。我们很容易想象这样的场景：当某一个处理器在自己的高速缓存中更新的某个共享变量的值，但它并没有将该值更新至共享主存中，更不用说将该值更新到其他处理器的缓存中了。这种缓存间共享变量值不一致的情况被称为缓存一致性问题(cache coherency problem)。

[单例线程安全实现、DCLP及其注意事项、饿汉懒汉实现方式](https://blog.csdn.net/brahmsjiang/article/details/111186828?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EOPENSEARCH%7EHighlightScore-1.queryctrv2&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EOPENSEARCH%7EHighlightScore-1.queryctrv2&utm_relevant_index=1)

[volatile与内存屏障总结](https://zhuanlan.zhihu.com/p/43526907)