#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "Request.hpp"

class Handler
{
private:
    Handler *mNextChain;
    void sendRequestToNextHandler(const Request &req)
    {
        if (mNextChain != nullptr)
        {
            mNextChain->handle(req);
        }
        else
        {
            std::cout << "The request can‘t be processed!" << std::endl
                      << "request type = " << req.getReqType() << std::endl
                      << "request data = " << req.getReqData() << std::endl;
        }
    }

protected: // 每个具体　Ｈandler　是否能处理的条件不一样，且处理的方式也不一样，所以是纯虚函数。
    virtual bool canHandleRequest(const Request &req) = 0;
    virtual void processRequest(const Request &req) = 0;

public:
    Handler() { mNextChain = nullptr; }
    void setNextChain(Handler *next) { mNextChain = next; }

    void handle(const Request &req)
    {
        if (canHandleRequest(req))
            processRequest(req);
        else
            sendRequestToNextHandler(req);
    }
};

#endif