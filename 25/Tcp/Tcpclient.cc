#include "Tcpserver.hpp"
#include "Socket.hpp"
#include "Common.hpp"

void Usage(std::string proc)
{
    std::cerr << "Usage: " << proc << " ip " << "port " << std::endl;
}

// ./client ip port
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        Usage(argv[0]);
        exit(USAGE_ERR);
    }
    std::string server_ip = argv[1];
    uint16_t server_port = std::stoi(argv[2]);

    InetAddr server(server_ip, server_port);

    std::unique_ptr<Socket> client = std::make_unique<TcpSocket>();

    return 0;
}