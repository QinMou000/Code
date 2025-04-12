#include <iostream>
#include <string>
#include "log.hpp"
#include <sys/socket.h> // 网络UDP四剑客
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    // 1.创建网络文件
    _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (_sockfd < 0)
    {
        LOG(LogLevel::FATAL) << "socket error";
        exit(1);
    }

    return 0;
}