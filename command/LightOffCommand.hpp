#ifndef LIGHT_OFF_COMMAND_HPP
#define LIGHT_OFF_COMMAND_HPP

#include <string>
#include <iostream>

#include "Command.hpp"
#include "Light.hpp"

class LightOffCommand : public Command
{
private:
    Light *mLight;

public:
    LightOffCommand(Light *light) : mLight(light){};

    virtual void execute() override
    {
        mLight->off();
    }
};

#endif