#ifndef SIMPLEREMOTECONTROL_HPP
#define SIMPLEREMOTECONTROL_HPP

#include "Command.hpp"
#include "UndoCommand.hpp"

static const unsigned int COMMAND_MAX(2);
class SimpleRemoteControl
{
private:
    Command *mOnCommands[COMMAND_MAX];
    Command *mOffCommands[COMMAND_MAX];
    Command *undoCommand = new UndoCommand();

public:
    SimpleRemoteControl()
    {
        for (unsigned int i = 0; i < COMMAND_MAX; ++i)
        {
            mOnCommands[i] = undoCommand;
            mOnCommands[i] = undoCommand;
        }
    }

    virtual ~SimpleRemoteControl()
    {
        if (nullptr != undoCommand)
        {
            delete undoCommand;
        }
    }

    void setCommand(unsigned int slot, Command *onCommand, Command *offCommand)
    {
        if (slot < COMMAND_MAX)
        {
            mOnCommands[slot] = onCommand;
            mOffCommands[slot] = offCommand;
        }
        else
        {
            std::cout << "invalie slot = " << slot << std::endl;
        }
    }

    void onButtonWasPressed(unsigned int slot)
    {
        if (slot >= COMMAND_MAX)
        {
            undoCommand->execute();
        }
        else
        {
            mOnCommands[slot]->execute();
        }
    }

    void offButtonWasPressed(unsigned int slot)
    {
        if (slot >= COMMAND_MAX)
        {
            undoCommand->execute();
        }
        else
        {
            mOffCommands[slot]->execute();
        }
    }
};

#endif