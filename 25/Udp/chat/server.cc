#include <iostream>
#include "UdpServer.hpp"
#include "InetAddr.hpp"
#include "Route.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "use like this: ./server -port" << std::endl;
        exit(1);
    }

    uint16_t port = std::stoi(argv[1]);

    Route route;

    std::unique_ptr<UdpServer> svr = std::make_unique<UdpServer>(port, [&route](int sockfd, const std::string &message, InetAddr &peer)
                                                                 { route.messageRoute(sockfd, message, peer); });

    // LOG(LogLevel::INFO) << "make_unique success";

    svr->Init();
    // LOG(LogLevel::INFO) << "UdpServer Init success";

    // LOG(LogLevel::INFO) << "UdpServer Start success";
    svr->Start();

    return 0;
}