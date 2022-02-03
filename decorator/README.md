## 装饰者模式

## 关于析构的顺序
当 main 函数里的对象是下列的时候
```C++
std::unique_ptr<Beverage> b2 = std::make_unique<Espresso>(); // 创建一个新对象 Espresso
// 实例 Espresso 并没有被析构，而是被 move 到实例 Mocha 里的 beverage。
b2 = std::make_unique<Mocha>(std::move(b2)); // 创建一个新对象，第一个 Mocha，其成员 beverage 指向 Espresso
b2 = std::make_unique<Mocha>(std::move(b2)); // 创建一个新对象，第二个 Mocha，其成员 beverage 指向第一个 Mocha
b2 = std::make_unique<Whip>(std::move(b2));  // 创建一个新对象 Whip，其成员 beverage 指向第二个 Mocha
```

打印

```
Beverage
Beverage
CondimentDecorator
Mocha
Beverage
CondimentDecorator
Mocha
Beverage
CondimentDecorator
Whip
~Whip
~CondimentDecorator
~Mocha
~CondimentDecorator
~Mocha
~CondimentDecorator
~Beverage
~Beverage
~Beverage
~Beverage
```

析构函数析构的顺序和构造顺序不一致，是因为当析构到`CondimentDecorator`的时候，应先析构它的成员`std::unique_ptr<Beverage> beverage`（即第二个 `Mocha`），再去析构它的父类`Beverage`。故此时应是析构`Mocha`