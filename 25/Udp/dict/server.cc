#include <iostream>
#include "UdpServer.hpp"
#include "Dict.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "use like this: ./server -port" << std::endl;
        exit(1);
    }

    uint16_t port = std::stoi(argv[1]);

    Dict dict;
    dict.LoadWords();

    std::unique_ptr<UdpServer> svr = std::make_unique<UdpServer>(port, [&dict](const std::string &word) -> std::string
                                                                 { return dict.Translate(word); });
    LOG(LogLevel::INFO) << "make_unique success";

    svr->Init();
    LOG(LogLevel::INFO) << "UdpServer Init success";


    LOG(LogLevel::INFO) << "UdpServer Start success";
    svr->Start();

    return 0;
}