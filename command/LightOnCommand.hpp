#ifndef LIGHT_ON_COMMAND_HPP
#define LIGHT_ON_COMMAND_HPP

#include <string>
#include <iostream>

#include "Command.hpp"
#include "Light.hpp"

class LightOnCommand : public Command
{
private:
    Light *mLight;

public:
    LightOnCommand(Light *light) : mLight(light){};

    virtual void execute() override
    {
        mLight->on();
    }
};

#endif