#ifndef TV_OFF_COMMAND_HPP
#define TV_OFF_COMMAND_HPP

#include <string>
#include <iostream>

#include "Command.hpp"
#include "Tv.hpp"

class TvOffCommand : public Command
{
private:
    Tv *mTv;

public:
    TvOffCommand(Tv *Tv) : mTv(Tv){};

    virtual void execute() override
    {
        mTv->off();
    }
};

#endif