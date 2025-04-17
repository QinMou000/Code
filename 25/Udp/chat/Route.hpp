#pragma once
#include <iostream>
#include <set>
#include "InetAddr.hpp"
#include "log.hpp"

using namespace LogModule;

class Route
{
private:
    void DeleteUser(InetAddr peer)
    {
        for (auto it = _online_user.begin(); it != _online_user.end(); it++)
        {
            if (*it == peer)
            {
                LOG(LogLevel::INFO) << "删除一个在线用户" << peer.StringAddr();
                _online_user.erase(it);
                break;
            }
        }
    }
    void AddUser(InetAddr peer)
    {
        LOG(LogLevel::INFO) << "新增一个在线用户 " << peer.StringAddr();
        _online_user.push_back(peer);
    }
    bool IsExsit(InetAddr peer)
    {
        for (auto &e : _online_user)
        {
            if (e == peer)
                return true;
        }
        return false;
        // if (_online_user.find(peer) != _online_user.end())
        //     return true;
        // return false;
    }

public:
    Route()
    {
    }
    void messageRoute(int sockfd, std::string message, InetAddr peer)
    {
        if (!IsExsit(peer)) // 不存在就添加
        {
            AddUser(peer);
        }

        std::string res = peer.StringAddr() + ":" + message;

        for (auto &e : _online_user) // 路由给所有在线用户
        {
            LOG(LogLevel::INFO) << "转发给用户:" << peer.StringAddr();
            sendto(sockfd, res.c_str(), res.size(), 0, (const sockaddr *)&e.SockAddrPtr(), e.AddrLen());
        }

        if (message == "Q") // 特定信息退出
        {
            DeleteUser(peer);
        }
    }

    ~Route()
    {
    }

private:
    std::vector<InetAddr> _online_user;
};