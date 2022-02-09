#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <memory>
class Observer
{
protected:
    std::shared_ptr<Subject> mSubject; // 考虑到以后想要取消注册，所以有了对 Subject 的引用会比较方便
public:
    Observer(std::shared_ptr<Subject> s) : mSubject(s){};

    virtual ~Observer() = default;
    virtual void update(float temp, float humidity, float pressure) = 0;
};

#endif
