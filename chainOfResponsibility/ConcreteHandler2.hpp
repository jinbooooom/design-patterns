#ifndef CONCRETE_HANDLER_2_HPP
#define CONCRETE_HANDLER_2_HPP

#include "Handler.hpp"

class ConcreteHandler2 : public Handler
{
protected:
    bool canHandleRequest(const Request &req) override
    {
        return req.getReqType() == RequestType::REQUEST_TYPE_2;
    }

    void processRequest(const Request &req) override
    {
        std::cout << "ConcreteHandler2 can handle Request: " << std::endl
                  << "request type = " << req.getReqType() << std::endl
                  << "request data = " << req.getReqData() << std::endl;

        // do something
    }
};

#endif