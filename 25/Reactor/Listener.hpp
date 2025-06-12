#pragma once
#include <iostream>
#include <memory>
#include "Common.hpp"
#include "Socket.hpp"
#include "Connection.hpp"

class Listener : public Connection
{

public:
    Listener(int port)
        : _port(port),
          _listensock(std::make_unique<TcpSocket>())
    {
        _listensock->BuildTcpSocket(_port);
        SetEvent(EPOLLIN | EPOLLET); // TODO 要改为ET模式
    }
    void Recver()
    {
    }
    void Sender()
    {
    }
    void Excepter()
    {
    }
    int GetSockfd() override
    {
        return _listensock->Fd();
    }
    ~Listener() {}

private:
    std::unique_ptr<Socket> _listensock;
    int _port;
};
