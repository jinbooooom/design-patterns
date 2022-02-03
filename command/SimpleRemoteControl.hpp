#ifndef SIMPLEREMOTECONTROL_HPP
#define SIMPLEREMOTECONTROL_HPP

#include "Command.hpp"
#include "UndoCommand.hpp"

static const unsigned int COMMAND_MAX(2);
class SimpleRemoteControl
{
private:
    Command *mOnCommand[COMMAND_MAX];
    Command *mOffCommand[COMMAND_MAX];
    Command *undoCommand = new UndoCommand();

public:
    SimpleRemoteControl()
    {
        for (unsigned int i = 0; i < COMMAND_MAX; ++i)
        {
            mOnCommand[i] = undoCommand;
            mOnCommand[i] = undoCommand;
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
            mOnCommand[slot] = onCommand;
            mOffCommand[slot] = offCommand;
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
            mOnCommand[slot]->execute();
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
            mOffCommand[slot]->execute();
        }
    }
};

#endif