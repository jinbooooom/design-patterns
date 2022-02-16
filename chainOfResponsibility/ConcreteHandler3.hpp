#ifndef CONCRETE_HANDLER_3_HPP
#define CONCRETE_HANDLER_3_HPP

#include "Handler.hpp"

class ConcreteHandler3 : public Handler
{
protected:
    bool canHandleRequest(const Request &req) override
    {
        return req.getReqType() == RequestType::REQUEST_TYPE_3;
    }

    void processRequest(const Request &req) override
    {
        std::cout << "ConcreteHandler3 can handle Request: " << std::endl
                  << "request type = " << req.getReqType() << std::endl
                  << "request data = " << req.getReqData() << std::endl;

        // do something
    }
};

#endif