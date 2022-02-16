#ifndef CONCRETE_HANDLER_1_HPP
#define CONCRETE_HANDLER_1_HPP

#include "Handler.hpp"

class ConcreteHandler1 : public Handler
{
protected:
    bool canHandleRequest(const Request &req) override
    {
        return req.getReqType() == RequestType::REQUEST_TYPE_1;
    }

    void processRequest(const Request &req) override
    {
        std::cout << "ConcreteHandler1 can handle Request: " << std::endl
                  << "request type = " << req.getReqType() << std::endl
                  << "request data = " << req.getReqData() << std::endl;

        // do something
    }
};

#endif