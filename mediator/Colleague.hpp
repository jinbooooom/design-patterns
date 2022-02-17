#ifndef COLLEAGUE_HPP
#define COLLEAGUE_HPP

class Mediator;

class Colleague
{
protected:
    Mediator *mMediator = nullptr;

public:
    virtual ~Colleague() = default;

    void setMediator(Mediator *mediator)
    {
        mMediator = mediator;
    }

    virtual void receive() = 0;

    virtual void send() = 0;
};

#endif