#ifndef CARETAKER_HPP
#define CARETAKER_HPP

#include "Memento.hpp"
#include <iostream>
#include <stack>

class Caretaker
{
private:
    std::stack<Memento *> mMementos;
public:
    Caretaker() = default;
    virtual ~Caretaker() {}

    void setMemento(Memento *m)
    {
        mMementos.push(m);
    }

    Memento *getMemento()
    {
        if (mMementos.empty())
        {
            std::cout << "The stack is empty, there is no saved state." << std::endl;
            return nullptr;
        }

        Memento* m = mMementos.top();
        mMementos.pop();
        return m;
    }
};

#endif