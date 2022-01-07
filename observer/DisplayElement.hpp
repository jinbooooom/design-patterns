#ifndef DISPLAY_ELEMENT_HPP
#define DISPLAY_ELEMENT_HPP

class DisplayElement
{
public:
    virtual ~DisplayElement() = default;
    virtual void display() = 0;
};

#endif