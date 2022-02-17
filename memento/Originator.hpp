#ifndef ORIGINATOR_HPP
#define ORIGINATOR_HPP

#include <string>
#include <memory>

#include "Memento.hpp"
#include <iostream>

class Originator
{
private:
    std::string mState;

public:
    Originator() : mState("") {}
    virtual ~Originator() = default;

    void setState(std::string s)
    {
        mState = s;
    }

    std::string getState()
    {
        return mState;
    }

    Memento *saveStateToMemento()
    {
        return new Memento(mState);
    }

    void restoreFromMemento(Memento *m)
    {
        if (nullptr == m)
        {
            setState("INIT");
        }
        else
        {
            setState(m->getState());
        }
    }

    friend std::ostream &operator<<(std::ostream &o, const Originator &ori)
    {
        o << "The state is " << ori.mState << std::endl;
        return o;
    }
};

#endif