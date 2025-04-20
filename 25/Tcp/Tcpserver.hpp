#pragma once
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "log.hpp"
#include "Common.hpp"

using namespace LogModule;


class TcpServer : public NoCopy
{
public:
    TcpServer()
    {
    }


    ~TcpServer()
    {
    }

private:
};