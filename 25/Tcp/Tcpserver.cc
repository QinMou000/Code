#include "Tcpserver.hpp"
#include "Socket.hpp"
#include "Common.hpp"

void Usage(std::string proc)
{
    std::cerr << "Usage: " << proc << " port " << std::endl;
}

// ./server port
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(USAGE_ERR);
    }
    uint16_t server_port = std::stoi(argv[1]);

    TcpServer server(server_port, [](std::shared_ptr<Socket> &sock, InetAddr &addr)
                     { printf("hello world\n"); });

    return 0;
}