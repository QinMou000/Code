#include <iostream>
#include "UdpServer.hpp"

int main()
{
    UdpServer server(8080);
    server.Init();
    server.Start();
    return 0;
}