#include <iostream>
#include <string>
#include "log.hpp"
#include <sys/socket.h> // 网络UDP四剑客
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const uint16_t defaultport = 8080;

using namespace LogModule;

class UdpServer
{

public:
    UdpServer(uint16_t port)
        : _port(defaultport),
          _sockfd(-1)
    {
    }
    void Init(std::string &ip)
    {
        // 1.创建网络文件
        _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (_sockfd < 0)
        {
            LOG(LogLevel::FATAL) << "socket error";
            exit(1);
        }

        // 2.绑定网络信息
    }
    void Start() // 收到消息，echo 回去即可
    {
    }
    ~UdpServer()
    {
    }

private:
    int _sockfd;
    uint16_t _port; // 本地端口号
    std::string _ip; // 本地点分十进制ip
};
