#include <iostream>
#include <string>
#include <functional>
#include <strings.h>
#include "log.hpp"
#include "Dict.hpp"
#include <sys/socket.h> // 网络UDP四剑客
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const uint16_t defaultport = 8080;

using translate_t = std::function<std::string(std::string)>;

using namespace LogModule;

class UdpServer
{

public:
    UdpServer(uint16_t port, translate_t func)
        : _port(defaultport),
          _sockfd(-1),
          _func(func)
    {
    }
    void Init()
    {
        // 1.创建网络文件
        _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (_sockfd < 0)
        {
            LOG(LogLevel::FATAL) << "socket error";
            exit(1);
        }

        // 2.绑定网络信息
        struct sockaddr_in local;           // 绑定本地ip和端口号
        bzero(&local, sizeof(local));       // 初始化置零
        local.sin_family = AF_INET;         // 指定IPv4族协议
        local.sin_port = htons(_port);      // 将端口转为网络序列
        local.sin_addr.s_addr = INADDR_ANY; // Address to accept any incoming messages.
                                            // #define	INADDR_ANY		((in_addr_t) 0x00000000)
        // 一个主机可能有多个网卡，不用绑定特定ip，0.0.0.0就是默认监听所有可用ip

        int n = bind(_sockfd, (const struct sockaddr *)&local, sizeof(local));
        if (n != 0)
        {
            LOG(LogLevel::FATAL) << "bind error";
            exit(2);
        }
    }
    void Start() // 收到消息，echo 回去即可
    {
        while (1)
        {
            // 1.收到消息
            struct sockaddr_in peer; // 定义客户端，
            char buffer[1024];
            unsigned int len = sizeof(peer); // 传回来的len会改变不能乱写，
            LOG(LogLevel::INFO) << "in the front of recvfrom ";
            ssize_t n = recvfrom(_sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&peer, &len);
            
            buffer[n] = 0;
            LOG(LogLevel::INFO) << "recvfrom success:" << buffer;

            if (n > 0)
            {
                // 2.调用翻译函数，结果发回去

                std::string ret = _func(buffer);

                LOG(LogLevel::INFO) << "translate success";

                sendto(_sockfd, ret.c_str(), ret.size(), 0, (const struct sockaddr *)&peer, len);

                LOG(LogLevel::INFO) << "sendto success";

                // // 2.echo 回去
                // buffer[n] = 0;
                // sendto(_sockfd, buffer, sizeof(buffer), 0, (const struct sockaddr *)&peer, len);
                // std::cout << htons(peer.sin_port) << htons(peer.sin_addr.s_addr) << std::endl;
            }
        }
    }
    ~UdpServer()
    {
    }

private:
    int _sockfd;
    uint16_t _port; // 本地端口号
    // std::string _ip; // 本地点分十进制ip //
    translate_t _func;
};
