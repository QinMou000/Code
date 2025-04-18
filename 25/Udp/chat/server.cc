#include <iostream>
#include <functional>
#include "UdpServer.hpp"
#include "InetAddr.hpp"
#include "Route.hpp"
#include "threadpool.hpp"

using task_t = std::function<void()>;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "use like this: ./server -port" << std::endl;
        exit(1);
    }

    uint16_t port = std::stoi(argv[1]);


    // std::unique_ptr<UdpServer> svr = std::make_unique<UdpServer>(port, [&route](int sockfd, const std::string &message, InetAddr &peer)
    //                                                              { route.messageRoute(sockfd, message, peer); });
    Route route;

    auto tp = ThreadPool<task_t>::GetInstance();

    auto svr = std::make_unique<UdpServer>(port,
                                           [&route, &tp](int sockfd, const std::string &message, InetAddr &peer)
                                           {
                                               task_t task = std::bind(&Route::messageRoute, &route, sockfd, message, peer);
                                               tp->Equeue(task);
                                           });

    // LOG(LogLevel::INFO) << "make_unique success";

    svr->Init();
    // LOG(LogLevel::INFO) << "UdpServer Init success";

    // LOG(LogLevel::INFO) << "UdpServer Start success";
    svr->Start();

    return 0;
}