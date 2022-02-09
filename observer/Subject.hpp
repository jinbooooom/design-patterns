#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <unordered_set>

class Observer;

class Subject
{
protected:
    std::unordered_set<Observer *> mObservers; // 有一个无序set用来记录注册的观察者
public:
    virtual ~Subject() = default;
    virtual void registerObserver(Observer *) = 0;
    virtual void removeObserver(Observer *) = 0;
    virtual void notifyObservers() = 0;
};

#endif