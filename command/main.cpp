#include "Light.hpp"
#include "LightOnCommand.hpp"
#include "LightOffCommand.hpp"
#include "Tv.hpp"
#include "TvOnCommand.hpp"
#include "TvOffCommand.hpp"
#include "SimpleRemoteControl.hpp"

int main()
{
    SimpleRemoteControl *remote = new SimpleRemoteControl();
    remote->onButtonWasPressed(0); // invalid
    Light *light = new Light("The light in the living room");
    Tv *tv = new Tv("My TV");
    LightOnCommand *lightOn = new LightOnCommand(light);
    LightOffCommand *lightOff = new LightOffCommand(light);
    TvOnCommand *tvOn = new TvOnCommand(tv);
    TvOffCommand *tvOff = new TvOffCommand(tv);

    remote->setCommand(0, lightOn, lightOff);
    remote->setCommand(1, tvOn, tvOff);
    remote->setCommand(999, tvOn, tvOff); // invalid

    remote->onButtonWasPressed(0);
    remote->offButtonWasPressed(0);
    remote->onButtonWasPressed(1);
    remote->offButtonWasPressed(1);

    remote->onButtonWasPressed(999); // invalid
    remote->offButtonWasPressed(-1); // invalid

    delete remote;
    delete light;
    delete lightOn;
    delete lightOff;
    delete tv;
    delete tvOn;
    delete tvOff;

    return 0;
}