#include <iostream>
#include <string>
#include <strings.h>
#include "log.hpp"
#include "thread.hpp"
#include "mutex.hpp"
#include <sys/socket.h> // 网络UDP四剑客
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace LogModule;

std::string server_ip;
uint16_t server_port;
int sockfd;
Mutex mutex;

void Send()
{
    // 2.绑定网络信息
    struct sockaddr_in server;
    bzero(&server, sizeof(server));                        // 初始化置零
    server.sin_family = AF_INET;                           // 指定IPv4族协议
    server.sin_port = htons(server_port);                  // 将端口转为网络序列
    server.sin_addr.s_addr = inet_addr(server_ip.c_str()); // 将主机的点分十进制字符串ip转化为网络序列的二进制数据

    // int n = bind(sockfd, (const struct sockaddr *)&local, sizeof(local)); // 不显式绑定，系统自动绑定本地可用端口

    while (1)
    {
        usleep(1000);
        std::string message;
        std::cout << "Please Enter# ";
        std::getline(std::cin, message);

        sendto(sockfd, message.c_str(), message.size(), 0, (const struct sockaddr *)&server, sizeof(server));

        if (message == "Q")
        {
            pthread_cancel(pthread_self());
            break;
        }
        // LOG(LogLevel::INFO) << "send to success";
    }
}

void Rcev()
{
    while (1)
    {
        char buffer[1024];
        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);
        int m = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&peer, &len);

        // LOG(LogLevel::INFO) << "recvfrom success";

        if (m > 0)
        {
            buffer[m] = 0;
            std::cout << buffer << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        LOG(LogLevel::ERROR) << "use like this ./client -ip -port";
        exit(1);
    }
    server_ip = argv[1];
    server_port = std::stoi(argv[2]);

    // 1.创建网络文件
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        LOG(LogLevel::FATAL) << "socket error";
        exit(1);
    }

    Thread send(Send);
    // LOG(LogLevel::FATAL) << "Thread send success";

    Thread recv(Rcev);
    // LOG(LogLevel::FATAL) << "Thread recv success";

    send.Start();
    // LOG(LogLevel::FATAL) << "send.Start() success";

    recv.Start();
    // LOG(LogLevel::FATAL) << "recv.Start() success";

    send.Join();
    // LOG(LogLevel::FATAL) << "send.Join success";

    recv.Join();
    // LOG(LogLevel::FATAL) << "recv.Join success";

    return 0;
}