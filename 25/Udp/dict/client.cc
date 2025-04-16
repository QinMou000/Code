#include <iostream>
#include <string>
#include <strings.h>
#include "log.hpp"
#include <sys/socket.h> // 网络UDP四剑客
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace LogModule;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        LOG(LogLevel::ERROR) << "use like this ./client -ip -port";
        exit(1);
    }
    std::string server_ip = argv[1];
    uint16_t server_port = std::stoi(argv[2]);

    // 1.创建网络文件
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        LOG(LogLevel::FATAL) << "socket error";
        exit(1);
    }
    // 2.绑定网络信息
    struct sockaddr_in server;
    bzero(&server, sizeof(server));                        // 初始化置零
    server.sin_family = AF_INET;                           // 指定IPv4族协议
    server.sin_port = htons(server_port);                  // 将端口转为网络序列
    server.sin_addr.s_addr = inet_addr(server_ip.c_str()); // 将主机的点分十进制字符串ip转化为网络序列的二进制数据

    // int n = bind(sockfd, (const struct sockaddr *)&local, sizeof(local)); // 不显式绑定，系统自动绑定本地可用端口

    while (1)
    {
        std::string message;
        std::cout << "Please# ";
        std::getline(std::cin, message);

        sendto(sockfd, message.c_str(), message.size(), 0, (const struct sockaddr *)&server, sizeof(server));
        
        LOG(LogLevel::INFO) << "send to success";

        char buffer[1024];
        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);
        int m = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&peer, &len);

        LOG(LogLevel::INFO) << "recvfrom success";
        
        if (m > 0)
        {
            buffer[m] = 0;
            std::cout <<  buffer << std::endl;
        }
    }

    return 0;
}