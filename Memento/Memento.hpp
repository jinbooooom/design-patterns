#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <string>

class Memento
{
private:
    std::string mState;

public:
    Memento(std::string s) : mState(s) {}
    virtual ~Memento() = default;

    void setState(std::string s)
    {
        mState = s;
    }

    std::string getState()
    {
        return mState;
    }
};

#endif