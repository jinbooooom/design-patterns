#ifndef __UN_COMMAND_HPP__
#define __UN_COMMAND_HPP__

#include <string>
#include <iostream>

#include "Command.hpp"

class UndoCommand : public Command
{
public:
    virtual void execute() override
    {
        std::cout << "invalid/undo command" << std::endl;
    }
};

#endif