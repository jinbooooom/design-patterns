#ifndef SUBJECT_HPP
#define SUBJECT_HPP

class Subject
{
public:
    virtual void request() = 0;
    virtual int requestAdd(int x, int y) = 0;
};

#endif