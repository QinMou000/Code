#pragma once
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class NoCopy
{
public:
    NoCopy() {}
    NoCopy(const NoCopy &) = delete;
    const NoCopy &operator=(const NoCopy &) = delete;
    ~NoCopy() {}
};

enum ExitCode
{
    OK = 0,
    USAGE_ERR,
    SOCKET_ERR,
    BIND_ERR,
    LISTEN_ERR,
    FORK_ERR,
    ACCEPT_ERR
};

#define CONV(addr) (struct sockaddr*)(&addr)