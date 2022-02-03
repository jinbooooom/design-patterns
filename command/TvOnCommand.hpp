#ifndef TV_ON_COMMAND_HPP
#define TV_ON_COMMAND_HPP

#include <string>
#include <iostream>

#include "Command.hpp"
#include "Tv.hpp"

class TvOnCommand : public Command
{
private:
    Tv *mTv;

public:
    TvOnCommand(Tv *Tv) : mTv(Tv){};

    virtual void execute() override
    {
        mTv->on();
    }
};

#endif