#pragma once
#include "Common.hpp"

using namespace LogModule;

class Request
{
public:
    std::string Serialize()
    {
    }
    bool Deserialize(std::string mesg)
    {
    }

private:
    float _x;
    float _y;
    char _oper;
};

class Response
{
public:
    std::string Serialize()
    {
    }
    bool Deserialize(std::string mesg)
    {
    }

private:
    float _res;
    int code; // 0表示结果可信
};

class Protocol
{
    GetRequest()
    {
    }
};