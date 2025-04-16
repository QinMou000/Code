#include <iostream>
#include "UdpServer.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "use like this: ./server -port" << std::endl;
        exit(1);
    }

    uint16_t port = std::stoi(argv[1]);
    UdpServer server(port);
    server.Init();
    server.Start();
    return 0;
}