#pragma once
#include <memory>
#include "Common.hpp"
#include "Epoller.hpp"
#include "Connection.hpp"

using namespace LogModule;

class Reactor // 反应堆容器
{
    static const int _revs_num = 128;

private:
    bool IsConExistsHelper(int sockfd)
    {
        if (_connection.find(sockfd) == _connection.end())
            return false;
        return true;
    }
    bool IsConExists(std::shared_ptr<Connection> &con)
    {
        return IsConExistsHelper(con->GetSockfd());
    }
    bool IsConExists(int sockfd)
    {
        return IsConExistsHelper(sockfd);
    }
    int LoopOnce(int timeout)
    {
        return _epoll->WaitEvent(_revs, _revs_num, timeout);
    }

    void Dispatcher(int n)
    {
        LOG(LogLevel::DEBUG) << n << "个事件就绪了";
        for (int i = 0; i < n; i++)
        {
            // TODO
        }
    }

public:
    Reactor()
        : _epoll(std::make_unique<Epoller>()),
          _isrunning(false)
    {
    }
    void Loop()
    {
        _isrunning = true;
        int timeout = -1; // 设置为阻塞
        while (_isrunning)
        {
            int n = LoopOnce(timeout);
            Dispatcher(n); // 将返回值（有多少个事件就绪了）传给事件派发器
        }
        _isrunning = false;
    }
    void AddConnection(std::shared_ptr<Connection> &con)
    {
        // 避免重复添加
        if (IsConExists(con))
        {
            LOG(LogLevel::WARNING) << "con is exists: " << con->GetSockfd();
            return;
        }
        // 将连接加入epoll模型，并写透到内核
        int sockfd = con->GetSockfd();
        uint32_t events = con->GetEvent();
        _epoll->AddEvent(sockfd, events);

        // 设置回指指针
        con->SetOwner(this);

        // 添加{fd, con}到hash里面
        _connection[sockfd] = con;
    }
    void Stop()
    {
        _isrunning = false;
    }
    ~Reactor() {}

private:
    std::unique_ptr<Epoller> _epoll;                                  // epoll模型
    std::unordered_map<int, std::shared_ptr<Connection>> _connection; // 管理所有连接的哈希表 用fd来做索引
    struct epoll_event _revs[_revs_num];                              // 管理epoll要关心的事件
    bool _isrunning;
};