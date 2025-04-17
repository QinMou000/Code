#pragma once
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

class InetAddr
{
public:
    InetAddr(struct sockaddr_in &addr)
        : _addr(addr)
    {
        _port = ntohs(_addr.sin_port);
        _ip = inet_ntoa(_addr.sin_addr);
    }
    InetAddr(uint16_t port, std::string ip)
    {
        _port = port;
        _ip = ip;
    }
    uint16_t Port() { return _port; }
    std::string Ip() { return _ip; }
    std::string StringAddr()
    {
        return _ip + ":" + std::to_string(_port);
    }
    const struct sockaddr_in &SockAddrPtr()
    {
        return _addr;
    }
    socklen_t AddrLen()
    {
        return sizeof(_addr);
    }
    bool operator==(const InetAddr &addr)
    {
        return _port == addr._port && _ip == addr._ip;
    }
    ~InetAddr()
    {
    }

private:
    struct sockaddr_in _addr;
    uint16_t _port;
    std::string _ip;
};