#include "Tcpserver.hpp"
#include "Socket.hpp"
#include "Common.hpp"

void Usage(std::string proc)
{
    std::cerr << "Usage: " << proc << " port " << std::endl;
}

void echo(std::shared_ptr<Socket> &sock, InetAddr &addr)
{
    std::string mesg;
    sock->Recv(&mesg);
    std::cout << addr.StringAddr() << " : ";
    std::cout << mesg << std::endl;
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

    std::unique_ptr<TcpServer> server = std::make_unique<TcpServer>(server_port, [](std::shared_ptr<Socket> &sock, InetAddr &addr)
                     { echo(sock, addr); });

    server->Start();

    return 0;
}