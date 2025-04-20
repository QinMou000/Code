#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Common.hpp"
#include "log.hpp"
#include "InetAddr.hpp"

class Socket
{
public:
    ~Socket()
    {
    }
    virtual void SocketOrDie() = 0; // 纯虚函数，等子类实现
    virtual void BindOrDie() = 0;
    virtual void ListenOrDie() = 0;
    virtual std::shared_ptr<Socket> Accept(InetAddr *client) = 0;

public:
    void BuildTcpSocket()
    {
        SocketOrDie();
        BindOrDie();
        ListenOrDie();
    }

private:
};

const static int defaultfd = -1;

class TcpSocket : public Socket
{
public:
    TcpSocket() // 无参构造
        : _sockfd(defaultfd)
    {
    }
    TcpSocket(int fd)
        : _sockfd(fd)
    {
    }
    void SocketOrDie()
    {
    }
    void BindOrDie()
    {
    }
    void ListenOrDie()
    {
    }
    std::shared_ptr<Socket> Accept(InetAddr *client)
    {
    }
    int Send(const std::string meesage)
    {
    }
    ~TcpSocket()
    {
    }

private:
    int _sockfd; // 可以是监听端口，也可以是读写端口
};