#pragma once
#include <memory>
#include "Common.hpp"
#include "Epoller.hpp"
#include "Connection.hpp"

class Reacctor // 反应堆容器
{

public:
    Reacctor()
        : _epoll(make_unique<Epoller>()),
          _isrunning(false)
    {
    }
    void Loop()
    {
        is_running = true;
        while (_isrunning)
        {
        }
        is_running = false;
    }
    Stop()
    {
        _isrunning = false;
    }
    ~Reacctor() {}

private:
    std::unique_ptr<Epoller> _epoll;                                  // epoll模型
    std::unordered_map<int, std::shared_ptr<Connection>> _connection; // 管理所有连接的哈希表 用fd来做索引
    bool _isrunning;
};