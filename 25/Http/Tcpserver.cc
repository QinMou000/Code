#include "Tcpserver.hpp"
#include "Socket.hpp"
#include "Common.hpp"
#include <fstream>
// #include "NetCal.hpp"
// #include "daemon.hpp"

void Usage(std::string proc)
{
    std::cerr << "Usage: " << proc << " port " << std::endl;
}

// void echo(std::shared_ptr<Socket> &sock, InetAddr &addr)
// {
//     std::string mesg;
//     sock->Recv(&mesg);
//     std::cout << addr.StringAddr() << " : ";
//     std::cout << mesg << std::endl;
// }

bool GetFile(std::string filename, std::string *html)
{
    std::ifstream in(filename);
    if (!in.is_open())
        return false;
    std::string line;
    while (std::getline(in, line))
    {
        *html += line;
    }
    return true;
}

void sendhtml(std::shared_ptr<Socket> &sock, InetAddr &addr)
{
    std::string html = "HTTP/1.1 200 OK\r\n\r\n";
    auto res = GetFile("./wwwroot/index.html", &html);
    if (res)
        sock->Send(html);
    else
        LOG(LogLevel::FATAL) << "send error";
}

// ./server port
int main(int argc, char *argv[])
{
    // daemon(); // 守护进程化

    if (argc != 2)
    {
        Usage(argv[0]);
        exit(USAGE_ERR);
    }
    uint16_t server_port = std::stoi(argv[1]);

    FileLogStrategy();

    // std::unique_ptr<NetCal> cal = std::make_unique<NetCal>();

    // std::unique_ptr<Protocol> prococol = std::make_unique<Protocol>([&cal](Request &req)->Response{
    //     return cal->Cal(req);
    // });

    std::unique_ptr<TcpServer> server = std::make_unique<TcpServer>(server_port, [](std::shared_ptr<Socket> &sock, InetAddr &addr)
                                                                    { sendhtml(sock, addr); });

    server->Start();

    return 0;
}