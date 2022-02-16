#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <iostream>

enum RequestType
{
    REQUEST_TYPE_1 = 1,
    REQUEST_TYPE_2,
    REQUEST_TYPE_3,
    REQUEST_TYPE_4,
    REQUEST_TYPE_5
};

class Request
{
private:
    std::string mData;
    RequestType mType;

public:
    Request(const std::string &data, RequestType type) : mData(data), mType(type) {}
    RequestType getReqType() const { return mType; }
    const std::string &getReqData() const { return mData; }
};

#endif